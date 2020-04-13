//https://www.acmicpc.net/problem/11286

//���� ���� �����غ���.
//������ ���� ������ ����ϰ�, ������ ���ٸ� �� ���� ���� ����Ѵ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(a, b, type) do{type temp = a; a = b; b = temp;}while(0)


int absCompare(int left, int right) {
	//��� �켱���� left�� �� ������ 1 �ƴϸ� -1
	char leftneg = 0;
	char rightneg = 0;
	if (left < 0)
	{
		left = -left;
		leftneg = 1;
	}
	if (right < 0)
	{
		right = -right;
		rightneg = 1;
	}

	if (left < right) return 1;
	else if (left > right) return -1;
	else {
		if (leftneg == rightneg) return 0;
		else {
			if (leftneg) return 1;
			else return -1;
		}
	}
}


int main(void)
{
	int heap[100001] = { 0 };

	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int input;
		scanf("%d", &input);

		if (input == 0) //����
		{
			if (heap[0] == 0) printf("0\n");
			else {
				printf("%d\n", heap[1]);
				heap[1] = heap[heap[0]--];

				int now_idx = 1;
				while (1)
				{
					if (now_idx * 2 <= heap[0])
					{
						if (now_idx * 2 + 1 <= heap[0])
						{
							if (absCompare(heap[now_idx * 2], heap[now_idx * 2 + 1]) >= 0)
							{
								if (absCompare(heap[now_idx], heap[now_idx * 2]) <= 0)
								{
									SWAP(heap[now_idx], heap[now_idx * 2], int);
									now_idx = now_idx * 2;
								}
								else break;
							}
							else {
								if (absCompare(heap[now_idx], heap[now_idx * 2 + 1]) <= 0)
								{
									SWAP(heap[now_idx], heap[now_idx * 2 + 1], int);
									now_idx = now_idx * 2 + 1;
								}
								else break;
							}
						}
						else {
							if (absCompare(heap[now_idx], heap[now_idx * 2]) <= 0)
							{
								SWAP(heap[now_idx], heap[now_idx * 2], int);
								now_idx = now_idx * 2;
							}
							else break;
						}
					}
					else break;
				}

			}
		}
		else { //�Է�
			heap[++heap[0]] = input;

			int now_idx = heap[0];

			while (now_idx >= 2)
			{
				if (absCompare(heap[now_idx], heap[now_idx / 2]) >= 0)
				{
					SWAP(heap[now_idx], heap[now_idx / 2], int);
					now_idx = now_idx / 2;
				} else break;
			}

		}


	}



	return 0;
}