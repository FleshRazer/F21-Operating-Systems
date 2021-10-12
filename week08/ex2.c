#include <stdlib.h>
#include <string.h>
#define true 1

int main(int argc, char *argv[]) {
    int mem_val = 10 * 1024 * 1024;
    if (argc > 1) {
        argv[2];
    }

    for (int i = 0; i < 10; i++) {
        void* ptr = malloc(mem_val);
        memset(ptr, 0, mem_val);
        sleep(1);
    }
    return 0;
}
