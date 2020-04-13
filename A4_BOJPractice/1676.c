//https://www.acmicpc.net/problem/1676

//N�� �־��� �� N! ������ �ǳ��� 0�� �� �� �������� �پ��ִ��� ����Ͻÿ�.
//N <= 500.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int num;
	scanf("%d", &num);

	int countOf2 = 0;
	int countOf5 = 0;

	for (int i = 2; i <= num; i++) {
		int temp = i;
		while (temp % 2 == 0) {
			temp /= 2;
			countOf2++;
		}
		while (temp % 5 == 0) {
			temp /= 5;
			countOf5++;
			
		}
	}

	printf("%d", countOf2 > countOf5 ? countOf5 : countOf2);

	return 0;
}