//https://www.acmicpc.net/problem/1912

//n���� ������ �̷���� ������ ������ �־�����.
//�츮�� �� �� ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�.
//��, ���� �� �� �̻� �����ؾ� �Ѵ�.
//���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 �̶�� ������ �־����ٰ� ����. ���⼭ ������ 12 + 21�� 33�� ������ �ȴ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int arrlen;
	scanf("%d", &arrlen);

	int* arr = (int*)malloc(sizeof(int) * arrlen);
	for (int i = 0; i < arrlen; i++)
		scanf("%d", &arr[i]);

	int* dp = (int*)malloc(sizeof(int) * arrlen);
	dp[0] = arr[0];

	int max = dp[0];

	for (int i = 1; i < arrlen; i++)
	{
		if (dp[i - 1] > 0)
			dp[i] = arr[i] + dp[i - 1];
		else
			dp[i] = arr[i];
		if (dp[i] > max) max = dp[i];
	}
	
	printf("%d", max);

	return 0;
}
