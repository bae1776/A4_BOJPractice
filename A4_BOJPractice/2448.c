//https://www.acmicpc.net/problem/2448

//특이한 별 피라미드 만들기
//3*2^n 꼴만 정상 동작 (n >= 0)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int input;
	scanf("%d", &input);
	char element;
	char *arr = &element;
	char **doublearr;

	doublearr = (char **)malloc(sizeof(char*) * input);
	for (int i = 0; i < input; i++) {
		doublearr[i] = (char *)malloc(sizeof(char) * input * 2);
	}

	for (int y = 0; y < input; y++) {
		for (int x = 0; x < input * 2; x++) doublearr[y][x] = ' ';
	}
	doublearr[0][0] = '*';

	for (int y = 0; y < input - 1; y++) {
		for (int x = 0; x < 6 * ((y / 3) + 1); x += 6) {
			if (doublearr[y][x] == '*' && doublearr[y][x + 1] == '*') { //별 5연속
				doublearr[y + 1][x] = '*';
				int contin = 6;
				for (; ; contin += 6) {
					if (doublearr[y][x + contin] == '*') continue;
					else break;
				}
				doublearr[y + 1][x + contin] = '*';
				x += (contin - 6);

			}
			else if (doublearr[y][x] == '*' && doublearr[y][x + 2] == ' ') { //별 홀로
				doublearr[y + 1][x] = '*'; doublearr[y + 1][x + 2] = '*';
			}
			else if (doublearr[y][x] == '*' && doublearr[y][x + 2] == '*') {//2쌍
				doublearr[y+1][x] = '*'; doublearr[y+1][x + 1] = '*'; doublearr[y+1][x + 2] = '*';
				doublearr[y+1][x + 3] = '*'; doublearr[y+1][x + 4] = '*'; 
			}
		}
	}

	for (int y = 0; y < input; y++) {
		for (int blank = input - y; blank > 1; blank--) {
			printf(" ");
		}
		for (int x = 0; x < input * 2 +y-input+1; x++) {
			printf("%c", doublearr[y][x]);
		}
		printf("\n");
	}


	
	for (int i = 0; i < input; i++) {
		free(doublearr[i]);
	}
	free(doublearr);

	return 0;
}


/*

*     
* *   
*****
*     *
* *   * *
***** *****
*           *
* *         * *
*****       *****
*     *     *     *
* *   * *   * *   * *
***** ***** ***** *****
*                       *
* *                     * *
*****                   *****
*     *                 *     *
* *   * *               * *   * *
***** *****             ***** *****
*           *           *           *
* *         * *         * *         * *
*****       *****       *****       *****
*     *     *     *
* *   * *   * *   * *
***** ***** ***** ***** ***** ***** ***** *****


*/