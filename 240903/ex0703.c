#include <stdio.h>
#include <unistd.h>

int main() {
	printf("before excuting ls -l\n");
	execl("/bin/ls", "ls", "-l", (char *)0);
	printf("after edcuting ls -l\n");
}
