//https://www.acmicpc.net/problem/1152

//단어의 개수 구하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str[1000000] = { 0 };
	scanf("%[^\n]s", str);

	int output = 0;
	char button = 0;

	for (unsigned int i = 0; i <= strlen(str); i++) {
		char ch = str[i];
		if (ch != ' ' && button == 0) {
			button = 1;
			if (output == 0) output++;
		}
		if (ch == ' ' && button == 1) {
			button = 0;
			output++;
		}
	}
	if (str[strlen(str) - 1] == ' ') output--;

	printf("%d", output);
}

//너무 복잡하게 풀었다.