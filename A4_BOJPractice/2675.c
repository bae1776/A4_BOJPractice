//https://www.acmicpc.net/problem/2675

//�׽�Ʈ ���̽��� ���ڿ��� �ݺ� Ƚ���� �־����� �� ����ϴ� ���α׷�
//3 ABC -> AAABBBCCC

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int testcase;
	scanf("%d", &testcase);
	
	for (int i = 0; i < testcase; i++) {
		int repeat;
		char str[21];
		scanf("%d %s", &repeat, str);
		for (int index = 0; str[index] != 0; index++) {
			for (int i = 0; i < repeat; i++) {
				printf("%c", str[index]);
			}
		}
		printf("\n");
	}
}