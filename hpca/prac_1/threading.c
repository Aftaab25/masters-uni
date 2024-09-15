//
// Created by batman on 8/29/24.
//

#include <pthread.h>
#include <stdio.h>

void *first_thread_fn(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf("First thread #%d\n", i);
    }
    return NULL;
}

void *sec_thread_fn(void *arg) {
    for (int i = 10; i < 20; i++) {
        printf("Second thread #%d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t first_thread, second_thread;

    pthread_create(&first_thread, NULL, first_thread_fn, NULL);
    pthread_create(&second_thread, NULL, sec_thread_fn, NULL);

    pthread_join(first_thread, NULL);
    pthread_join(second_thread, NULL);

    return 0;
}