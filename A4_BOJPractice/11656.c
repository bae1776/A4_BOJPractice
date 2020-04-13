//https://www.acmicpc.net/problem/11656

//���̻� �迭
//(���ĺ� �ҹ��� �ܾ�)beakjoon�� �Է¹��� ��
//beakjoon, eakjoon, akjoon, kjoon, joon, oon, on, n �� �����
//�̸� ���������� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexiCompare(const void* a, const void* b)
{
	//return strcmp(*(char**)a, *(char**)b); �� Ǯ���
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