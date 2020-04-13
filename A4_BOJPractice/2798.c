//https://www.acmicpc.net/problem/2798

//����
//ī�� ������ �� ī���� ��, ���� ������ �־�����, ī��� �߿��� 3���� ���� ��
//3�� ���� ���� ���� ���� ���ѿ� ����� ���� 3�� �������� ����Ͻÿ�.

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