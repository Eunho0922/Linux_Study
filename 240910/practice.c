#include <stdio.h>

int main() {

	char a = 5;
	char b = 6;
	int c = 1;

	printf("%d\n", a & b); // 2진수 AND 연산
	printf("%d\n", a | b); // 2진수 OR 연산

	printf("%d\n", c <<  8); // 왼쪽으로 8칸 이동. 256
}
