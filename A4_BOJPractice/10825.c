//https://www.acmicpc.net/problem/10825

//국영수
//학생 이름과 각 학생의 국어, 영어, 수학 점수가 주어질 때
//국어 점수가 높은 순 -> 영어 점수가 낮은 순 -> 수학 점수가 높은 순 -> 이름 사전 순으로 정렬하여
//학생 이름을 각 줄에 걸쳐서 출력하시오.

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