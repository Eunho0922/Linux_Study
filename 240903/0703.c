#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	// execl("/usr/bin/head","head", argv[1], argv[2], argv[3], (char *)0);
	// execlp("head", "head", argv[1], argv[2], argv[3], (char *)0);
	char *args[] = {"head", argv[1], argv[2], argv[3], NULL};
	execv("/usr/bin/head", args);
	execvp("head", args);



}
