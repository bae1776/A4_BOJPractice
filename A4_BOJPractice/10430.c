//https://www.acmicpc.net/problem/10430

//나머지

/*
입력
첫째 줄에 A, B, C가 순서대로 주어진다. (2 ≤ A, B, C ≤ 10000)

출력
첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C, 셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n%d\n%d\n%d", (A + B) % C, (A%C + B % C) % C, (A*B) % C, (A%C * B%C) % C);
}