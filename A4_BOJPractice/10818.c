//https://www.acmicpc.net/problem/10818 (���� ��ȣ)

//�ִ񰪰� �ּڰ� ���
//ù° �ٿ� �Է��� ������ ������ �־�����
//�Է��� ���� �߿��� ���� ���� ���� ���� ū ���� ���ʴ�� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int input;
	scanf("%d", &input);

	int max = -1000001;
	int min = 1000001;

	int num;

	for (int i = 0; i < input; i++) {
		scanf("%d", &num);
		if (num > max) max = num;
		if (num < min) min = num;
	}

	printf("%d %d", min, max);

}