//https://www.acmicpc.net/problem/15652

//M N을 입력받아 1~M의 자연수 중에서 N개를 뽑아 순열을 나열 할 때
//현재 항이 전 항보다 크거나 같은 조건을 만족시키는 것만 출력하시오.

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