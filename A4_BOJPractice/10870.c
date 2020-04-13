//https://www.acmicpc.net/problem/10870

//재귀를 사용하여 피보나치 수를 구현하자.

#include <stdio.h>

int fibbonachi(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return fibbonachi(num - 2) + fibbonachi(num - 1);
}
int main(void)
{
	int input;
	scanf("%d", &input);
	printf("%d", fibbonachi(input));
	return 0;
}