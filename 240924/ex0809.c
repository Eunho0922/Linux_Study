#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid;

	if((pid = fork()) > 0) {
		sleep(1);
		exit(1);
	} else if (pid == 0) {
		printf("old session id : %d\n", getsid(0));
		printf("old session id : %d\n", setsid());
		sleep(600);
	}

	return 0;
} 
