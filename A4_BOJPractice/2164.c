//https://www.acmicpc.net/problem/2164

//1~n 번호가 적힌 카드가 숫자 순으로 쌓여있다. 1번 카드가 맨 위에 온다.
//제일 위에 있는 카드를 버리고, 그 다음 제일 위에 있는 카드를 맨 뒤로 옮긴다.
//이를 계속 반복할 때, 마지막에 한 장 남았을 때의 카드 번호는?

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
