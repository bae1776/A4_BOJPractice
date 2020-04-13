//https://www.acmicpc.net/problem/1002

//�ͷ�
//�� �ͷ��� ��ǥ(��ġ)�� �� �ͷ����� ��󿡱����� �Ÿ��� �־��� �� ����� ���� �� �ִ� ��ġ�� ����� ���� ����Ͻÿ�.
//-> ���� �ٸ� ������ ����

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