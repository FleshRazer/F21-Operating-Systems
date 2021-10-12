#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#define true 1

int main(int argc, char *argv[]) {
    int mem_val = 10 * 1024 * 1024;
    if (argc > 1) {
        argv[2];
    }

    void* ptr;
    struct rusage usage;
    for (int i = 0; i < 10; i++) {
        ptr = malloc(mem_val);
        memset(ptr, 0, mem_val);
        
        getrusage(RUSAGE_SELF, &usage);
        printf("usage.ru_maxrss: %ld kilobytes\n", usage.ru_maxrss);
        
        sleep(1);
    }
    return 0;
}
