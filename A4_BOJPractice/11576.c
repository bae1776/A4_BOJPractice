//https://www.acmicpc.net/problem/11576

//진법 변환 (인하대 : Base Conversion)

//A 진수를 B 진수로 변환하여라. (2~30진수)
//첫 줄에 A B가 주어지고
//둘째 줄에는 변환할 A진수 정수의 자릿수가 주어진다.
//셋째 줄에는 A진수 정수의 각 자리의 값이 들어간다.

//변환하고 난 뒤 값도 자릿수마다 띄워서 출력하면 된다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int A, B;
	scanf("%d %d", &A, &B);

	int digit;
	scanf("%d", &digit);

	int mulVar = 1;
	for (int i = 0; i < digit - 1; i++)
		mulVar *= A;

	int AtoTen = 0;

	for (int i = 0; i < digit; i++) 
	{
		int tempInput;
		scanf("%d", &tempInput);

		AtoTen += mulVar * tempInput;
		mulVar /= A;
	}
	
	int stack[100];
	int top = -1;

	while (AtoTen != 0) 
	{
		stack[++top] = AtoTen % B;
		AtoTen /= B;
	}

	while (top >= 0)
	{
		printf("%d ", stack[top--]);
	}

	return 0;
}
