#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int filedes;
    ssize_t nread;
    char buffer[1024];
    int alphabet_count = 0;

    if ((filedes = open("alpha.txt", O_RDONLY)) == -1) {
        printf("file open error!\n");
        exit(1);
    }

    while ((nread = read(filedes, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < nread; i++) {
            if (isalpha(buffer[i])) {
                alphabet_count++;
            }
        }
    }

    if (nread == -1) {
        printf("file read error!\n");
        exit(1);
    }

    close(filedes);

    printf("%d\n", alphabet_count);

    return 0;
}

