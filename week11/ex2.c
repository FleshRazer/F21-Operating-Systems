#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(void) {
    DIR *tmp = opendir("/");
    struct dirent *dp;

    while ((dp = readdir(tmp)) != NULL) {
        printf("%s\t", dp->d_name);
    }
    printf("\n\n");
    return 0;
}
