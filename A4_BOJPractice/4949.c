//https://www.acmicpc.net/problem/4949

//문자열에 괄호가 올바르게 쳐져 있는지 확인하는 문제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


char isEquality(char str[], int length) {
	char stack[100];
	int top = 0;

	for (int i = 0; i < length; i++) {
		switch (str[i]) {
		case '(':
			stack[top++] = '(';
			break;
		case ')':
			if (top == 0 || stack[top-1] != '(') return 0;
			else top--;
			break;
		case '[':
			stack[top++] = '[';
			break;
		case ']':
			if (top == 0 || stack[top - 1] != '[') return 0;
			else top--;
			break;
		case '.':
			i = length;
		}
	}

	if (top == 0) return 1;
	else return 0;
}


int main(void)
{
	char str[103];
	fgets(str, 102, stdin);
	int len = strlen(str) - 1;

	while (str[0] != '.' || len >= 2) {
		char judge = isEquality(str, len);

		if (judge == 0) printf("no\n");
		else printf("yes\n");

		fgets(str, 102, stdin);
		len = strlen(str) - 1;
	}
	
	return 0;
}
