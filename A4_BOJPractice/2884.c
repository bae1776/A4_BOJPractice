//https://www.acmicpc.net/problem/2884

//알람 시계

//상근이는 정시에 알람을 맞추니 맨날 늦어서 정시보다 45분 일찍 알람을 맞추려고 한다. 
//어떻게 맞춰야 하는가?  하루의 시작은 0 0이고 끝은 23 59 이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int hour, min;
	scanf("%d %d", &hour, &min);

	min -= 45;
	if (min < 0) {
		hour--;
		min += 60;
	}
	if (hour < 0) {
		hour += 24;
	}


	printf("%d %d", hour, min);
}