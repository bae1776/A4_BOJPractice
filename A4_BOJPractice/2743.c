//https://www.acmicpc.net/problem/2743

//단어 길이 재기
//주어진 단어의 길이를 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[103];
	scanf("%s", str);
	int output = -1;
	while (str[++output] != '\0');
	printf("%d", output);
	return 0;
}