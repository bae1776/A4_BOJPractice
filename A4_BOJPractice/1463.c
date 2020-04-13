//https://www.acmicpc.net/problem/1463

//입력받은 정수를 아래 3가지 연산을 이용하여 1로 만들때 최소 연산 횟수를 구하시오.
//(1) 3으로 나눈다. (3으로 나누어 떨어져야함),  (2) 2로 나눈다. (2로 나누어 떨어져야함), (3) 1을 뺀다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int input;
	scanf("%d", &input);

	int* calTimes = (int*)malloc(sizeof(int) * (input+1));
	calTimes[1] = 0;

	for (int i = 2; i <= input; i++)
	{
		int calMin = calTimes[i - 1] + 1;  //default = 1을 뺀다.
		if (i % 2 == 0 && calMin > calTimes[i / 2] + 1) calMin = calTimes[i / 2] + 1;  //2로 나눈다
		if (i % 3 == 0 && calMin > calTimes[i / 3] + 1) calMin = calTimes[i / 3] + 1;  //3으로 나눈다
		calTimes[i] = calMin;
	}

	printf("%d", calTimes[input]);

	free(calTimes);
}