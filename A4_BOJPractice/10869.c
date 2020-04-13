//https://www.acmicpc.net/problem/10869

//사칙 연산
//두 자연수 A,B를 입력받아
//첫째 줄에 A+B, 둘째 줄에 A-B, 셋째 줄에 A*B, 
//넷째 줄에 A/B, 다섯째 줄에 A%B를 출력하시오.

#include <stdio.h>

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%d\n%d\n%d\n%d\n%d\n", A + B, A - B, A*B, A / B, A%B);
	return 0;
}