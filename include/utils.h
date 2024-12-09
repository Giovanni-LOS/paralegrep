#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>
#include <linux/limits.h>
#define FILE_BUFFER_SIZE 50
#define RANK_BUFFER_SIZE 10

typedef struct {
    char file_name[NAME_MAX];
    int mask;
} file_t;

typedef struct {
    char file_name[NAME_MAX];
    int count;
} rank_t;

extern file_t file_buffer[];
extern rank_t rank_buffer[];
extern int rank_buffer_read_index, rank_buffer_lenght, rank_buffer_write_index;
extern int file_buffer_read_index, file_buffer_lenght, file_buffer_write_index;
extern char word_to_search[256];
extern pthread_mutex_t files_lock;
extern pthread_cond_t file_have_data, file_have_space;
extern pthread_mutex_t rank_lock;
extern pthread_cond_t rank_have_data, rank_have_space;
extern volatile int terminate_program;

#endif
