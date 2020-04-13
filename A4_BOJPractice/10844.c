//https://www.acmicpc.net/problem/10844

//12321 ���� ������ �ڸ��� ���ڰ� ��� 1 ���� ���� ���� ��ܼ���� �Ѵ�.
//N�� �־��� �� N�ڸ��� ��ܼ��� ���� % 1000000000 �� ���Ͻÿ�.
//(��, 0���� �����ϴ� ��ܼ��� ����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int digit;
	scanf("%d", &digit);

	long long int(*stairNumCount)[10] = (long long int(*)[10])malloc((digit + 1) * sizeof(long long int[10]));


	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			stairNumCount[i][j] = i;
		}
	}

	for (int i = 2; i <= digit; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) stairNumCount[i][j] = stairNumCount[i - 1][1];
			else if (j == 9) stairNumCount[i][j] = stairNumCount[i - 1][8];
			else stairNumCount[i][j] = (stairNumCount[i - 1][j - 1] + stairNumCount[i - 1][j + 1]) % 1000000000;
		}
	}


	long long int result = 0;
	for (int i = 1; i < 10; i++)
		result += stairNumCount[digit][i];

	printf("%lld", result % 1000000000);

	free(stairNumCount);

}