#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int filedes;
	char relativePath[] = "temp0.txt";
	char absolutePath[] = "/Users/eunho/linux2/Linux_Study/240813/temp0.txt";

	if ((filedes = open(absolutePath, O_CREAT | O_EXCL | O_RDWR, 0644)) == -1 ) {
		printf("file open error!\n");
		exit(1);
	}

	close(filedes);
}
