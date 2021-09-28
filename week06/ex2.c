#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a, b, T) \
    T t = a; \
    a = b; \
    b = t;

struct process {
    int id;
    int at;
    int bt;
};

struct process parse_process(char* buffer) {
    strtok(buffer, ",");
    char *second = strtok(NULL, ",");

    struct process p;
    p.at = atoi(buffer);
    p.bt = atoi(second);
    
    return p;
}

int cmp_process(struct process *a, struct process *b) {
    if (a->at > b->at) return 1;
    if (a->at < b->at) return -1;
    return 0;
}

int main() {
    FILE *fp = fopen("new_input.csv", "r");
    
    int n = 0;
    struct process p_arr[10];
    
    char buffer[256];
    while (fgets(buffer, 256, fp) != NULL) {
        p_arr[n] = parse_process(buffer);
        p_arr[n].id = n;
        n++;
    }
    
    qsort(p_arr, n, sizeof(struct process), cmp_process);
    
    printf("P# AT  BT  CT  TAT WT\n");
    
    int wt = 0;
    int ct = 0;
    int tut = 0;
    double avr_wt = 0;
    double avr_tut = 0;
    for (int i = 0; i < n; i++) {
    	int k = i;
    	for (int j = i; j < n && p_arr[j].at <= ct; j++) {
    	    if (p_arr[k].bt > p_arr[j].bt) {
    	        k = j;
    	    }
    	}
        while (i < k--) {
            swap(p_arr[k - 1], p_arr[k], struct process);
        }
        
        wt = p_arr[i].at < ct ? ct - p_arr[i].at : 0;
        ct = p_arr[i].at + wt + p_arr[i].bt;
        tut = wt + p_arr[i].bt;
        avr_wt += wt;
        avr_tut += tut;
        
        printf(
            "P%d %-3d %-3d %-3d %-3d %-3d\n", 
            p_arr[i].id,
            p_arr[i].at,
            p_arr[i].bt,
            ct,
            tut,
            wt
        );
    }
    
    avr_wt /= n;
    avr_tut /= n;
    
    printf("\n");
    printf("Average turnaround time = %f\n", avr_tut);
    printf("Average waiting time = %f\n", avr_wt);
    
    return 0;
}
