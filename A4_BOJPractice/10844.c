//https://www.acmicpc.net/problem/10844

//12321 같이 인접한 자리의 숫자가 모두 1 차이 나는 수를 계단수라고 한다.
//N이 주어질 때 N자리수 계단수의 갯수 % 1000000000 를 구하시오.
//(단, 0으로 시작하는 계단수는 없다)

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