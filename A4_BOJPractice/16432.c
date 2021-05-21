//https://www.acmicpc.net/problem/16432

//떡장수와 호랑이
//대회 링크 : https://www.acmicpc.net/category/detail/1949

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int day;
	scanf("%d", &day);
	int* conclusion = (int*)calloc(day, sizeof(int));
	int** TtokOfDay = (int**)malloc(sizeof(int*) * day);

	for (int i = 0; i < day; i++) {
		int var;
		scanf("%d", &var);
		TtokOfDay[i] = (int*)malloc(sizeof(int) * var + 4);
		TtokOfDay[i][0] = var;
		for (int j = 1; j <= var; j++) {
			scanf("%d", &TtokOfDay[i][j]);
		}
	}

	if (day == 1) {
		printf("%d", TtokOfDay[0][1]);
		return 0;
	}

	char button = 1;

	int redo = 1;
	while (redo) {
		for (int i = 0; i < day; i++) {
			if (TtokOfDay[i][0] == 0 && !conclusion[i]) {
				button = 0; //-1  출력
				break;
			}
			//1개 있으면 앞뒤에 존재하는 같은 숫자 지움
			if (TtokOfDay[i][0] == 1) {
				conclusion[i] = TtokOfDay[i][1];
				TtokOfDay[i][0]--;
				if (i != day - 1) {
					for (int j = 1; j <= TtokOfDay[i + 1][0]; j++) {
						if (TtokOfDay[i][1] == TtokOfDay[i + 1][j]) {

							if (j == TtokOfDay[i + 1][0]) {
								TtokOfDay[i + 1][j] = 0;
								TtokOfDay[i + 1][0]--;
							}
							else {
								TtokOfDay[i + 1][0]--;
								for (int k = j; k <= TtokOfDay[i + 1][0]; k++) {
									TtokOfDay[i + 1][k] = TtokOfDay[i + 1][k + 1];
								}
							}
							break;
						}
					}
				}
				if (i != 0) {
					for (int j = 1; j <= TtokOfDay[i - 1][0]; j++) {
						if (TtokOfDay[i][1] == TtokOfDay[i - 1][j]) {
							if (j == TtokOfDay[i - 1][0]) {
								TtokOfDay[i - 1][j] = 0;
								TtokOfDay[i - 1][0]--;
							}
							else {
								TtokOfDay[i - 1][0]--;
								for (int k = j; k <= TtokOfDay[i - 1][0]; k++) {
									TtokOfDay[i - 1][k] = TtokOfDay[i - 1][k + 1];
								}
							}
							if (TtokOfDay[i - 1][0] == 1) {
								redo = 2;
							}
							break;
						}
					}

				}
			}
		}
		redo--;
		//print(TtokOfDay, conclusion, day);
	}

	if (button == 0) {
		printf("-1");
		return 0;
	}



	for (int i = 0; i < day; i++) {
		if (conclusion[i]) continue;
		for (int j = 1; j <= TtokOfDay[i][0]; j++) {
			if (i >= 1 && i < day - 1) {
				if (TtokOfDay[i][j] != conclusion[i - 1] && TtokOfDay[i][j] != conclusion[i + 1])
				{
					conclusion[i] = TtokOfDay[i][j]; break;
				}
			}
			else if (i == 0) {
				if (TtokOfDay[i][j] != conclusion[i + 1])
				{
					conclusion[i] = TtokOfDay[i][j]; break;
				}
			}
			else if (i == day - 1) {
				if (TtokOfDay[i][j] != conclusion[i - 1])
				{
					conclusion[i] = TtokOfDay[i][j]; break;
				}
			}
		}
	}


	for (int i = 0; i < day; i++) {
		printf("%d\n", conclusion[i]);
	}
}