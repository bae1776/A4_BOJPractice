//https://www.acmicpc.net/problem/2775

//규칙 찾기 문제 (계차 수열 + 등차)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int humans[15][15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, };
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int k = 1; k <= j; k++) {
				humans[i][j] += humans[i - 1][k];
			}
		}
	}

	int testcase;
	scanf("%d", &testcase);


	for (int i = 0; i < testcase; i++) {
		int layer, div;
		scanf("%d ", &layer);
		scanf("%d", &div);
		printf("%d\n", humans[layer][div]);
	}
}




// 1 3 6 10 ...
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14
