#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int filedes;
	off_t newpos;

	filedes = open("data.txt", O_RDONLY, 0644);
	newpos = lseek(filedes, (off_t)0, SEEK_END);

	printf("file size: %lld\n", newpos);

	close(filedes);
}
