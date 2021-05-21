//https://www.acmicpc.net/problem/2475

//검증수
//KOI 전자에서는 컴퓨터를 만들어서 6자리의 고유번호를 매기는데,
//마지막 6번째에는 검증수가 들어간다. 검증수는 고유번호 처음 5자리에 들어가는 5개의 숫자를
//각각 제곱한 수의 합을 10으로 나눈 나머지이다.
//검증수를 구하는 프로그램을 작성하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int number[5];
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &number[i]);
		sum += number[i] * number[i];
	}
	printf("%d", sum % 10);

}