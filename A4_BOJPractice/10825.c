//https://www.acmicpc.net/problem/10825

//������
//�л� �̸��� �� �л��� ����, ����, ���� ������ �־��� ��
//���� ������ ���� �� -> ���� ������ ���� �� -> ���� ������ ���� �� -> �̸� ���� ������ �����Ͽ�
//�л� �̸��� �� �ٿ� ���ļ� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[12];
	int korean;
	int english;
	int math;
} Student;

int cmp(const void* a, const void* b)
{
	if ((*(Student*)a).korean != (*(Student*)b).korean)
		return (*(Student*)b).korean - (*(Student*)a).korean;
	else if ((*(Student*)a).english != (*(Student*)b).english)
		return (*(Student*)a).english - (*(Student*)b).english;
	else if ((*(Student*)a).math != (*(Student*)b).math)
		return (*(Student*)b).math - (*(Student*)a).math;
	else return strcmp((*(Student*)a).name, (*(Student*)b).name);
}


int main(void)
{
	int studentCount;
	scanf("%d", &studentCount);

	Student* studentList = (Student*)malloc(sizeof(Student) * studentCount);
	for (int i = 0; i < studentCount; i++)
	{
		scanf("%s %d %d %d",
			studentList[i].name, &(studentList[i].korean), &(studentList[i].english), &(studentList[i].math));
	}
	
	qsort(studentList, studentCount, sizeof(Student), cmp);

	for (int i = 0; i < studentCount; i++)
	{
		printf("%s\n", studentList[i].name);
	}
	free(studentList);

	return 0;
}