#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	printf("[ex-06.c] PPID: %d, PID: %d\n", getppid(), getpid());
}
