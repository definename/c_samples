#include <stdio.h>
#include <unistd.h>
#include "pthread.h"

void *thread_handler(void* data) {
    printf("We are here\n");
    if (data != NULL) {
        unsigned int* seconds_to_sleep = (unsigned int*)data;
        printf("Sleep for:%u seconds required\n", *seconds_to_sleep);
        sleep(*seconds_to_sleep);
    } else {
        printf("No sleep required\n");
    }
    pthread_exit(0);
}


int main(const int argc, const char * argv[]) {
    unsigned int sec = 2;
    pthread_t thread_hdl;
    pthread_create(&thread_hdl, NULL, thread_handler, &sec);
    pthread_join(thread_hdl, NULL);
    return 0;
}