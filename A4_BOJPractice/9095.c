//https://www.acmicpc.net/problem/9095

//���� 1 ~ 10�� 1, 2, 3�� �� �÷� ��Ÿ�� �� �ִ� ������ ���Ͻÿ�.

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