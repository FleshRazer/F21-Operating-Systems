#include <stdio.h>
#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0])) 

void bubble_sort(int arr[], int arr_len);
void swap(int *a, int *b);
void print_array(int arr[], int arr_size);

void bubble_sort(int arr[], int arr_len) {
    for (int i = 0; i < arr_len - 1; i++) {
        for (int j = 0; j < arr_len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    puts("Enter initial array, one integer per line");
    puts("Enter 'q' to end input");
    
    int arr[256], n = 0;
    char buffer[256];
    
    while (gets(buffer)) {
    	if (strcmp(buffer, "q") == 0) {
    	    break;
    	}
    	arr[n++] = atoi(buffer);
    }
    
    bubble_sort(arr, n);
    
    puts("Array after bubble sort:");
    print_array(arr, n);
    return 0;
}
