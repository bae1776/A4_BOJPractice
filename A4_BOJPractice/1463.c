//https://www.acmicpc.net/problem/1463

//�Է¹��� ������ �Ʒ� 3���� ������ �̿��Ͽ� 1�� ���鶧 �ּ� ���� Ƚ���� ���Ͻÿ�.
//(1) 3���� ������. (3���� ������ ����������),  (2) 2�� ������. (2�� ������ ����������), (3) 1�� ����.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int input;
	scanf("%d", &input);

	int* calTimes = (int*)malloc(sizeof(int) * (input+1));
	calTimes[1] = 0;

	for (int i = 2; i <= input; i++)
	{
		int calMin = calTimes[i - 1] + 1;  //default = 1�� ����.
		if (i % 2 == 0 && calMin > calTimes[i / 2] + 1) calMin = calTimes[i / 2] + 1;  //2�� ������
		if (i % 3 == 0 && calMin > calTimes[i / 3] + 1) calMin = calTimes[i / 3] + 1;  //3���� ������
		calTimes[i] = calMin;
	}

	printf("%d", calTimes[input]);

	free(calTimes);
}