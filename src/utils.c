#include "../include/utils.h"

file_t file_buffer[FILE_BUFFER_SIZE];
rank_t rank_buffer[RANK_BUFFER_SIZE];
int file_buffer_read_index = 0, file_buffer_lenght = 0, file_buffer_write_index = 0;
int rank_buffer_read_index = 0, rank_buffer_lenght = 0, rank_buffer_write_index = 0;
char word_to_search[256];
pthread_mutex_t files_lock;
pthread_cond_t file_have_data = PTHREAD_COND_INITIALIZER;
pthread_cond_t file_have_space = PTHREAD_COND_INITIALIZER;
pthread_mutex_t rank_lock;
pthread_cond_t rank_have_data = PTHREAD_COND_INITIALIZER;
pthread_cond_t rank_have_space = PTHREAD_COND_INITIALIZER;
volatile int terminate_program = 0;