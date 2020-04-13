//https://www.acmicpc.net/problem/10820

//문자열 분석
//문자열 최대 100줄이 주어질 때, 각 줄의 소문자, 대문자, 숫자, 공백의 개수를
//공백으로 구분하여 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[103];

	while (1) {
		int small = 0, big = 0, num = 0, space = 0;
		if (fgets(str, 102, stdin) == NULL) break;

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				small++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				big++;
			else if (str[i] >= '0' && str[i] <= '9')
				num++;
			else if (str[i] == ' ')
				space++;
		}
		printf("%d %d %d %d\n", small, big, num, space);
	}
}