//https://www.acmicpc.net/problem/2753

//����
//������ �Է¹ް� �����̸� 1 �ƴϸ� 0�� ����Ͻÿ�.

#include <stdio.h>

int main() {
	short year;
	char output;
	scanf("%hd", &year);
	output = (year % 400 == 0) ? 1 : ((year % 100 == 0) ? 0 : ((year % 4) ? 0 : 1));
	printf("%d", output);

	return 0;
}