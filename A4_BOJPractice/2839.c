//https://www.acmicpc.net/problem/2839

//설탕 배달
//3kg, 5kg 포대만 있고 nkg을 보내야할 때 포대 갯수를 최소로 했을 때의 포대 갯수를 구하시오.
//불가능하면 -1 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int input;
	int output = 0;

	scanf("%d", &input);
	int rest = input % 5;

	if (input % 5 == 0) {
		printf("%d", input / 5);
	}
	else if (input >= 3 && rest == 3) {
		printf("%d", (input - 3) / 5 + 1);
	}
	else if (input >= 6 && rest == 1) {
		printf("%d", (input - 6) / 5 + 2);
	}
	else if (input >= 9 && rest == 4) {
		printf("%d", (input - 9) / 5 + 3);
	}
	else if (input >= 12 && rest == 2) {
		printf("%d", (input - 12) / 5 + 4);
	}
	else {
		printf("-1");
	}
}