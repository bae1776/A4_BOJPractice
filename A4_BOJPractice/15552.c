//https://www.acmicpc.net/problem/15552

//덧셈식이 몇개인지 입력 받고 각 덧셈식을 입력해서 각 합을 출력하는 프로그램이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int input, a, b;
	scanf("%d ", &input);
	for (int i = 1; i <= input; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
}
