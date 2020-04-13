//https://www.acmicpc.net/problem/11866

//(N, K)-�似Ǫ�� ������ ����Ͻÿ�.
//1~N�������� ������� ������� ���� �̷�鼭 �ɾ� �ִ�. ���� ������� K��° ����� �����Ѵ�.
//�� ����� ���ŵǸ�, ���� �� ������� �� �������� K��° ����� �����ϴ� ���� ��� �ݺ��Ѵ�.
//�̶� ���ŵ� ������� ��ȣ�� ������� ������ ���� (N, K)-�似Ǫ�� �����̶�� �Ѵ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int queue[1000];
int front, rear;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		queue[i] = i + 1;
	}
	front = 0;
	rear = N-1;

	printf("<");
	while (front != rear) {
		for (int i = 0; i < K - 1; i++) {
			if (rear == N - 1) rear = -1;
			queue[++rear] = queue[front++];
			if (front == N) front = 0;
		}
		printf("%d, ", queue[front++]);
		if (front == N) front = 0;
	}
	

	printf("%d>", queue[front]);

}