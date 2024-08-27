#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main () {
    pid_t pid;
    int num;
    
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &num);

    pid = fork();
    
    if (pid == 0) {
        long long product = 1;
        for (int i = 1; i <= num; i++) {
            product *= i;
        }
        printf("child process : 1부터 %d까지의 곱 = %lld\n", num, product);
    } else if (pid > 0) {
        int sum = 0;
        for (int i = 1; i <= num; i++) {
            sum += i;
        }
        printf("parent process: 1부터 %d까지의 합 = %d\n", num, sum);
    } else {
		printf("fail to fork\n");
	}

    return 0;
}

