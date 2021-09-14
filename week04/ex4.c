#include <unistd.h>
#include <sys/wait.h>
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
        buffer[strlen(buffer) - 1] = '\0';
        
        char *token = strtok(buffer, " ");        
        
        char pathname[256] = "/bin/";
        strcat(pathname, token);
        
        int argv_cnt = 0;
        char *argv[32];
        while(token) {
            argv[argv_cnt++] = token;
            token = strtok(NULL, " ");
        }
        argv[argv_cnt] = NULL;
        
        int bg = (strcmp(argv[argv_cnt - 1], "&") == 0 ? true : false);
        
        pid_t child_pid = fork();
        if (child_pid == 0) {
            if (bg == true) {
                // remove '&' from argv
                argv[--argv_cnt] = NULL;
                
                // redirect output from console to /dev/null
                int dev_null = open("/dev/null");
                dup2(dev_null, 1);
                dup2(dev_null, 2);
                close(dev_null);
            }
            
            execve(pathname, argv, NULL);
        }
        
        if (bg == false) {
            waitpid(child_pid, NULL, 0);
        }
    }
    return 0;
}
