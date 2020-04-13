//https://www.acmicpc.net/problem/10773

//Á¦·Î

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int testcase;
	scanf("%d", &testcase);

	int* taskarray = (int *)calloc(testcase, sizeof(int));
	int wrindex = 0;

	for (int i = 0; i < testcase; i++) {
		int input;
		scanf("%d", &input);
		if (input == 0) {
			taskarray[wrindex-1] = 0;
			wrindex--;
		}
		else {
			taskarray[wrindex] = input;
			wrindex++;
		}
	}
	
	int sum = 0;
	for (int i = 0; taskarray[i] != 0; i++) {
		sum += taskarray[i];
	}

	printf("%d", sum);
}