#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

int main() {
	pid_t pid;
	int status;
	int x, y;
	int result = 0;
	int a = 0;

	scanf("%d %d", &x, &y);

	pid = fork();

	if (pid > 0) {
		printf("parendt: waiting...\n");
		wait(&status);
		printf("parent: status is %d\n", status >> 8);
		result += pow(x, y) + (status >> 8);
		printf("total result: %d\n", result);
		
	} else if (pid == 0) {
		for (int i = x; i <= y; i++) {
			a += i;
		}
		printf("child result: %d!\n", a);
		exit(a);
	} else {
		printf("fail to fork\n");
	}

	printf("bye!\n");
}
