//https://www.acmicpc.net/problem/11721

//�Էµ� ���ڿ��� 10�ھ� ©�� ����ϴ� ���α׷��̴�.

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
