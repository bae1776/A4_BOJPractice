//https://www.acmicpc.net/problem/10650

//좌표를 정렬 하시오. (x가 작은 순->y가 작은 순)

#include <stdio.h>
#include <stdlib.h>

typedef struct _point {
	int x;
	int y;
} Point;

void merge(Point* arr, int arrsize) //실제 Sorting하는 구간
{
	int left = 0;
	int right = arrsize / 2;
	Point* temparr = (Point*)malloc(sizeof(Point) * arrsize);
	for (int i = 0; i < arrsize; i++)
	{
		temparr[i].x = arr[i].x;
		temparr[i].y = arr[i].y;
	}

	int cursor = 0;
	while (left != arrsize / 2 && right != arrsize)
	{
		if (temparr[left].x < temparr[right].x)
		{
			arr[cursor].x = temparr[left].x;
			arr[cursor].y = temparr[left].y;
			left++;
		}
		else if (temparr[left].x > temparr[right].x) {
			arr[cursor].x = temparr[right].x;
			arr[cursor].y = temparr[right].y;
			right++;
		}
		else
		{
			if (temparr[left].y < temparr[right].y)
			{
				arr[cursor].x = temparr[left].x;
				arr[cursor].y = temparr[left].y;
				left++;
			}
			else {
				arr[cursor].x = temparr[right].x;
				arr[cursor].y = temparr[right].y;
				right++;
			}
		}
		cursor++;
	}

	while (left != arrsize/2)
	{
		arr[cursor].x = temparr[left].x;
		arr[cursor].y = temparr[left].y;
		left++;
		cursor++;
	}
	while (right != arrsize)
	{
		arr[cursor].x = temparr[right].x;
		arr[cursor].y = temparr[right].y;
		right++;
		cursor++;
	}

	free(temparr);
}

void pointMergeSort(Point* arr, int arrsize)
{
	if (arrsize <= 1) return;
	pointMergeSort(arr, arrsize / 2);
	pointMergeSort(arr + arrsize / 2, arrsize - arrsize / 2);
	merge(arr, arrsize);
}

int main(void)
{
	int pointNum;
	scanf("%d", &pointNum);

	Point* myPoints = (Point*)malloc(sizeof(Point) * pointNum);
	for (int i = 0; i < pointNum; i++)
	{
		scanf("%d %d", &myPoints[i].x, &myPoints[i].y);
	}

	pointMergeSort(myPoints, pointNum);

	for (int i = 0; i < pointNum; i++)
	{
		printf("%d %d\n", myPoints[i].x, myPoints[i].y);
	}

	free(myPoints);
}

