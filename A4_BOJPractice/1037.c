//https://www.acmicpc.net/problem/1037

//� ��� A�� �� �ϳ��� ��� N�� ����̸鼭 , A�� 1�̳� N�� �ƴҶ�, A�� N�� ��¥ ������ �Ѵ�.
//� ���� ��¥ ������� �־��� ��, � ���� ���ϴ� ���α׷��� �ۼ� �Ͻÿ�.

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