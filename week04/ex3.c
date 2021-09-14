#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define true 1
#define false 0

int main() {
    char buffer[256];
    
    while (true) {
        fputs("> ", stdout);
        fgets(buffer, 256, stdin);
        
        system(buffer);
    }
    return 0;
}
