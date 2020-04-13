//https://www.acmicpc.net/problem/2675

//테스트 케이스와 문자열과 반복 횟수가 주어졌을 때 출력하는 프로그램
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