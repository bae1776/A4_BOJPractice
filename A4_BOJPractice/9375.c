//https://www.acmicpc.net/problem/11051

//패션왕 신해빈
//문제가 너무 길어 링크 참조

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char type[21];
	int count;
} Wear;

int main(void) {
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		int wear_count;
		scanf("%d", &wear_count);

		Wear* myWear = (Wear*)malloc(sizeof(Wear) * wear_count);
		int wearlen = 0;

		for (int i = 0; i < wear_count; i++) {
			char wearName[21]; char wearType[21];
			scanf("%s %s", wearName, wearType);

			char flag = 0;
			for (int j = 0; j < wearlen; j++) {
				if (strcmp(myWear[j].type, wearType) == 0) {
					myWear[j].count++;
					flag = 1; break;
				}
			}
			if (!flag) {
				myWear[wearlen].count = 1;
				strcpy(myWear[wearlen++].type, wearType);
			}
		}

		int sum = 1;
		for (int i = 0; i < wearlen; i++) {
			sum *= (myWear[i].count + 1);
		}

		printf("%d\n", sum - 1);

		free(myWear);
	}


	return 0;
}