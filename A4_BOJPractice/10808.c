//https://www.acmicpc.net/problem/10808

//���ĺ� ���� ����
//���ĺ� �ҹ��ڷ� �̷���� �ܾ �־��� �� �ܾ��� �� ���ĺ� ������ ����ϼ���.

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