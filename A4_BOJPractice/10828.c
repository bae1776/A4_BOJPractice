//https://www.acmicpc.net/problem/10828

//스택의 개념 익히고 실습해보기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	//back의 뒷부분부터 back[0] -> front[0] ~ front의 뒷부분 순으로 출력한다.

	int header = 0;
	int stack[10000] = { 0, };
	int testcase;

	scanf("%d", &testcase);
	char *reserved[5] = {"push", "pop", "size", "empty", "top" };
	for (int t = 0; t < testcase; t++) {
		int i = 0;
		char command[10];
		scanf("%s", command);
		if (!strncmp(command, reserved[i], sizeof(reserved[i]))) {
			int element;
			scanf("%d", &element);
			stack[header] = element; header++; continue;
		}
		i++;
		if (!strncmp(command, reserved[i], sizeof(reserved[i]))) {
			if (header) {
				printf("%d\n", stack[header - 1]);
				stack[header - 1] = 0; header--; continue;
			}
			else printf("-1\n");
		}
		i++;
		if (!strncmp(command, reserved[i], sizeof(reserved[i]))) {
			printf("%d\n", header); continue;
		}
		i++;
		if (!strncmp(command, reserved[i], sizeof(reserved[i]))) {
			if (header) printf("0\n");
			else printf("1\n"); continue;
		}
		i++;
		if (!strncmp(command, reserved[i], sizeof(reserved[i]))) {
			if (header) {
				printf("%d\n", stack[header - 1]);
				continue;
			}
			else printf("-1\n");
		}
		
	}

	
}

//1~2까지의 수에 대해 가능한 스택

