//https://www.acmicpc.net/problem/15649

//M N을 입력받아 1~M의 자연수 중에서 N개를 뽑아 나열하는 순열을 사전식으로 나열하시오.

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
			if (arr[j] == i)  //깊이(depth) 앞 배열에서 이미 사용된 숫자는 쓰지 않게한다.
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