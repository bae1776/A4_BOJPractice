//https://www.acmicpc.net/problem/1330

//두 수 비교하기
//A와 B가 주어진다.
//그리고 다음 세 가지 중 하나를 출력한다.

//A가 B보다 큰 경우에는 '>'를 출력한다.
//A가 B보다 작은 경우에는 '<'를 출력한다.
//A와 B가 같은 경우에는 '=='를 출력한다.

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