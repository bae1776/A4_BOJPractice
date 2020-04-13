//https://www.acmicpc.net/problem/15652

//M N�� �Է¹޾� 1~M�� �ڿ��� �߿��� N���� �̾� ������ ���� �� ��
//���� ���� �� �׺��� ũ�ų� ���� ������ ������Ű�� �͸� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printNumArr(int* arr, int arrsize, int intmax, int depth, int start_pos)
{
	if (depth == arrsize)
	{
		for (int i = 0; i < arrsize; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = start_pos; i <= intmax; i++)
	{
		arr[depth] = i;
		printNumArr(arr, arrsize, intmax, depth + 1, i);
	}
}

int main(void)
{
	int max, picks;
	scanf("%d %d", &max, &picks);

	int* arr = (int*)malloc(sizeof(int) * picks);
	for (int i = 0; i < picks; i++)
	{
		arr[i] = i + 1;
	}

	printNumArr(arr, picks, max, 0, 1);

}