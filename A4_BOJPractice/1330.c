//https://www.acmicpc.net/problem/1330

//�� �� ���ϱ�
//A�� B�� �־�����.
//�׸��� ���� �� ���� �� �ϳ��� ����Ѵ�.

//A�� B���� ū ��쿡�� '>'�� ����Ѵ�.
//A�� B���� ���� ��쿡�� '<'�� ����Ѵ�.
//A�� B�� ���� ��쿡�� '=='�� ����Ѵ�.

#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	if (a > b) {
		printf(">");
	}
	else if (a == b) {
		printf("==");
	}
	else {
		printf("<");
	}
}