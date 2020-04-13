//https://www.acmicpc.net/problem/15649

//M N�� �Է¹޾� 1~M�� �ڿ��� �߿��� N���� �̾� �����ϴ� ������ ���������� �����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printNumArr(int* arr, int arrsize, int intmax, int depth)
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

	for (int i = 1; i <= intmax; i++)
	{
		char isUsed = 0;
		for (int j = 0; j < depth; j++)
		{
			if (arr[j] == i)  //����(depth) �� �迭���� �̹� ���� ���ڴ� ���� �ʰ��Ѵ�.
			{
				isUsed = 1;
				break;
			}
		}
		if (!isUsed) {
			arr[depth] = i;
			printNumArr(arr, arrsize, intmax, depth + 1);
		}
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

	printNumArr(arr, picks, max, 0);

}