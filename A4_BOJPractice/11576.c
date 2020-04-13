//https://www.acmicpc.net/problem/11576

//���� ��ȯ (���ϴ� : Base Conversion)

//A ������ B ������ ��ȯ�Ͽ���. (2~30����)
//ù �ٿ� A B�� �־�����
//��° �ٿ��� ��ȯ�� A���� ������ �ڸ����� �־�����.
//��° �ٿ��� A���� ������ �� �ڸ��� ���� ����.

//��ȯ�ϰ� �� �� ���� �ڸ������� ����� ����ϸ� �ȴ�.

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
