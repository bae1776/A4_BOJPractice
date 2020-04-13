//https://www.acmicpc.net/problem/1085

//직사각형 탈출
//한수는 (x,y)에 있고 직사각형의 왼쪽 하단 꼭짓점은 (0,0), 오른쪽 상단 꼭짓점은 (w,h)에 있다. 
//한수와 직사각형 경계선과의 최소 거리(정수)를 출력하시오
//입력 : x y w h

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int my_x, my_y, rect_x, rect_y;
	scanf("%d %d %d %d", &my_x, &my_y, &rect_x, &rect_y);

	int xmin = (my_x > rect_x - my_x) ? rect_x - my_x : my_x;
	int ymin = (my_y > rect_y - my_y) ? rect_y - my_y : my_y;

	printf("%d", xmin < ymin ? xmin : ymin);
}