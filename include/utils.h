#ifndef UTILS_H
#define UTILS_H

#include <linux/limits.h>

typedef struct {
    char file_name[NAME_MAX];
    int mask;
} file_t;

extern file_t file_buffer[];
extern int file_buffer_read_index, file_buffer_count, file_buffer_write_index;

#endif
