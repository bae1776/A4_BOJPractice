//https://www.acmicpc.net/problem/7568

//�Էµ� ����ŭ�� ������� ������ �־��� ��, ��ġ ������ ���ϴ� ����
//A�� B���� �����Ե� ũ�� Ű�� Ŀ�� ��ġ�� ũ�ٰ� �� �� �ִ�.
//�� �� �ϳ��� ū ��� ���� ������ �ű��.

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