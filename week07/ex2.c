#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[256];
    printf("Enter the size of an array: ");
    
    int n = atoi(fgets(buffer, 256, stdin));
    int *arr = calloc(n, sizeof(int));
    
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + 1;
    }
    
    printf("The array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);        
    }
    printf("\n");
    
    free(arr);
    return 0;
}
