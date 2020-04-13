//https://www.acmicpc.net/problem/10866

//��(Deque)�� ��������.
//���� �� ��, �� �ڿ����� Ž��, �߰�, ������ �� �� �ִ� �ڷ� �����̴�.

//push_front X : ���� X�� ���� �տ� �ִ´�.
//push_back X : ���� X�� ���� �ڿ� �ִ´�.
//pop_front : ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//pop_back : ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//size : ���� ����ִ� ������ ������ ����Ѵ�.
//empty : ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
//front : ���� ���� �տ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//back : ���� ���� �ڿ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int deque[20003];
int front = 10001;
int rear = 10000;

int main(void) {
	int command;
	scanf("%d", &command);
	char* commandstr[8] = { "push_front", "push_back", "pop_front", "pop_back", "size", "empty", "front", "back" };

	for (int i = 0; i < command; i++) {
		char input[15];
		scanf("%s", input);
		if (!strcmp(input, commandstr[0])) {
			int num;
			scanf("%d", &num);
			deque[--front] = num;
		}
		else if (!strcmp(input, commandstr[1])) {
			int num;
			scanf("%d", &num);
			deque[++rear] = num;
		}
		else if (!strcmp(input, commandstr[2])) {
			if (rear < front) /*No element*/ printf("-1\n");
			else printf("%d\n", deque[front++]);
		}
		else if (!strcmp(input, commandstr[3])) {
			if (rear < front) /*No element*/ printf("-1\n");
			else printf("%d\n", deque[rear--]);
		}
		else if (!strcmp(input, commandstr[4])) {
			printf("%d\n", rear - front + 1);
		}
		else if (!strcmp(input, commandstr[5])) {
			if (rear < front) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(input, commandstr[6])) {
			if (rear < front) /*No element*/ printf("-1\n");
			else printf("%d\n", deque[front]);
		}
		else if (!strcmp(input, commandstr[7])) {
			if (rear < front) /*No element*/ printf("-1\n");
			else printf("%d\n", deque[rear]);
		}

	}


	return 0;
}