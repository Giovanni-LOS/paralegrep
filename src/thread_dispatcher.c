#include "../include/thread_dispatcher.h"
#include "../include/utils.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

void *thread_dispatcher(void *arg) {
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

    char *dir = realpath("../fileset", NULL);
    if (dir == NULL) {
        fprintf(ferror, "Error: realpath ../fileset\n");
        free(logs_dir);
        fclose(ferror);
        exit(1);
    }

    char *log_dir = realpath("../logs", NULL);
    if (log_dir == NULL) {
        fprintf(ferror, "Error: realpath ../logs\n");
        free(logs_dir);
        free(dir);
        fclose(ferror);
        exit(1);
    }

    char dispatcher_log_file[PATH_MAX];
    snprintf(dispatcher_log_file, PATH_MAX, "%s/dispatcher.log", log_dir);

    FILE *flog = fopen(dispatcher_log_file, "a");
    if (flog == NULL) {
        fprintf(ferror, "Error: fopen dispatcher.log\n");
        free(logs_dir);
        free(dir);
        free(log_dir);
        fclose(ferror);
        exit(1);
    }

    free(logs_dir);
    free(log_dir);

    DIR *d = opendir(dir);
    if (d == NULL) {
        fprintf(ferror, "Error: opendir %s\n", dir);
        free(dir);
        fclose(ferror);
        fclose(flog);
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) { // If the entry is a regular file
            pthread_mutex_lock(&files_lock);
            while (file_buffer_lenght == FILE_BUFFER_SIZE) {
                pthread_cond_wait(&file_have_space, &files_lock);
            }
            if (terminate_program) {
                pthread_mutex_unlock(&files_lock);
                break;
            }
            strcpy(file_buffer[file_buffer_write_index].file_name, entry->d_name);
            file_buffer[file_buffer_write_index].mask = 1;
            file_buffer_write_index = (file_buffer_write_index + 1) % FILE_BUFFER_SIZE;
            file_buffer_lenght++;
            pthread_cond_signal(&file_have_data);
            pthread_mutex_unlock(&files_lock);
        }
    }
    closedir(d);

    struct inotify_event *event;
    char event_buf[BUF_LEN];
    int n;
    char *p;

    int notify_fd = inotify_init();
    if (notify_fd < 0) {
        fprintf(ferror, "Error: inotify_init\n");
        exit(1);
    }
    int watch_fd = inotify_add_watch(notify_fd, dir, IN_CREATE | IN_DELETE | IN_MODIFY | IN_MOVED_FROM | IN_MOVED_TO);
    if (watch_fd < 0) {
        fprintf(ferror, "Error: inotify_add_watch\n");
        exit(1);
    }

    while (!terminate_program) {
        sleep(5);
        n = read(notify_fd, event_buf, BUF_LEN);
        if (n < 0) {
            fprintf(ferror, "Error: read\n");
            exit(1);
        }

        for (p = event_buf; p < event_buf + n;) {
            event = (struct inotify_event *)p;
            if (event->mask & IN_CREATE) {
                fprintf(flog, "File %s created\n", event->name);
                pthread_mutex_lock(&files_lock);
                while (file_buffer_lenght == FILE_BUFFER_SIZE) {
                    pthread_cond_wait(&file_have_space, &files_lock);
                }
                if (terminate_program) {
                    pthread_mutex_unlock(&files_lock);
                    break;
                }
                strcpy(file_buffer[file_buffer_write_index].file_name, event->name);
                file_buffer[file_buffer_write_index].mask = 1;
                file_buffer_write_index = (file_buffer_write_index + 1) % FILE_BUFFER_SIZE;
                file_buffer_lenght++;
                pthread_cond_signal(&file_have_data);
                pthread_mutex_unlock(&files_lock);
            }
            if (event->mask & IN_DELETE || event->mask & IN_MOVED_FROM) {
                fprintf(flog, "File %s deleted or moved from\n", event->name);
                pthread_mutex_lock(&files_lock);
                while (file_buffer_lenght == FILE_BUFFER_SIZE) {
                    pthread_cond_wait(&file_have_space, &files_lock);
                }
                if (terminate_program) {
                    pthread_mutex_unlock(&files_lock);
                    break;
                }
                strcpy(file_buffer[file_buffer_write_index].file_name, event->name);
                file_buffer[file_buffer_write_index].mask = 2;
                file_buffer_write_index = (file_buffer_write_index + 1) % FILE_BUFFER_SIZE;
                file_buffer_lenght++;
                pthread_cond_signal(&file_have_data);
                pthread_mutex_unlock(&files_lock);
            }
            if (event->mask & IN_MOVED_TO) {
                fprintf(flog, "File %s moved to\n", event->name);
                pthread_mutex_lock(&files_lock);
                while (file_buffer_lenght == FILE_BUFFER_SIZE) {
                    pthread_cond_wait(&file_have_space, &files_lock);
                }
                if (terminate_program) {
                    pthread_mutex_unlock(&files_lock);
                    break;
                }
                strcpy(file_buffer[file_buffer_write_index].file_name, event->name);
                file_buffer[file_buffer_write_index].mask = 1;
                file_buffer_write_index = (file_buffer_write_index + 1) % FILE_BUFFER_SIZE;
                file_buffer_lenght++;
                pthread_cond_signal(&file_have_data);
                pthread_mutex_unlock(&files_lock);
            }
            if (event->mask & IN_MODIFY) {
                fprintf(flog, "File %s modified\n", event->name);
                pthread_mutex_lock(&files_lock);
                while (file_buffer_lenght == FILE_BUFFER_SIZE) {
                    pthread_cond_wait(&file_have_space, &files_lock);
                }
                if (terminate_program) {
                    pthread_mutex_unlock(&files_lock);
                    break;
                }
                strcpy(file_buffer[file_buffer_write_index].file_name, event->name);
                file_buffer[file_buffer_write_index].mask = 1;
                file_buffer_write_index = (file_buffer_write_index + 1) % FILE_BUFFER_SIZE;
                file_buffer_lenght++;
                pthread_cond_signal(&file_have_data);
                pthread_mutex_unlock(&files_lock);
            }
            fflush(flog);
            p += sizeof(struct inotify_event) + event->len;
        }
    }
    fprintf(flog, "Dispatcher thread terminated\n");
    inotify_rm_watch(notify_fd, watch_fd);
    close(notify_fd);
    fclose(flog);
    fclose(ferror);
    free(dir);
    return NULL;
}