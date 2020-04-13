//https://www.acmicpc.net/problem/9251

//LCS(���� ���� �κ� ����)�� ���̸� ���Ͻÿ�.
//LCS�� �� ������ ���� �κ� �������� ���� �� ������ ���Ѵ�.
//���� ��� ������ ACAYKP�� CAPCAK�� �־����� �� ���� LCS�� ACAK�̴�.



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str1[1001], str2[1001];
	scanf("%s", str1);
	scanf("%s", str2);

	int** table = (int**)malloc(sizeof(int*) * (strlen(str2) + 1));

	for (int i = 0; i <= (int)strlen(str2); i++)
	{
		table[i] = (int*)malloc(sizeof(int) * (strlen(str1) + 1));
		table[i][0] = 0;
	}
	for (int i = 0; i <= (int)strlen(str1); i++)
	{
		table[0][i] = 0;
	}

	for (int i = 1; i <= (int)strlen(str2); i++)
		for (int j = 1; j <= (int)strlen(str1); j++)
			if (str1[j-1] == str2[i-1]) table[i][j] = table[i - 1][j - 1] + 1;
			else table[i][j] = table[i - 1][j] > table[i][j - 1] ? table[i - 1][j] : table[i][j - 1];


	printf("%d", table[strlen(str2)][strlen(str1)]);
}

