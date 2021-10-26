#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(void) {
    DIR *tmp = opendir("./tmp");
    struct dirent *dp;

    while ((dp = readdir(tmp)) != NULL) {
        int hard_link_cnt = 0;
        char *output = malloc(1024);
        DIR *tmp_nested = opendir("./tmp");
        struct dirent *dp_nested;

        strcat(output, dp->d_name);
        strcat(output, " - ");

        while ((dp_nested = readdir(tmp_nested)) != NULL) {
            if (dp_nested->d_ino == dp->d_ino && strcmp(dp_nested->d_name, dp->d_name) != 0) {
                hard_link_cnt++;
                strcat(output, dp_nested->d_name);
                strcat(output, ", ");
            }
        }

        if (hard_link_cnt > 0) {
            output[strlen(output) - 2] = '\0';
            printf("%s\n", output);
        }

        free(output);
    }

    return 0;
}