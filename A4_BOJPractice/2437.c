#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);



int main(void) {
	
	int limit = 0;
	int weightCount;

	//���� ���� �Է¹ޱ�
	scanf("%d", &weightCount);
	//���� ���� �Է¹ޱ�
	int* weights = (int*)malloc(sizeof(int) * (weightCount));
	for (int i = 0; i < weightCount; i++)
		scanf("%d", &weights[i]);

	//�������� ����
	qsort(weights, weightCount, sizeof(int), compare);
	
	//<�ͳ��� ����> 
	for (int i = 0; i < weightCount && limit + 1 >= weights[i]; i++)
		limit += weights[i];

	//�� ���
	printf("%d", limit + 1);

	free(weights);
	return 0;
}



int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}