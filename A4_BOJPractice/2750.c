//https://www.acmicpc.net/problem/2750

//�Է� ���� ���� �������� �����غ���. (�Է� �޴� ���� �ߺ� ���� ����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}


int main() {
	int testcase;
	scanf("%d", &testcase);
	
	int *arbnum = malloc(sizeof(int) * testcase);


	for (int i = 0; i < testcase; i++) {
		scanf("%d", &arbnum[i]);
	}

	qsort(arbnum, testcase, sizeof(int), compare); //�� ��Ʈ �˰���

	for (int i = 0; i < testcase; i++) {
		printf("%d\n", arbnum[i]);
	}

	free(arbnum);
}