#ifndef THREAD_DISPATCHER
#define THREAD_DISPATCHER

#define BUF_LEN (2 * (sizeof(struct inotify_event) + NAME_MAX + 1))

void *thread_dispatcher(void *arg);

#endif // !THREAD_DISPATCHER
