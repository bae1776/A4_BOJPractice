//https://www.acmicpc.net/problem/10809

//알파벳 소문자가 처음 등장하는 위치를 출력하시오. (단 첫 자리를 0으로 하고 점점 증가) 없으면 -1 출력.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char alphabet_digit[26] = { 0, };

	char input[101];
	scanf("%s", input);

	for (int i = 0; input[i] != 0; i++) {
		int index = input[i] - 'a';
		if (alphabet_digit[index] == 0) alphabet_digit[index] = i + 1;
	}

	for (int i = 0; i < 26; i++) {
		alphabet_digit[i]--;
		printf("%d ", alphabet_digit[i]);
	}
	return 0;
}