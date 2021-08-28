#include <stdio.h>
#include <string.h>

int main() {
    fputs("Enter a string: ", stdout);
    
    char line[256];
    fgets(line, 256, stdin);
    
    fputs("Its reverse is: ", stdout);
    for (int i = strlen(line) - 2; i >= 0; i--) {
    	fputc(line[i], stdout);
    }
    fputc('\n', stdout);
    
    return 0;
}
