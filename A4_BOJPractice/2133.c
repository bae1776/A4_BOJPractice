//https://www.acmicpc.net/problem/2133

//Ÿ�� ä���
//3��N ũ���� ���� 2��1, 1��2 ũ���� Ÿ�Ϸ� ä��� ����� ���� ���غ���.
//N�� 1 ~ 30

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int DP[31] = { 0, 0, 3 };


int main(void)
{
	int width;
	scanf("%d", &width);

	for (int i = 4; i <= width; i += 2) 
	{
		int temp = DP[i - 2] * 3;

		int j = 4;
		while (i > j)
		{ 
			temp += DP[i - j] * 2;
			j += 2;
		}

		DP[i] = temp + 2; 
		//��� �¹����� ��ġ�ϴ� ����� ���� 2��.
		
	}

	printf("%d", DP[width]);

	return 0;
}
