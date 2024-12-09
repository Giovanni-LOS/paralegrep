#include "../include/thread_worker.h"
#include "../include/utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread_worker(void *arg) {
    char *logs_dir = realpath("../logs", NULL);
    if (logs_dir == NULL) {
        perror("errorLogFile: realpath");
        exit(1);
    }

    char error_log_file[PATH_MAX];
    snprintf(error_log_file, PATH_MAX, "%s/error.log", logs_dir);

    FILE *ferror = fopen(error_log_file, "a");
    if (ferror == NULL) {
        perror("fopen error.log");
        free(logs_dir);
        exit(1);
    }

    char worker_log_file[PATH_MAX];
    snprintf(worker_log_file, PATH_MAX, "%s/worker.log", logs_dir);

    FILE *fworker = fopen(worker_log_file, "a");
    if (fworker == NULL) {
        fprintf(ferror, "Error: fopen worker.log\n");
        free(logs_dir);
        fclose(ferror);
        exit(1);
    }

    free(logs_dir);

    while (!terminate_program) {
        file_t file;
        pthread_mutex_lock(&files_lock);
        while (file_buffer_lenght == 0 && !terminate_program) {
            pthread_cond_wait(&file_have_data, &files_lock);
        }
        if (terminate_program) {
            pthread_mutex_unlock(&files_lock);
            break;
        }
        strcpy(file.file_name, file_buffer[file_buffer_read_index].file_name);
        file.mask = file_buffer[file_buffer_read_index].mask;
        file_buffer_read_index = (file_buffer_read_index + 1) % FILE_BUFFER_SIZE;
        file_buffer_lenght--;
        pthread_cond_signal(&file_have_space);
        pthread_mutex_unlock(&files_lock);

        if (file.mask == 1) {
            char command[512];
            snprintf(command, sizeof(command), "grep -o -i '%s' %s%s | wc -l", word_to_search, "../fileset/", file.file_name);
            FILE *fp = popen(command, "r");
            if (fp == NULL) {
                fprintf(fworker, "Error: failed to execute command\n");
                fclose(fp);
                continue;
            }
            int count = 0;
            if (fscanf(fp, "%d", &count) != 1) {
                fprintf(fworker, "Error: failed to read from command\n");
                fclose(fp);
                continue;
            }
            fprintf(fworker, "File %s contains %d occurrences of '%s'\n", file.file_name, count, word_to_search);
            fclose(fp);

            pthread_mutex_lock(&rank_lock);
            while (rank_buffer_lenght == RANK_BUFFER_SIZE && !terminate_program) {
                pthread_cond_wait(&rank_have_space, &rank_lock);
            }
            if (terminate_program) {
                pthread_mutex_unlock(&rank_lock);
                break;
            }
            strcpy(rank_buffer[rank_buffer_write_index].file_name, file.file_name);
            rank_buffer[rank_buffer_write_index].count = count;
            rank_buffer_write_index = (rank_buffer_write_index + 1) % RANK_BUFFER_SIZE;
            rank_buffer_lenght++;
            pthread_cond_signal(&rank_have_data);
            pthread_mutex_unlock(&rank_lock);
        } else if (file.mask == 2) {
            pthread_mutex_lock(&rank_lock);
            while (rank_buffer_lenght == RANK_BUFFER_SIZE && !terminate_program) {
                pthread_cond_wait(&rank_have_space, &rank_lock);
            }
            if (terminate_program) {
                pthread_mutex_unlock(&rank_lock);
                break;
            }
            strcpy(rank_buffer[rank_buffer_write_index].file_name, file.file_name);
            rank_buffer[rank_buffer_write_index].count = -1;
            rank_buffer_write_index = (rank_buffer_write_index + 1) % RANK_BUFFER_SIZE;
            rank_buffer_lenght++;
            fprintf(fworker, "File %s was flagged as removed\n", file.file_name);
            pthread_cond_signal(&rank_have_data);
            pthread_mutex_unlock(&rank_lock);
        }
    }
    fprintf(fworker, "Worker thread finished\n");
    fclose(fworker);
    fclose(ferror);
    return NULL;
}