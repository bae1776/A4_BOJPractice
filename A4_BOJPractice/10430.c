//https://www.acmicpc.net/problem/10430

//������

/*
�Է�
ù° �ٿ� A, B, C�� ������� �־�����. (2 �� A, B, C �� 10000)

���
ù° �ٿ� (A+B)%C, ��° �ٿ� (A%C + B%C)%C, ��° �ٿ� (A��B)%C, ��° �ٿ� (A%C �� B%C)%C�� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n%d\n%d\n%d", (A + B) % C, (A%C + B % C) % C, (A*B) % C, (A%C * B%C) % C);
}