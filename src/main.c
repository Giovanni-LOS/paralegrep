#include "../include/thread_dispatcher.h"
#include "../include/thread_worker.h"
#include "../include/thread_ranking.h"
#include "../include/utils.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

void handle_signal(int signal) {
    terminate_program = 1;

    pthread_cond_broadcast(&file_have_data);
    pthread_cond_broadcast(&file_have_space);
    pthread_cond_broadcast(&rank_have_data);
    pthread_cond_broadcast(&rank_have_space);
}

int main(int argc, char *argv[]) {
       
    if (argc != 2) {
        printf("Usage: %s <word to find>\n", argv[0]);
        return 1;
    }
    
    if (strlen(argv[1]) > 255) {
        printf("Error: word too long\n");
        return 1;
    }

    strcpy(word_to_search, argv[1]);

    pthread_t dispatcher_thread;
    pthread_t worker_thread[10];
    pthread_t ranking_thread;

    pthread_mutex_init(&files_lock, NULL);
    pthread_cond_init(&file_have_data, NULL);
    pthread_cond_init(&file_have_space, NULL);
    pthread_mutex_init(&rank_lock, NULL);
    pthread_cond_init(&rank_have_data, NULL);
    pthread_cond_init(&rank_have_space, NULL);

    // signal(SIGINT, handle_signal);

    pthread_create(&dispatcher_thread, NULL, thread_dispatcher, NULL);
    for(int i = 0; i<10; i++) pthread_create(&worker_thread[i], NULL, thread_worker, NULL);
    pthread_create(&ranking_thread, NULL, thread_ranking, NULL);

    pthread_join(dispatcher_thread, NULL);
    for(int i = 0; i<10; i++) pthread_join(worker_thread[i], NULL);
    pthread_join(ranking_thread, NULL);

    pthread_mutex_destroy(&files_lock);
    pthread_cond_destroy(&file_have_data);
    pthread_cond_destroy(&file_have_space);
    pthread_mutex_destroy(&rank_lock);
    pthread_cond_destroy(&rank_have_data);
    pthread_cond_destroy(&rank_have_space);

    return 0;
}
