//https://www.acmicpc.net/problem/11721

//입력된 문자열을 10자씩 짤라 출력하는 프로그램이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char input[101];
	scanf("%s", &input);
	int charline = strlen(input) / 10 + 1;
	for (int i = 1; i <= charline; i++) {
		for (int j = 0; j <= 9; j++) {
			if (input[(i-1) * 10 + j] == '\0') break;
			printf("%c", input[(i-1) * 10 + j]);
		}
		puts("");
	}
}
