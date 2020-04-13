//https://www.acmicpc.net/problem/14889

//삼성 기출 : 스타트와 링크
//짝수 명의 팀을 이루었을 때의 둘 사이의 시너지 능력치가 주어질때
//두 팀간의 능력치 차가 최소가 되도록 팀을 짤 때의 능력치 차이를 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int getNextTeam(int* arr, int arrsize)   //스타트 팀을 오름차순으로 구성
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

	//링크 팀 구성
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
	//배열을 절반 나눠서 왼쪽 반은 스타트팀 구성이고, 오른쪽 반은 링크팀 구성임.
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