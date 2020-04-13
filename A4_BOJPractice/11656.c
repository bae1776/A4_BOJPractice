//https://www.acmicpc.net/problem/11656

//접미사 배열
//(알파벳 소문자 단어)beakjoon을 입력받을 때
//beakjoon, eakjoon, akjoon, kjoon, joon, oon, on, n 을 만들고
//이를 사전순으로 정렬하는 프로그램을 작성하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexiCompare(const void* a, const void* b)
{
	//return strcmp(*(char**)a, *(char**)b); 을 풀어쓰기
	if (*(*(char**)a) - *(*(char**)b) > 0) return 1;
	else if (*(*(char**)a) - *(*(char**)b) < 0) return -1;
	else {
		char* ra = *(char**)a + 1;
		char* rb = *(char**)b + 1;
		if (*ra == '\0') return 0;
		else return hexiCompare(&ra, &rb);
	}
}

int main(void)
{
	char str[1002];
	scanf("%s", str);

	int length = strlen(str);
	char** strList = (char**)malloc(sizeof(char*) * length);
	for (int i = 0; i < length; i++)
	{
		strList[i] = (char*)malloc(sizeof(char) * (i + 2));
		strncpy(strList[i], str + length - i - 1, i + 2);
	}

	qsort(strList, length, sizeof(char*), hexiCompare);

	for (int i = 0; i < length; i++)
	{
		printf("%s\n", strList[i]);
		free(strList[i]);
	}

	free(strList);
}