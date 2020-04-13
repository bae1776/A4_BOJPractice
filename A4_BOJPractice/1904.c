//https://www.acmicpc.net/problem/1904

//������ ���̰� �־��� ��, 00 Ÿ�ϰ� 1 Ÿ�Ϸ� ���� �� �ִ� ���� �ٸ� ������ ���� % 15746�� ���Ͻÿ�.
//Ÿ���� ����� ���� ������ ��������.
//���� ��� ���� ���̰� 4��, 0011, 0000, 1001, 1100, 1111 �� 5���� ���� �� �ִ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const int REST = 15746;

int main(void)
{
	int input;
	scanf("%d", &input);

	int* ways = (int*)malloc(sizeof(int) * (input + 1));
	ways[1] = 1; ways[2] = 2;

	int unknownidx = 3;
	while (unknownidx <= input)
	{
		ways[unknownidx++] = (ways[unknownidx - 1] + ways[unknownidx - 2]) % REST;
	}

	printf("%d", ways[input]);
	free(ways);
}