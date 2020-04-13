//https://www.acmicpc.net/problem/1300

/*
N*Nũ���� �迭�� �������. (�迭�� �� ��ȣ�� 1���� �����Ѵ�.)
�� �迭�� A��� �Ҷ�, A[i][j] = i * j �̴�.
�����̴� �� ���� ������ �迭 B�� �������� �Ѵ�. �׷���, B�� ũ��� N*N�� �� ���̴�.
�׷��� �� �Ŀ�, B�� �������� �����ؼ� k��° ���Ҹ� ���Ϸ��� �Ѵ�.
N�� �־����� ��, k��° ���Ҹ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int arrsize, order;
	scanf("%d %d", &arrsize, &order);

	int left = 1;
	int right = order;
	//A[i][j] = i * j <= (i-1)*n + j�� �����
	//A[i][j] -> B[(i-1)*n + j]
	int result = -1;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		long long int undersame = 0;

		for (int i = 1; i <= arrsize; i++) {
			long long int temp = middle / i;
			undersame += arrsize < temp ? arrsize : temp;
		}

		if (undersame >= order)
		{
			result = middle;
			right = middle - 1;
		}
		else
			left = middle + 1;
	}

	printf("%d", result);



	return 0;
}