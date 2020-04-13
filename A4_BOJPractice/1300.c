//https://www.acmicpc.net/problem/1300

/*
N*N크기의 배열을 만들었다. (배열의 방 번호는 1부터 시작한다.)
그 배열을 A라고 할때, A[i][j] = i * j 이다.
세준이는 이 수를 일차원 배열 B에 넣으려고 한다. 그러면, B의 크기는 N*N이 될 것이다.
그러고 난 후에, B를 오름차순 정렬해서 k번째 원소를 구하려고 한다.
N이 주어졌을 때, k번째 원소를 구하는 프로그램을 작성하시오.
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
	//A[i][j] = i * j <= (i-1)*n + j이 보장됨
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