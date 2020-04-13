//https://www.acmicpc.net/problem/1037

//어떤 양수 A가 또 하나의 양수 N의 약수이면서 , A는 1이나 N이 아닐때, A는 N의 진짜 양수라고 한다.
//어떤 수의 진짜 양수들이 주어질 때, 어떤 수를 구하는 프로그램을 작성 하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arrlen;
	scanf("%d", &arrlen);

	int* arr = (int*)malloc(sizeof(int) * arrlen);

	for (int i = 0; i < arrlen; i++)
		scanf("%d", &arr[i]);

	int max = 0;
	int min = 0x7FFFFFFF;

	for (int i = 0; i < arrlen; i++)
	{
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}

	printf("%d", max * min);


}