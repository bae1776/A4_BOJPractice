//https://www.acmicpc.net/problem/2609

//�� ���� �־�����, �� ���� �ִ������� �ּ� ������� ���Ͻÿ�.
//���� ������ ~10000

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int left, right;
	scanf("%d %d", &left, &right);

	if (left > right) {
		int temp = left;
		left = right;
		right = temp;
	}

	int cofactor = 0;
	for (int i = left; i >= 1; i--) {
		if (left % i == 0 && right % i == 0)
		{
			cofactor = i;
			break;
		}
	}

	printf("%d\n%d", cofactor, left * right / cofactor);


	return 0;
}