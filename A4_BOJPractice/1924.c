//https://www.acmicpc.net/problem/1924

//������ : 2007��

//2007�� 1�� 1�� �������̴�. 2007�� x�� y���� ���� �����ϱ�?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int Calcuday = b % 7;
	int Calcumonth = 0;
	for (int i = 1; i <= a; i++) {
		if (i == 2 || i == 4 || i == 6 || i == 8 || i == 9 || i == 11) {
			Calcumonth += 3;
		}
		if (i == 5 || i == 7 || i == 10 || i == 12) {
			Calcumonth += 2;
		}
	}
	int Calcudate = (Calcuday + Calcumonth) % 7;
	switch (Calcudate) {
	case 1:
		printf("MON"); break;
	case 2:
		printf("TUE"); break;
	case 3:
		printf("WED"); break;
	case 4:
		printf("THU"); break;
	case 5:
		printf("FRI"); break;
	case 6:
		printf("SAT"); break;
	case 0:
		printf("SUN"); break;
	}
}