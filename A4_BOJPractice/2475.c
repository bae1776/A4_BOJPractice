//https://www.acmicpc.net/problem/2475

//������
//KOI ���ڿ����� ��ǻ�͸� ���� 6�ڸ��� ������ȣ�� �ű�µ�,
//������ 6��°���� �������� ����. �������� ������ȣ ó�� 5�ڸ��� ���� 5���� ���ڸ�
//���� ������ ���� ���� 10���� ���� �������̴�.
//�������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int number[5];
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &number[i]);
		sum += number[i] * number[i];
	}
	printf("%d", sum % 10);

}