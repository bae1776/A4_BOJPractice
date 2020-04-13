//https://www.acmicpc.net/problem/11652

//ī��
//long long ������ ��ȣ�� ���� ī�尡 ���� �־��� ��, ���� ���� ���� ī���� ������ ���Ͻÿ�.
//���� ���� ���� ī�尡 ���� ���� ���� ���� ���� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	if (*(long long*)a < *(long long*)b) return -1;
	else if (*(long long*)a == *(long long*)b) return 0;
	else return 1;
}


int main(void)
{
	int cardNum;
	scanf("%d", &cardNum);

	long long* cardList = (long long *)malloc(sizeof(long long) * cardNum);
	for (int i = 0; i < cardNum; i++)
		scanf("%lld", &cardList[i]);

	qsort(cardList, cardNum, sizeof(long long), cmp);

	int maxFreq = 1, nowFreq = 1;
	long long answer = cardList[0];

	for (int i = 1; i < cardNum; i++)
	{
		if (cardList[i - 1] == cardList[i])
		{
			nowFreq++;
			if (nowFreq > maxFreq)
			{
				maxFreq = nowFreq;
				answer = cardList[i];
			}
		}
		else nowFreq = 1;
	}

	printf("%lld", answer);
	free(cardList);
}