//https://www.acmicpc.net/problem/1655

//우선순위 큐를 응용하여 수를 입력받을 때마다의 중간값을 출력하는 프로그램을 만들자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(a, b, type) do{type temp = a; a = b; b = temp;}while(0)
#define RMIN 0
#define LMAX 1

int middle;
int left[50005] = { 0 };
int right[50005] = { 0 };

int deleteHeap(char heapType);
void insertHeap(int value, char heapType);


int main(void)
{
	int testcase;
	scanf("%d", &testcase);
	scanf("%d", &middle);
	printf("%d\n", middle);

	for (int i = 1; i < testcase; i++)
	{
		//R은 L보다 1크거나 같아야한다.
		int input;
		scanf("%d", &input);

		if (input >= middle)
		{
			if (left[0] < right[0])
			{
				insertHeap(input, RMIN);
				int temp = middle;
				middle = deleteHeap(RMIN);
				insertHeap(temp, LMAX);
			}
			else {
				insertHeap(input, RMIN);
			}
		}
		else if (input < middle) 
		{
			if (left[0] == right[0])
			{
				insertHeap(input, LMAX);
				int temp = middle;
				middle = deleteHeap(LMAX);
				insertHeap(temp, RMIN);
			}
			else {
				insertHeap(input, LMAX);
			}
		}
		printf("%d\n", middle);
	}
}


int deleteHeap(char heapType)
{
	int headValue, now_pos;
	switch (heapType)
	{
	case RMIN:
		headValue = right[1];
		right[1] = right[right[0]--];
		now_pos = 1;
		
		while (1)
		{
			if (now_pos * 2 + 1 <= right[0])
			{
				if (right[now_pos * 2] < right[now_pos * 2 + 1])
				{
					if (right[now_pos] >= right[now_pos * 2])
					{
						SWAP(right[now_pos], right[now_pos * 2], int);
						now_pos = now_pos * 2;
					}
					else break;
				}
				else {
					if (right[now_pos] >= right[now_pos * 2 + 1])
					{
						SWAP(right[now_pos], right[now_pos * 2 + 1], int);
						now_pos = now_pos * 2 + 1;
					}
					else break;
				}
			}
			else if (now_pos * 2 <= right[0])
			{
				if (right[now_pos] >= right[now_pos * 2])
				{
					SWAP(right[now_pos], right[now_pos * 2], int);
					now_pos = now_pos * 2;
				}
				else break;
			}
			else break;
		}
		break;
	case LMAX:
		headValue = left[1];
		left[1] = left[left[0]--];
		now_pos = 1;

		while (1)
		{
			if (now_pos * 2 + 1 <= left[0])
			{
				if (left[now_pos * 2] > left[now_pos * 2 + 1])
				{
					if (left[now_pos] <= left[now_pos * 2])
					{
						SWAP(left[now_pos], left[now_pos * 2], int);
						now_pos = now_pos * 2;
					}
					else break;
				}
				else {
					if (left[now_pos] <= left[now_pos * 2 + 1])
					{
						SWAP(left[now_pos], left[now_pos * 2 + 1], int);
						now_pos = now_pos * 2 + 1;
					}
					else break;
				}
			}
			else if (now_pos * 2 <= left[0])
			{
				if (left[now_pos] <= left[now_pos * 2])
				{
					SWAP(left[now_pos], left[now_pos * 2], int);
					now_pos = now_pos * 2;
				}
				else break;
			}
			else break;
		}
	}
	return headValue;
}


void insertHeap(int value, char heapType)
{
	int now_pos;
	switch (heapType)
	{
	case RMIN:
		right[++right[0]] = value;
		now_pos = right[0];

		while (now_pos >= 2)
		{
			if (right[now_pos] <= right[now_pos / 2])
			{
				SWAP(right[now_pos], right[now_pos / 2], int);
				now_pos = now_pos / 2;
			}
			else break;
		}
		return;
	case LMAX:
		left[++left[0]] = value;
		now_pos = left[0];

		while (now_pos >= 2)
		{
			if (left[now_pos] >= left[now_pos / 2])
			{
				SWAP(left[now_pos], left[now_pos / 2], int);
				now_pos = now_pos / 2;
			}
			else break;
		}
		return;
	}
}