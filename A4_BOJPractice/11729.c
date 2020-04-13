//https://www.acmicpc.net/problem/1065

//하노이 탑 재귀문제
#include <stdio.h>
#include <stdlib.h>

int move_count = 0;
int* move_log;

int twoexp(int input)
{
	int ans = 1;
	for (int i = 0; i < input; i++)
	{
		ans <<= 1;
	}
	return ans;
}

void hanoi_tower(int from, int mid, int to, int tower_height)
{
	if (tower_height <= 0) return;
	hanoi_tower(from, to, mid, tower_height - 1);
	move_log[move_count++] = from; 
	move_log[move_count++] = to;
	hanoi_tower(mid, from, to, tower_height - 1);
}

int main(void)
{
	int input;
	scanf("%d", &input);

	move_log = (int*)malloc(sizeof(int) * twoexp(input) * 2);

	hanoi_tower(1, 2, 3, input);

	printf("%d\n", move_count / 2);
	for (int i = 0; i < move_count; i)
	{
		printf("%d ", move_log[i++]);
		printf("%d\n", move_log[i++]);
	}

	free(move_log);
}