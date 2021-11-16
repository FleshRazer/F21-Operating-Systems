#include <stdio.h>
#include <stdlib.h>

int **malloc_int_matrix(int n, int m) {
    int **matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(m * sizeof(int));
    }

    return matrix;
}

void fscanf_int_matrix(FILE *file, int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
}

int main(int argc, char *argv[]) {
    int process_cnt = argc > 2 ? atoi(argv[1]) : 5;
    int resource_cnt = argc > 2 ? atoi(argv[2]) : 3;
    
    FILE *file = fopen("input_dl.txt", "r");

    int *e = malloc(resource_cnt * sizeof(int)); 
    int *a = malloc(resource_cnt * sizeof(int));
    for (int i = 0; i < resource_cnt; i++) fscanf(file, "%d", &a[i]);
    for (int i = 0; i < resource_cnt; i++) fscanf(file, "%d", &e[i]);

    int **c = malloc_int_matrix(process_cnt, resource_cnt);
    int **r = malloc_int_matrix(process_cnt, resource_cnt);
    fscanf_int_matrix(file, c, process_cnt, resource_cnt);
    fscanf_int_matrix(file, r, process_cnt, resource_cnt);

    int new_resources_available = 1;
    int *terminated_processes = calloc(process_cnt, sizeof(int));
    while (new_resources_available) {
        new_resources_available = 0;

        for (int i = 0; i < process_cnt; i++) {
            if (terminated_processes[i]) {
                continue;
            }

            int is_executable = 1;
            for (int j = 0; j < resource_cnt; j++) {
                if (a[j] < r[i][j]) {
                    is_executable = 0;
                    break;
                }
            }

            if (is_executable) {
                for (int j = 0; j < resource_cnt; j++) {
                    a[j] += r[i][j];
                }

                terminated_processes[i] = 1;
                new_resources_available = 1;
            }
        }
    }

    int deadlocked_cnt = 0;
    int *deadlocked_inds = malloc(process_cnt * sizeof(int));
    for (int i = 0; i < process_cnt; i++) {
        if (!terminated_processes[i]) {
            deadlocked_inds[deadlocked_cnt++] = i;
        }
    }

    if (deadlocked_cnt) {
        printf("%s ", deadlocked_cnt == 1 ? "Process" : "Processes");
        for (int i = 0; i < deadlocked_cnt; i++) {
            printf("%d ", deadlocked_inds[i]);
        }
        printf("deadlocked.");
    } else {
        printf("No deadlock is detected.");
    }
    return 0;
}
