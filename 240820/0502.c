#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    DIR *dirp;
    struct dirent *dentry;

    int file_count = 0, dir_count = 0;
    char path[1024];

    if((dirp = opendir(argv[1])) == NULL)
        exit(1);

    while((dentry = readdir(dirp)) ) {


        strcpy(path, argv[1]);
        strcat(path, "/");
        strcat(path, dentry->d_name);

        DIR *subdir = opendir(path);
        if (subdir != NULL) {
            dir_count++;
            closedir(subdir);
        } else {
            file_count++;
        }
    }

    printf("FILE : %d\n", file_count);
    printf("DIRECTORY : %d\n", dir_count);

    closedir(dirp);
    return 0;
}

