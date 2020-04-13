//https://www.acmicpc.net/problem/11054

//가장 긴 부분 바이토닉 수열을 구하시오.
//바이토닉 수열이란  A(0) < ... < A(k-1) < A(k) > A(k+1) > ... > A(n) 을 만족하는 수열이다. (k는 0~n까지)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int arrlen;
	scanf("%d", &arrlen);

	int* arr = (int*)malloc(sizeof(int) * arrlen);
	int* Ldp = (int*)calloc(arrlen, sizeof(int));
	int* Rdp = (int*)calloc(arrlen, sizeof(int));

	for (int i = 0; i < arrlen; i++)
		scanf("%d", &arr[i]);
	Ldp[0] = 1;
	Rdp[arrlen - 1] = 1;

	for (int i = 1; i < arrlen; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (Ldp[j] > max && arr[j] < arr[i]) max = Ldp[j];
		}
		Ldp[i] = max + 1;
	}

	for (int i = arrlen - 2; i >= 0; i--)
	{
		int max = 0;
		for (int j = arrlen - 1; j > i; j--)
			if (Rdp[j] > max && arr[j] < arr[i]) max = Rdp[j];
		Rdp[i] = max + 1;
	}

	int dpmax = 0;
	for (int i = 0; i < arrlen; i++)
	{
		if ((Ldp[i] + Rdp[i] - 1) > dpmax) dpmax = Ldp[i] + Rdp[i] - 1;
	}

	printf("%d", dpmax);

	free(arr);
	free(Ldp);
	free(Rdp);
}