//https://www.acmicpc.net/problem/11279

//최대 힙을 구현해보자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int heap[100001] = { 0 };

	int testcase;
	scanf("%d", &testcase);
	
	for (int i = 0; i < testcase; i++)
	{
		int input;
		scanf("%d", &input);

		if (input == 0) //추출
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
							if (heap[now_idx * 2] < heap[now_idx * 2 + 1])
							{
								if (heap[now_idx * 2 + 1] > heap[now_idx])
								{
									int temp = heap[now_idx];
									heap[now_idx] = heap[now_idx * 2 + 1];
									heap[now_idx * 2 + 1] = temp;
									now_idx = now_idx * 2 + 1;
								}
								else break;
							} 
							else {
								if (heap[now_idx * 2] > heap[now_idx])
								{
									int temp = heap[now_idx];
									heap[now_idx] = heap[now_idx * 2];
									heap[now_idx * 2] = temp;
									now_idx = now_idx * 2;
								}
								else break;
							} 
						}
						else {
							if (heap[now_idx * 2] > heap[now_idx])
							{
								int temp = heap[now_idx];
								heap[now_idx] = heap[now_idx * 2];
								heap[now_idx * 2] = temp;
								now_idx = now_idx * 2;
							}
							else break;
						}
					}
					else break;
				}

			}
		}
		else { //입력
			heap[++heap[0]] = input;

			int now_idx = heap[0];

			while (now_idx >= 2)
			{
				if (heap[now_idx] > heap[now_idx / 2])
				{
					int temp = heap[now_idx];
					heap[now_idx] = heap[now_idx / 2];
					heap[now_idx / 2] = temp;
					now_idx = now_idx / 2;
				}
				else break;
			}

		}


	}



	return 0;
}