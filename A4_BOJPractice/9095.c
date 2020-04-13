//https://www.acmicpc.net/problem/9095

//정수 1 ~ 10을 1, 2, 3의 합 꼴로 나타낼 수 있는 갯수를 구하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int DP[11] = { 0 };

int func(int input)
{
	if (DP[input] != 0) return DP[input];
	else {
		int total = 0;
		switch (input) {
		default:
			total += func(input - 3);
		case 2:
			total += func(input - 2);
			total += func(input - 1);
			DP[input] = total;
			return total;
		case 1: case 0:
			return 1;
		}
	}
}



int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int input;
		scanf("%d", &input);
		printf("%d\n", func(input));
	}
	return 0;
}