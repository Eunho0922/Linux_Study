#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*filedes = creat(pathname, 0644) 가능하지만 사용하지 않는다*/

int main() {
	int filedes;
	char pathname[] = "temp.txt";

	if ((filedes = open(pathname, O_CREAT | O_EXCL | O_RDWR, 0644)) == -1 ) {
		printf("file open error!\n");
		exit(1);
	}

	close(filedes);
}
