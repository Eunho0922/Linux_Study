#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    pid_t pid = fork();

	if (pid > 0) {
        exit(0);
    }

    setsid();

    while (1) {
        int fd = open("curtime.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S\n", tm_info);

        write(fd, buffer, sizeof(buffer));
        close(fd);

        sleep(10);
    }

    return 0;
}

