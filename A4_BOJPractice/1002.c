//https://www.acmicpc.net/problem/1002

//터렛
//두 터렛의 좌표(위치)와 각 터렛에서 대상에까지의 거리가 주어질 때 대상이 있을 수 있는 위치의 경우의 수를 출력하시오.
//-> 서로 다른 원과의 관계

#include <stdio.h>

int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int ax, ay, adist, bx, by, bdist;
		scanf("%d %d %d %d %d %d", &ax, &ay, &adist, &bx, &by, &bdist);
		int turretdist = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
		int distdist = (adist + bdist) * (adist + bdist);

		if (distdist < turretdist)
		{
			printf("0");
		}
		else if (distdist == turretdist) {
			printf("1");
		}
		else {
			int gapdist = (adist - bdist) * (adist - bdist);
			if (gapdist < turretdist)
			{
				printf("2");
			}
			else if (gapdist == turretdist) {
				if (gapdist == 0)
				{
					printf("-1");
				}
				else {
					printf("1");
				}
			}
			else {
				printf("0");
			}
		}
		printf("\n");
	}


	return 0;
}