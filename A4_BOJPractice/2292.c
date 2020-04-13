//https://www.acmicpc.net/problem/2292

//벌집 (계차수열 이해 문제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int add;
	scanf("%d", &add);
	int gap = 6;
	int arraynum = 1;
	int min_room = 1;

	while (1) {
		if (add > arraynum) {
			min_room++;
			arraynum += gap;
			gap += 6;
		} 
		else break;
	}

	printf("%d", min_room);

}