//https://www.acmicpc.net/problem/1427

//�ڿ����� �־����� �ڸ����� ������������ �����Ͻÿ�.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//c(char*a,char*b) { return*b - *a; }main() { char n[10]; scanf("%s", n); int i = 0; 
//for (; n[i]; i++)n[i] -= 47;qsort(n, i, 1, c); for (i = 0; n[i]>0; i++)printf("%d",--n[i]); }   //���ڵ�

int compare(const void *a, const void *b) {
	return *(char *)b - *(char *)a;
}

int main() {
	char num[10];
	scanf("%s", num);

	int i;
	for (i = 0; num[i] != '\0'; i++) {
		num[i] -= '0';
	}
	num[i] = -1;

	qsort(num, i, sizeof(char), compare);

	for (int j = 0; num[j] >= 0; j++) {
		printf("%d", num[j]);
	}

}