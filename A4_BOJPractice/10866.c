//https://www.acmicpc.net/problem/10866

//덱(Deque)을 구현하자.
//덱은 맨 앞, 맨 뒤에서만 탐색, 추가, 삭제를 할 수 있는 자료 구조이다.

//push_front X : 정수 X를 덱의 앞에 넣는다.
//push_back X : 정수 X를 덱의 뒤에 넣는다.
//pop_front : 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//pop_back : 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size : 덱에 들어있는 정수의 개수를 출력한다.
//empty : 덱이 비어있으면 1을, 아니면 0을 출력한다.
//front : 덱의 가장 앞에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//back : 덱의 가장 뒤에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

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