//https://www.acmicpc.net/problem/1003

//n을 입력받아 n번째 피보나치 수를 재귀적으로 구할 때, fib(0), fib(1)이 호출되는 횟수를
//먼저 입력받은 테스트 케이스 갯수만큼 각각 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _callCount { 
	int zeroCall;
	int oneCall;
} callCount;

int main(void)
{
	callCount fibCall[41] = { {1, 0}, {0, 1}, };
	int calidx = 1;

	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int num;
		scanf("%d", &num);
		while (num > calidx)	
		{
			calidx++;
			fibCall[calidx].zeroCall = fibCall[calidx - 1].zeroCall + fibCall[calidx - 2].zeroCall;
			fibCall[calidx].oneCall = fibCall[calidx - 1].oneCall + fibCall[calidx - 2].oneCall;
		}
		printf("%d %d\n", fibCall[num].zeroCall, fibCall[num].oneCall);
	}

	return 0;
}