//https://www.acmicpc.net/problem/2798

//블랙잭
//카드 갯수와 각 카드의 수, 숫자 상한이 주어지고, 카드들 중에서 3장을 뽑을 때
//3장 숫자 합이 가장 숫자 상한에 가까울 때의 3장 숫자합을 출력하시오.

#include <stdio.h>
#include <stdlib.h>

int blackJack(int arr[], int arrsize, int limit)
{
	int uplimit = 0;
	
	for (int first = 0; first < arrsize; first++)
		for (int second = first + 1; second < arrsize; second++)
			for (int third = second + 1; third < arrsize; third++)
				if (arr[first] + arr[second] + arr[third] <= limit && arr[first] + arr[second] + arr[third] > uplimit)
					uplimit = arr[first] + arr[second] + arr[third];
	return uplimit;
}

int main(void)
{
	int cardnum, limit;
	scanf("%d %d", &cardnum, &limit);
	int* arr = (int*)malloc(sizeof(int) * cardnum);
	for (int i = 0; i < cardnum; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", blackJack(arr, cardnum, limit));

	return 0;
}