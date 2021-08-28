#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    char buffer[256];
    
    fputs("Enter first number: ", stdout);
    fgets(buffer, 256, stdin);
    int first = atoi(buffer);
    
    fputs("Enter second number: ", stdout);
    fgets(buffer, 256, stdin);
    int second = atoi(buffer);
    
    swap(&first, &second);
    printf("First number after swapping: %d\n", first);
    printf("Second number after swapping: %d\n", second);
    
    return 0;
}
