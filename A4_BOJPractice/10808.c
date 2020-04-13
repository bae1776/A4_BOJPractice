//https://www.acmicpc.net/problem/10808

//알파벳 개수 세기
//알파벳 소문자로 이루어진 단어가 주어질 때 단어의 각 알파벳 개수를 출력하세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int alphabetArr[26] = { 0, };
	char ch;

	while (scanf("%c", &ch) && ch != '\n')
		alphabetArr[ch - 'a']++;

	for (int i = 0; i < 26; i++)
		printf("%d ", alphabetArr[i]);

	return 0;
}