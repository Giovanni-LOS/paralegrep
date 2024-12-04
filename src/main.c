#include "../include/thread_dispatcher.h"
#include <linux/limits.h>
#include <pthread.h>


int main(int argc, char *argv[]) {
       
    pthread_t dispatcher_thread;

    pthread_create(&dispatcher_thread, NULL, thread_dispatcher, NULL);

    pthread_join(dispatcher_thread, NULL);

    return 0;
}
