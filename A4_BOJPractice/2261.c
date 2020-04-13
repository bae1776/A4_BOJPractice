//https://www.acmicpc.net/problem/2261

//Platinum V
//각 점의 좌표가 주어질 때, 가장 가까운 두 점의 거리의 제곱을 구하시오.
//점이 최대 10만개 주어지므로 O(n^2) 알고리즘으로는 통과할 수 없다.

//풀이 : 점을 반씩 나누어 왼쪽 최소, 오른쪽 최소를 구하고 반 나누는 지점에서 너무 떨어진 점들을 다 쳐내고
//인접한 것들끼리만 계산 : O(n(logn)^2)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} Point;



int cmpx(const void* a, const void* b) {
	return (*(Point*)a).x - (*(Point*)b).x;
}

int cmpy(const void* a, const void* b) {
	return (*(Point*)a).y - (*(Point*)b).y;
}

int minDist(Point* myPoint, int pointCount) {
	int result = 0x7FFFFFFF;
	if (pointCount <= 4) {
		for (int i = 0; i < pointCount; i++)
			for (int j = i + 1; j < pointCount; j++)
			{
				int temp = (myPoint[i].x - myPoint[j].x) * (myPoint[i].x - myPoint[j].x)
					+ (myPoint[i].y - myPoint[j].y) * (myPoint[i].y - myPoint[j].y);
				if (temp < result) result = temp;
			}
	}
	else {
		int midLine = (myPoint[pointCount / 2 - 1].x + myPoint[pointCount / 2].x) / 2;
		int leftMin = minDist(myPoint, pointCount / 2);
		int rightMin = minDist(myPoint + pointCount / 2, pointCount - pointCount / 2);
		result = leftMin > rightMin ? rightMin : leftMin;

		Point* adjPoint = (Point*)malloc(sizeof(Point) * pointCount);
		int idx = 0;
		for (int i = 0; i < pointCount; i++) {
			int lineToDot = myPoint[i].x - midLine;
			if (lineToDot * lineToDot < result) {
				adjPoint[idx++] = myPoint[i];
			}
		}
		qsort(adjPoint, idx, sizeof(Point), cmpy);

		for (int i = 0; i < idx-1; i++)
		{
			int ydist;
			for (int j = i + 1; j < idx; j++)
			{
				ydist = (adjPoint[i].y - adjPoint[j].y)*(adjPoint[i].y - adjPoint[j].y);
				if (ydist < result)
				{
					int temp = ydist + (adjPoint[i].x - adjPoint[j].x)*(adjPoint[i].x - adjPoint[j].x);
					if (temp < result) result = temp;
				}
				else break;
			}
		}

		free(adjPoint);
	}

	return result;
}


int main(void) {
	int pointCount;
	scanf("%d", &pointCount);

	Point* myPoint = (Point*)malloc(sizeof(Point) * pointCount);
	for (int i = 0; i < pointCount; i++) {
		scanf("%d %d", &myPoint[i].x, &myPoint[i].y);
	}

	qsort(myPoint, pointCount, sizeof(Point), cmpx);

	printf("%d", minDist(myPoint, pointCount));

	
	return 0;
}


/*
5 
0 0 
0 0 
0 8 
1 4 
2 7
*/