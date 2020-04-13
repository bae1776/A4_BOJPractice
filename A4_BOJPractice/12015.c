//https://www.acmicpc.net/problem/12015

//가장 긴 부분 수열의 길이를 구하시오.
//10 20 10 30 20 50
//에서 가장 긴 부분 수열은
//10 20    30    50 이다.
//수열의 길이는 1000000개 이하다.
//참고 : 동적계획법으로 풀면 O(n^2)이므로 시간 초과가 된다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int lowSame_bound(int* arr, int arrsize, int key)
{
	int left = 0;
	int right = arrsize - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (arr[middle] >= key)
			right = middle - 1;
		else
			left = middle + 1;
	}

	return left;
}



int main(void)
{
	int arrlen;
	scanf("%d", &arrlen);

	int* arr = (int*)malloc(sizeof(int) * arrlen);
	int* newdp = (int*)calloc(arrlen, sizeof(int));

	for (int i = 0; i < arrlen; i++)
		scanf("%d", &arr[i]);
	
	newdp[0] = arr[0];
	int cursor = 1;
	int dpsize = 1;

	while (cursor < arrlen)
	{
		if (newdp[dpsize - 1] < arr[cursor])
		{
			newdp[dpsize++] = arr[cursor++];
		}
		else {
			newdp[lowSame_bound(newdp, dpsize, arr[cursor])] = arr[cursor];
			cursor++;
		}
	}
	printf("%d", dpsize);

	free(arr);
	free(newdp);

	return 0;
}
