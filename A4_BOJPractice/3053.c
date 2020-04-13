//https://www.acmicpc.net/problem/3053

//택시 기하학
//반지름 R에 대한, 유클리드 기하학에서의 원 넓이, 택시 기하학에서의 원 넓이를 한 줄씩 출력하시오.
//(실 정답과의 오차는 0.0001까지 허용)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
	int radius;
	scanf("%d", &radius);

	printf("%.6lf\n", radius * radius * pi);
	printf("%d.000000", radius * radius * 2);
}

