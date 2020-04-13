//https://www.acmicpc.net/problem/2156

//������ �ý�ȸ���� �Ϸķ� ������ ������ �ܵ��� �ִ��� ���� ���� �������� �Ѵ�.
//�׷��� �������� ���� 3���� ��� ���� �� ����.
//������ �� ����, �� ���� ������ ���� �־��� �� ���� �� �ִ� �������� �ִ밪��?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) 
{
	int glasses;
	scanf("%d", &glasses);

	int* glassList = (int*)malloc(sizeof(int) * glasses);
	for (int i = 0; i < glasses; i++)
		scanf("%d", &glassList[i]);

	int* befselect = (int*)malloc(sizeof(int) * glasses);
	int* befnselect = (int*)malloc(sizeof(int) * glasses);

	befselect[0] = 0;
	befnselect[0] = glassList[0];

	if (glasses >= 1)
	{
		befselect[1] = glassList[0] + glassList[1];
		befnselect[1] = glassList[1];
	}

	for (int i = 2; i < glasses; i++)
	{
		befselect[i] = befnselect[i - 1] + glassList[i];
		if (i >= 3) {
			int temp1 = befselect[i - 2] > befnselect[i - 2] ? befselect[i - 2] : befnselect[i - 2];
			int temp2 = befselect[i - 3] > befnselect[i - 3] ? befselect[i - 3] : befnselect[i - 3];
			befnselect[i] = (temp1 > temp2 ? temp1 : temp2) + glassList[i];
		}
		else befnselect[i] = (befselect[i - 2] > befnselect[i - 2] ? befselect[i - 2] : befnselect[i - 2]) + glassList[i];
	}

	int max = 0;
	for (int i = glasses - 2; i < glasses; i++)
	{
		if (i < 0) continue;
		if (befselect[i] > max) max = befselect[i];
		if (befnselect[i] > max) max = befnselect[i];
	}

	printf("%d", max);

}