//https://www.acmicpc.net/problem/1874

//스택 수열

#include <stdio.h>
#include <stdlib.h>

int* arr;
int* stack;
int top = 0;
char* stackOpr;
int opridx = 0;




int main(void) {
	int stackSize;
	scanf("%d", &stackSize);

	arr = (int*)malloc(sizeof(int) * (stackSize + 1));
	stack = (int*)malloc(sizeof(int) * stackSize);
	stackOpr = (char*)malloc(sizeof(char) * (stackSize * 2));

	arr[0] = 0;
	for (int i = 1; i <= stackSize; i++) {
		scanf("%d", &arr[i]);
	}
	//입력 받기

	int putNum = 1;
	char validity = 1;
	for (int i = 1; i <= stackSize; i++) {
		if (arr[i - 1] < arr[i]) {
			while (putNum <= arr[i]) {
				stackOpr[opridx++] = '+';
				stack[top++] = putNum++;
			}
			stackOpr[opridx++] = '-';
			top--;
		}
		else {
			if (top >= 1 && stack[--top] == arr[i]) {
				stackOpr[opridx++] = '-';
			}
			else {
				validity = 0;
				break;
			}
		}

		//printf("Operates : ");
		//for (int i = 0; i < opridx; i++) {
		//	printf("%c", stackOpr[i]);
		//}
		//printf("\nNowStack : ");
		//for (int i = 0; i < top; i++) {
		//	printf("%d ", stack[i]);
		//}
		//printf("  <- top\n\n");

	}

	if (validity) {
		for (int i = 0; i < stackSize * 2; i++) {
			printf("%c\n", stackOpr[i]);
		}
	}
	else {
		printf("NO");
	}

	free(arr);
	free(stack);
	free(stackOpr);

	return 0;

}