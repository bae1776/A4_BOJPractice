//https://www.acmicpc.net/problem/1065

//재귀를 사용하여 팩토리얼을 구현하자

#include <stdio.h>

int factorial(int num)
{
	if (num <= 1) return 1;
	else return num * factorial(num - 1);
}

int main(void)
{
	int num;
	scanf("%d", &num);
	printf("%d", factorial(num));
}