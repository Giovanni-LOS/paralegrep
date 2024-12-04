#include "../include/thread_dispatcher.h"
#include "../include/utils.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void *thread_dispatcher(void *arg) {

    const char *dir = realpath("../fileset/", NULL);
    if (dir == NULL) {
        perror("realpath");
        exit(1);
    }
    const char *log_file = realpath("../logs/log.out", NULL);
    if (log_file == NULL) {
        perror("realpath");
        exit(1);
    }

    FILE *flog = fopen(log_file, "a");
    if (flog == NULL) {
        perror("fopen");
        exit(1);
    }
    struct inotify_event *event;
    char event_buf[BUF_LEN];
    int n;
    char* p;

    int notify_fd = inotify_init();
    if (notify_fd < 0) {
        perror("inotify_init");
        exit(1);
    }
    int watch_fd = inotify_add_watch(notify_fd, dir, IN_CREATE | IN_DELETE | IN_MODIFY);
    if (watch_fd < 0) {
        perror("inotify_add_watch");
        exit(1);
    }
    printf("Watching %s\n", dir);

    while(1) {
        n = read(notify_fd, event_buf, BUF_LEN);
        if (n < 0) {
            perror("read");
            exit(1);
        }
        for (p = event_buf; p < event_buf + n; ) {
            event = (struct inotify_event *) p;
            if (event->mask & IN_CREATE) {
                fprintf(flog, "File %s created\n", event->name);
                strcpy(file_buffer[file_buffer_write_index].file_name, event->name);
                file_buffer[file_buffer_write_index].mask = 1;
                file_buffer_write_index = (file_buffer_write_index + 1) % 50;
                file_buffer_count++;
            }
            if (event->mask & IN_DELETE) {
                fprintf(flog, "File %s deleted\n", event->name);
                strcpy(file_buffer[file_buffer_write_index].file_name, event->name);
                file_buffer[file_buffer_write_index].mask = 2;
                file_buffer_write_index = (file_buffer_write_index + 1) % 50;
                file_buffer_count++;
            }
            if (event->mask & IN_MODIFY) {
                fprintf(flog, "File %s modified\n", event->name);
                strcpy(file_buffer[file_buffer_write_index].file_name, event->name);
                file_buffer[file_buffer_write_index].mask = 1;
                file_buffer_write_index = (file_buffer_write_index + 1) % 50;
                file_buffer_count++;
            }
            for(int i = 0; i < file_buffer_count; i++) {
                printf("File: %s, Mask: %d\n", file_buffer[i].file_name, file_buffer[i].mask);
            }
            fflush(flog);
            p += sizeof(struct inotify_event) + event->len;
        }
    }
        
    fclose(flog);
    close(notify_fd);
    free((void *)dir);

    return NULL;
}
