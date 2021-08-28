#include <stdio.h>

int main(int argc, char *argv[]) {
    int height = atoi(argv[1]);
    int width = (height<<1) - 1;
    
    for (int i = 0; i < height; i++) {
    	for (int j = 0; j < height - i; j++) {
    	    fputc(' ', stdout);
    	}
    	for (int j = 0; j < (i<<1) + 1; j++) {
    	    fputc('*', stdout);
    	}
    	fputc('\n', stdout);
    }
    
    return 0;
}
