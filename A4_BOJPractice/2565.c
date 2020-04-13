//https://www.acmicpc.net/problem/2565

//전깃줄이 마구 뒤엉켜 연결되어 있어서, 전깃줄을 잘라 전깃줄이 교차되지 않도록 하려한다.
//잘라할 전깃줄 수의 최소는 ?
//첫째 줄엔 전깃줄 갯수, 둘째줄 부턴 각 전깃줄의 시작/끝지점이 주어진다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct elecl {
	int start_line;
	int end_line;
} elecLine;


int cmp(const void* a, const void* b)
{
	return (*(elecLine*)a).start_line - (*(elecLine*)b).start_line;
}


int main(void)
{
	int lineCount;
	scanf("%d", &lineCount);
	
	elecLine* lineList = (elecLine*)malloc(sizeof(elecLine) * lineCount);
	int* dp = (int*)calloc(lineCount, sizeof(int));

	for (int i = 0; i < lineCount; i++)
		scanf("%d %d", &lineList[i].start_line, &lineList[i].end_line);

	qsort(lineList, lineCount, sizeof(elecLine), cmp);

	dp[0] = 1;

	for (int i = 1; i < lineCount; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (dp[j] > max && lineList[j].end_line < lineList[i].end_line) max = dp[j];
		}
		dp[i] = max + 1;
	}

	int dpmax = 0;
	for (int i = 0; i < lineCount; i++)
		if (dp[i] > dpmax) dpmax = dp[i];
	
	printf("%d", lineCount - dpmax);

	free(lineList);
	free(dp);

	return 0;
}