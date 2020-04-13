//https://www.acmicpc.net/problem/1699

//���� ���� ��

//� �ڿ��� N�� �׺��� �۰ų� ���� ���������� ������ ��Ÿ�� �� �ִ�. 
//���� ��� 11=9+1+1(3�� ��)�̴�. �̷� ǥ������� ���� ������ �� �� �ִµ�, 
//11�� ��� 11=4+4+1+1+1(5�� ��)�� �����ϴ�. 
//�� ���, ������ ��ũ���׽��� ��11�� 3�� ���� ������ ������ ǥ���� �� �ִ�.����� ���Ѵ�. 
//���� 11�� �׺��� ���� ���� ������ ������ ǥ���� �� �����Ƿ�, 
//11�� �� �����ν� ǥ���� �� �ִ� ������ ���� �ּ� ������ 3�̴�.

//�־��� �ڿ��� N�� �̷��� ���������� ������ ǥ���� ���� 
//�� ���� �ּҰ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//N <= 100000

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int quadNum[400];

int main(void)
{
	int number;
	scanf("%d", &number);

	int i = 1;
	while (1) {
		int quad = i * i;
		quadNum[i] = i * i;
		if (quad <= number) {
			i++;
		}
		else break;
	}

	int* DP = (int*)malloc(sizeof(int) * (number + 1));

	
	int quadNumCursor = 1;
	for (int i = 1; i <= number; i++) {
		if (i == quadNum[quadNumCursor]) {
			DP[i] = 1;
			quadNumCursor++;
			continue;
		}
		else {
			int tempCursor = 1;
			int min = 123456789;
			while (i > quadNum[tempCursor]) {
				if (DP[i - quadNum[tempCursor]] < min) 
					min = DP[i - quadNum[tempCursor]];
				tempCursor++;
			}
			DP[i] = min + 1;
		}
	}


	printf("%d", DP[number]);
	free(DP);


	return 0;
}