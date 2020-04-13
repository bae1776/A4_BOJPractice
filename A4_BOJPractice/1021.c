//https://www.acmicpc.net/problem/1021

//지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다.지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

//지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

//1. 첫 번째 원소를 뽑아낸다.이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
//2. 왼쪽으로 한 칸 이동시킨다.이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
//3. 오른쪽으로 한 칸 이동시킨다.이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak - 1이 된다.

//여기서 M개의 (<= N) 원소를 뽑으려고 한다. M값과 M의 위치가 주어질 때
//2, 3번 연산을 수행해야 하는 최소 횟수를 구하시오.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int queueSize, selectCount;
	scanf("%d %d", &queueSize, &selectCount);

	int* selectPos = (int*)malloc(sizeof(int) * selectCount);
	for (int i = 0; i < selectCount; i++) {
		scanf("%d", &selectPos[i]);
	}

	int* queue = (int*)malloc(sizeof(int) * queueSize);
	for (int i = 0; i < queueSize; i++) {
		queue[i] = i + 1;
	}

	int front = 0;
	int nowSize = queueSize;
	int selectOrder = 0;
	int totalMove = 0;

	while (selectOrder < selectCount) {
		int moveCount = 0;
		while (queue[front] != selectPos[selectOrder]) {
			front++;
			if (front >= queueSize) front = 0;
			if (queue[front] != 0) moveCount++;
		}

		queue[front] = 0;
		if (nowSize >= 2) {
			while (queue[front] == 0) {
				front++;
				if (front >= queueSize) front = 0;
			}
		}
		selectOrder++;
		totalMove += nowSize - moveCount > moveCount ? moveCount : nowSize - moveCount;
		nowSize--;
	}

	printf("%d", totalMove);

	free(selectPos);
	free(queue);
	return 0;
}