//https://www.acmicpc.net/problem/11653

//���� N�� �־����� �� ���μ������ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���μ� ���� ���ڴ� ������������ ����Ѵ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int num;
	scanf("%d", &num);
	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			printf("%d\n", i);
			num /= i;
		}
	}
	return 0;
}