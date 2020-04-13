//https://www.acmicpc.net/problem/10817

//세 수를 입력받고 그 중 두번째로 큰 수를 출력하는 프로그램이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int Mid = (a > b) ? ((a > c) ? ((b > c) ? b : c) : a) : ((b > c) ? ((a > c) ? a : c) : b);
	//논리적 계산이다. 이해는 알아서 해라
	printf("%d", Mid);
}