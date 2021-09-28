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
    int bt; // burst time
    int r_bt; // remaining burst time
    int wt;
};

struct process parse_process(char* buffer) {
    strtok(buffer, ",");
    char *second = strtok(NULL, ",");

    struct process p;
    p.at = atoi(buffer);
    p.bt = atoi(second);
    p.r_bt = p.bt;
    p.wt = 0;
    
    return p;
}

int cmp_process(struct process *a, struct process *b) {
    if (a->at > b->at) return 1;
    if (a->at < b->at) return -1;
    return 0;
}

int main(int argc, char *argv[]) {
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
    
    int n_wt = n; // number of waiting processes
    int time = p_arr[0].at; // current time
    int quantum = atoi(argv[1]);
    
    while (n_wt > 0) {
        time = time < p_arr[0].at ? p_arr[0].at : time;
    
    	for (int i = 0; i < n_wt && p_arr[i].at <= time;) {
        	// 1. execute process in a given time slot and update time value
        	int exec_time = quantum < p_arr[i].r_bt ? quantum : p_arr[i].r_bt;
        	
        	time += exec_time;
        	p_arr[i].r_bt -= exec_time;
        	
        	// 2. update wt of precesses which are not completed yet
        	for (int j = 0; j < n_wt && p_arr[j].at <= time; j++) {
        	    if (j == i) {
        	        continue;
        	    }
        	    
        	    // if process j started during the execution of process i,
        	    // its waiting time will not be equal to exec_time
        	    p_arr[i].wt += exec_time < time - p_arr[j].at ? exec_time : time - p_arr[j].at;
        	}
        	
        	// 3. mark process as a completed one if needed
        	if (p_arr[i].r_bt == 0) {
        	    for (int j = i + 1; j < n_wt; j++) {
        	        swap(p_arr[j - 1], p_arr[j], struct process);
        	    }
        	    n_wt--;
        	    
        	    continue;
        	}
        	
        	i++;
        }
    }
    
    int ct = 0;
    int tut = 0;
    double avr_wt = 0;
    double avr_tut = 0;
    
    for (int i = 0; i < n; i++) {
        ct = p_arr[i].at + p_arr[i].wt + p_arr[i].bt;
        tut = p_arr[i].wt + p_arr[i].bt;
        avr_wt += p_arr[i].wt;
        avr_tut += tut;
        
        printf(
            "P%d %-3d %-3d %-3d %-3d %-3d\n", 
            p_arr[i].id,
            p_arr[i].at,
            p_arr[i].bt,
            ct,
            tut,
            p_arr[i].wt
        );
        
    }
    
    avr_wt /= n;
    avr_tut /= n;
    
    printf("\n");
    printf("Average turnaround time = %f\n", avr_tut);
    printf("Average waiting time = %f\n", avr_wt);
    
    return 0;
}
