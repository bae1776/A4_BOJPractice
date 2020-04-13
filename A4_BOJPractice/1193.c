//https://www.acmicpc.net/problem/1193

//분수 찾기 (패턴 찾기)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int order;
	scanf("%d", &order);

	int upline = 1;
	int dwline = 1;

	for (int i = 1; i < order; i++) {
		switch ((upline + dwline) % 2) {
		case 0:
			if (upline == 1) dwline++;
			else {
				upline--; dwline++;
			}
			break;
		case 1:
			if (dwline == 1) upline++;
			else {
				dwline--; upline++;
			}
		}
	}

	printf("%d/%d", upline, dwline);
}