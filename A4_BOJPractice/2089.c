//https://www.acmicpc.net/problem/2089

//10������ �־����� -2������ ��ȯ�Ͻÿ�.
//1(-2) = 1(10), 10(-2) = -2(10), 100 = 4(10)...
//10������ int �����̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[200];
int top = -1;


int main(void)
{
	int num;
	scanf("%d", &num);

	if (num == 0) printf("0");
	while (num != 0) {
		stack[++top] = num % -2;
		num /= -2;
	}
	
	for (int i = 0; i <= top; i++) {
		switch (stack[i]) {
		case -1:
			stack[i] = 1;
			stack[i + 1] += 1;
			if (i + 1 > top) top = i + 1;
			break;
		case 2:
			stack[i] = 0;
			stack[i + 1] += 1;
			stack[i + 2] += 1;
			if (i + 2 > top) top = i + 2;
			break;
		}
	}

	while (top >= 0) {
		printf("%d", stack[top--]);
	}
	
	

	return 0;
}