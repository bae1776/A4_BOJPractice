//https://www.acmicpc.net/problem/7568

//입력된 수만큼의 사람들의 신장이 주어질 때, 덩치 순위를 구하는 문제
//A가 B보다 몸무게도 크고 키도 커야 덩치가 크다고 할 수 있다.
//둘 중 하나만 큰 경우 공동 순위로 매긴다.

#include <stdio.h>
#include <stdlib.h>

typedef struct _inbody
{
	int weight;
	int height;
} Inbody;

void judgeGrade(Inbody* data, int* grade, int num)
{
	for (int i = 0; i < num; i++)
	{
		int tmpgrade = 1;
		Inbody temp = data[i];
		for (int j = 0; j < num; j++)
		{
			if (data[j].weight > temp.weight && data[j].height > temp.height)
				tmpgrade++;
		}

		grade[i] = tmpgrade;
	}

}

int main(void)
{
	int number;
	scanf("%d", &number);

	Inbody* peopleData = (Inbody*)malloc(sizeof(Inbody) * number);
	int* grade = (int*)malloc(sizeof(int) * number);

	for (int i = 0; i < number; i++)
	{
		scanf("%d %d", &peopleData[i].weight, &peopleData[i].height);
	}


	judgeGrade(peopleData, grade, number);


	for (int i = 0; i < number; i++)
	{
		printf("%d ", grade[i]);
	}

	return 0;
}