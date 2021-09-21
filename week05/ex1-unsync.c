#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <sys/stat.h>
#include <sys/fcntl.h>

FILE *fp;

void *print_thread_id(void* num) {
    fprintf(fp, "Thread %d has started its execution\n", *((int*) num));
    fprintf(fp, "Thread %d has ended its execution\n", *((int*) num));
        
    free(num);   
}

int main() {
    fp = fopen("ex1-unsync-output.txt", "w");

    pthread_t thread_ids[5];

    for (int i = 0; i < 5; i++) {
        int* num = malloc(sizeof(int));
        *num = i;
        
        fprintf(fp, "Thread %d is created\n", i);
        pthread_create(thread_ids + i, NULL, print_thread_id, (void*) num);
    }
    return 0;
}
