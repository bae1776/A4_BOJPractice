//https://www.acmicpc.net/problem/14889

//�Ｚ ���� : ��ŸƮ�� ��ũ
//¦�� ���� ���� �̷���� ���� �� ������ �ó��� �ɷ�ġ�� �־�����
//�� ������ �ɷ�ġ ���� �ּҰ� �ǵ��� ���� © ���� �ɷ�ġ ���̸� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int getNextTeam(int* arr, int arrsize)   //��ŸƮ ���� ������������ ����
{
	if (arrsize <= 2) return 0;

	int addidx = arrsize / 2 - 1;
	while (arr[addidx] >= arrsize / 2 + addidx)
	{
		if (addidx == 1) return 0;
		addidx--;
	}

	arr[addidx]++;

	while (addidx + 1 < arrsize / 2)
	{
		arr[addidx + 1] = arr[addidx] + 1;
		addidx++;
	}

	int sTeamidx = 0;
	int lMemnum = 0;

	//��ũ �� ����
	for (int i = arrsize / 2; i < arrsize; i++)
	{
		while (lMemnum == arr[sTeamidx])
		{
			lMemnum++;
			sTeamidx++;
		}
		arr[i] = lMemnum++;
	}


	return 1;
}

int getStat(int** statArr, int* arr, int arrsize)
{
	int sum = 0;
	for (int i = 0; i < arrsize; i++)
		for (int j = i + 1; j < arrsize; j++)
			sum += statArr[arr[i]][arr[j]];

	return sum;
}


int main(void)
{
	int people;
	scanf("%d", &people);

	int** statArr = (int**)malloc(sizeof(int*) * people);

	for (int i = 0; i < people; i++)
	{
		statArr[i] = (int*)malloc(sizeof(int) * people);
		for (int j = 0; j < people; j++)
		{
			scanf("%d", &statArr[i][j]);
		}
	}


	for (int i = 0; i < people; i++)
	{
		for (int j = i + 1; j < people; j++)
			statArr[i][j] += statArr[j][i];
	}


	int* tempTeamSet = (int*)malloc(sizeof(int) * people);
	//�迭�� ���� ������ ���� ���� ��ŸƮ�� �����̰�, ������ ���� ��ũ�� ������.
	for (int i = 0; i < people; i++)
	{
		tempTeamSet[i] = i;
	}

	//for (int i = 0; i < people; i++)
	//{
	//	for (int j = 0; j < people; j++)
	//	{
	//		if (i < j) printf("%2d ", statArr[i][j]);
	//		else printf("   ");
	//	}
	//	printf("\n");
	//}

	int mingap = 0x7FFFFFFF;
	do {
		int startTeamstat = getStat(statArr, tempTeamSet, people / 2);
		int linkTeamstat = getStat(statArr, tempTeamSet + people / 2, people / 2);

		int tempGap = startTeamstat > linkTeamstat ? startTeamstat - linkTeamstat : linkTeamstat - startTeamstat;
		if (tempGap < mingap)
			mingap = tempGap;
		//for (int i = 0; i < people; i++)
		//{
		//	printf("%d ", tempTeamSet[i]);
		//}
		//printf("--> %d vs %d\n", startTeamstat, linkTeamstat);
	} while (getNextTeam(tempTeamSet, people));


	printf("%d", mingap);


	return 0;
}