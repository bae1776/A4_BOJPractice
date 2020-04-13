//https://www.acmicpc.net/problem/1021

//�����̴� N���� ���Ҹ� �����ϰ� �ִ� ����� ��ȯ ť�� ������ �ִ�.�����̴� �� ť���� �� ���� ���Ҹ� �̾Ƴ����� �Ѵ�.

//�����̴� �� ť���� ������ ���� 3���� ������ ������ �� �ִ�.

//1. ù ��° ���Ҹ� �̾Ƴ���.�� ������ �����ϸ�, ���� ť�� ���Ұ� a1, ..., ak�̾��� ���� a2, ..., ak�� ���� �ȴ�.
//2. �������� �� ĭ �̵���Ų��.�� ������ �����ϸ�, a1, ..., ak�� a2, ..., ak, a1�� �ȴ�.
//3. ���������� �� ĭ �̵���Ų��.�� ������ �����ϸ�, a1, ..., ak�� ak, a1, ..., ak - 1�� �ȴ�.

//���⼭ M���� (<= N) ���Ҹ� �������� �Ѵ�. M���� M�� ��ġ�� �־��� ��
//2, 3�� ������ �����ؾ� �ϴ� �ּ� Ƚ���� ���Ͻÿ�.


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