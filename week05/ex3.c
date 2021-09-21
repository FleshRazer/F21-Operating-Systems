#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define true 1
#define false 0
#define BUFFER_CAPACITY 10

int size = 0;
int buffer[BUFFER_CAPACITY];

int producer_sleep = false;
int consumer_sleep = false;

void *producer() {
    printf("start producer\n");
    while (true) {
        while (producer_sleep);
        buffer[size++] = rand() % 100;
        
        printf("%d\n", buffer[size - 1]);
        
        consumer_sleep = false;
        
        if (size == BUFFER_CAPACITY) {
            producer_sleep = true;
        }
    }
}

void *consumer() {
    printf("start consumer\n");
    while (true) {
        while (consumer_sleep);
        size--;
        producer_sleep = false;
        
        if (size == 0) {
            consumer_sleep = true;
        }
    }
}

int main() {
    pthread_t producer_id;
    pthread_create(&producer_id, NULL, producer, NULL);
    
    pthread_t consumer_id;
    pthread_create(&consumer_id, NULL, consumer, NULL);
    
    while (true);
    return 0;
}
