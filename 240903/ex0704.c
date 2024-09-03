#include <stdio.h>
#include <unistd.h>

int main() {
	char *arg[] = {"ls", "-l", (char *)0};
	printf("before excuting ls -l\n");
	execv("/bin/ls", arg);
	printf("after edcuting ls -l\n");
}
