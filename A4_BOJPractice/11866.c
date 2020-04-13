//https://www.acmicpc.net/problem/11866

//(N, K)-요세푸스 순열을 출력하시오.
//1~N번까지의 사람들이 순서대로 원을 이루면서 앉아 있다. 이제 순서대로 K번째 사람을 제거한다.
//한 사람이 제거되면, 제거 된 사람부터 원 방향으로 K번째 사람을 제거하는 것을 계속 반복한다.
//이때 제거된 사람들의 번호를 순서대로 나열한 것을 (N, K)-요세푸스 순열이라고 한다.

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