#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);



int main(void) {
	
	int limit = 0;
	int weightCount;

	//추의 개수 입력받기
	scanf("%d", &weightCount);
	//추의 무게 입력받기
	int* weights = (int*)malloc(sizeof(int) * (weightCount));
	for (int i = 0; i < weightCount; i++)
		scanf("%d", &weights[i]);

	//오름차순 정렬
	qsort(weights, weightCount, sizeof(int), compare);
	
	//<귀납적 접근> 
	for (int i = 0; i < weightCount && limit + 1 >= weights[i]; i++)
		limit += weights[i];

	//답 출력
	printf("%d", limit + 1);

	free(weights);
	return 0;
}



int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}