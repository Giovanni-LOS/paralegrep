#ifndef THREAD_RANKING
#define THREAD_RANKING
#include <pthread.h>
#include <linux/limits.h>

typedef struct Node {
    char filename[NAME_MAX];
    int count;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void *thread_ranking(void *arg);

#endif /* ifndef THREAD_RANKING */
