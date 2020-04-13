//https://www.acmicpc.net/problem/11052

//ī�� �����ϱ�
//N���� ī�带 ����� �ϴµ�, 1~N�� ���� ���� �� �� �ִ�.
//�αԴ� ī�尡 ��θ� ������ ī�尡 �������� �����ϹǷ� ������ �� ��ΰ� ���� ����
//��� N���� ����� �Ѵ�.
//N�� 1~N ������ ������ ������ �־��� ��, N���� ī�带 ��� �ִ��� ���Ͻÿ�.
//��, ī�带 �ʰ��ϰ� �缭 ���� ��ŭ ������ �� ������� �ʴ´�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int cardNum;
	scanf("%d", &cardNum);

	int* DP = (int*)malloc(sizeof(int) * (cardNum + 1));
	DP[0] = 0;

	for (int i = 1; i <= cardNum; i++)
	{
		scanf("%d", &DP[i]);
	}

	for (int i = 1; i <= cardNum; i++)
	{
		int left = 1;
		int right = i - 1;
		while (left <= right) {
			int temp = DP[left] + DP[right];
			if (temp > DP[i]) DP[i] = temp;
			left++;
			right--;
		}
	}

	printf("%d", DP[cardNum]);

	free(DP);
	return 0;

}