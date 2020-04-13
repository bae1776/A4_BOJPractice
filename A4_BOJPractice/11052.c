//https://www.acmicpc.net/problem/11052

//카드 구매하기
//N개의 카드를 사려고 하는데, 1~N개 묶음 팩을 살 수 있다.
//민규는 카드가 비싸면 고성능의 카드가 나오리라 생각하므로 가능한 한 비싸게 묶음 팩을
//골라 N개를 사려고 한다.
//N과 1~N 까지의 묶음팩 가격이 주어질 때, N개의 카드를 사는 최댓값을 구하시오.
//단, 카드를 초과하게 사서 남는 만큼 버리는 건 허용하지 않는다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int cardNum;
	scanf("%d", &cardNum);

	int* DP = (int*)malloc(sizeof(int) * (cardNum + 1));
	DP[0] = 0;

	for (int i = 1; i <= cardNum; i++)
	{
		scanf("%d", &DP[i]);
	}

	for (int i = 1; i <= cardNum; i++)
	{
		int left = 1;
		int right = i - 1;
		while (left <= right) {
			int temp = DP[left] + DP[right];
			if (temp > DP[i]) DP[i] = temp;
			left++;
			right--;
		}
	}

	printf("%d", DP[cardNum]);

	free(DP);
	return 0;

}