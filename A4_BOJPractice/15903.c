//https://www.acmicpc.net/problem/15903

/* 카드 합체 놀이 (Silver 1)

자연수 카드 n(~1000)개와 카드 합체 횟수 m(~15n)이 주어진다.
카드 합체는 다음과 같은 과정으로 이루어진다.

1. x번 카드와 y번 카드를 골라 그 두 장에 쓰여진 수를 더한 값을 계산한다. (x ≠ y)
2. 계산한 값을 x번 카드와 y번 카드 두 장 모두에 덮어 쓴다.

카드 합체가 모두 끝난 뒤, 이 점수를 가장 작게 만드는 것이 놀이의 목표일때,
최저 점수를 구하세요.

Solution : 
그리디 알고리즘을 적용해 (항상 가장 작은 수 2개를 고른다) 
우선 순위 큐 자료구조를 이용한다. (가장 작은 원소 2개를 pop하고 더한 결과를 2개 push)
*/

#include <stdio.h>
#define SWAP(a, b) long long temp = a; a = b; b = temp
long long priorityQueue[1001];

void pushPQ(long long value)
{
	long long index;
	priorityQueue[index = ++priorityQueue[0]] = value;

	while (index > 1)
	{
		if (priorityQueue[index] < priorityQueue[index / 2])
		{
			SWAP(priorityQueue[index], priorityQueue[index / 2]);
			index /= 2;
		} else break;
	}
}

long long popPQ()
{
	long long index = 1;
	long long top = priorityQueue[1];
	priorityQueue[1] = priorityQueue[priorityQueue[0]--];

	while (1)
	{
		if (priorityQueue[0] >= index * 2 + 1)
		{
			if (priorityQueue[index * 2] < priorityQueue[index * 2 + 1])
			{
				if (priorityQueue[index * 2] < priorityQueue[index])
				{
					SWAP(priorityQueue[index * 2], priorityQueue[index]);
					index *= 2;
				} else break;
			} else {
				if (priorityQueue[index * 2 + 1] < priorityQueue[index])
				{
					SWAP(priorityQueue[index * 2 + 1], priorityQueue[index]);
					index = index * 2 + 1;
				} else break;
			}
		} else if (priorityQueue[0] == index * 2) {
			if (priorityQueue[index * 2] < priorityQueue[index])
			{
				SWAP(priorityQueue[index * 2], priorityQueue[index]);
				index *= 2;
			} else break;
		} else
			break;
	}

	return top; 
}


int main(void)
{
	int cardCount, sumCount;
	scanf("%d %d", &cardCount, &sumCount);

	long long input, result = 0;
	while (cardCount--)
	{
		scanf("%lld", &input);
		pushPQ(input);
	}

	while (sumCount--)
	{
		long long one = popPQ();
		long long two = popPQ();
		pushPQ(one + two);
		pushPQ(one + two);
	}

	while (priorityQueue[0])
		result += popPQ();
	
	printf("%lld", result);

	return 0;
}
