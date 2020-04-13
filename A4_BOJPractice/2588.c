//https://www.acmicpc.net/problem/2588

//(세자리수)*(세자리수) 곱셈 풀이

//곱셈을 할 때 손풀이 과정에서 써야하는 세 개의 수와 곱셈의 정답을 각각 출력한다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	int digit[4] = { b % 10, b / 10 % 10, b / 100, b };

	for (int i = 0; i < 4; i++) {
		printf("%d\n", a * digit[i]);
	}
}