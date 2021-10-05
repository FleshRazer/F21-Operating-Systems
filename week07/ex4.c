#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *my_realloc(void *ptr, size_t size) {
    if (size == 0) {
        size = 1;
    }
    
    void *dest = malloc(size);
    
    if (ptr != NULL) {
        memcpy(dest, ptr, size);
        free(ptr);
    }
    
    return dest;
}

int main() {
    char *string = malloc(6);
    strcpy(string, "Hello");
    
    printf("%s\n", string);
    
    string = my_realloc(string, 12);
    string[11] = '\0';
    printf("%s\n", string);
    
    string = my_realloc(string, 3);
    string[11] = '\0';
    printf("%s\n", string);
    
    string = my_realloc(string, 0);
    printf("%c\n", string[0]);
    
    char* new_string = realloc(NULL, 6);
    return 0;
}
