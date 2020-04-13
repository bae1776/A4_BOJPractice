//https://www.acmicpc.net/problem/2164

//1~n ��ȣ�� ���� ī�尡 ���� ������ �׿��ִ�. 1�� ī�尡 �� ���� �´�.
//���� ���� �ִ� ī�带 ������, �� ���� ���� ���� �ִ� ī�带 �� �ڷ� �ű��.
//�̸� ��� �ݺ��� ��, �������� �� �� ������ ���� ī�� ��ȣ��?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int cardnum;
	scanf("%d", &cardnum);

	int* cardqueue = (int*)malloc(sizeof(int) * cardnum);
	int front = 0, rear = -1;
	for (int i = 0; i < cardnum; i++) {
		cardqueue[i] = i + 1;
	}

	do {
		front++; //drop
		if (front >= cardnum) front = 0;
		cardqueue[++rear] = cardqueue[front++];
		if (front >= cardnum) front = 0;
	} while (front != rear);

	printf("%d", cardqueue[front]);

	free(cardqueue);

	return 0;
}
