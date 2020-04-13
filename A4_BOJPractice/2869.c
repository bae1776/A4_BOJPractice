//https://www.acmicpc.net/problem/2869

//달팽이는 올라가고 싶다
//하루에 a만큼 올라갔다 b만큼 미끄러지는 달팽이가 있다. c만큼 올라오는 데 걸리는 날(정수)을 출력하시오.
//입력 : a b c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int up, down, goal;
	scanf("%d %d %d", &up, &down, &goal);


	if (goal <= down + 1) {
		printf("1");
	}
	else {
		printf("%d", (goal - down - 1) / (up - down) + 1);
	}


	return 0;
}