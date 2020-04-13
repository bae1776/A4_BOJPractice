//https://www.acmicpc.net/problem/13159

//Diamond 3 : 배열 가지고 놀기
//문제가 길어서 링크를 참조한다.

//배열 삽입 탐색 삭제인데,
//이 세 과정 모두 O(logn) 이하의 시간 복잡도를 가져야 풀 수 있는 문제이다.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flipArray(int* start_pos, int arrlen) {
	for (int i = 0; i < arrlen / 2; i++) {
		int temp = start_pos[i];
		start_pos[i] = start_pos[arrlen - 1 - i];
		start_pos[arrlen - 1 - i] = temp;
	}
}

void printmMSum(int* start_pos, int arrlen) {
	int max, min, sum;
	max = min = sum = start_pos[0];

	for (int i = 1; i < arrlen; i++) {
		if (start_pos[i] > max) max = start_pos[i];
		if (start_pos[i] < min) min = start_pos[i];
		sum += start_pos[i];
	}

	printf("%d %d %d\n", min, max, sum);
}

int main(void) 
{
	int arrlen, query;
	scanf("%d %d", &arrlen, &query);

	int* arr = (int*)malloc(sizeof(int) * (arrlen + 1));
	for (int i = 0; i <= arrlen; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < query; i++) {
		int order;
		scanf("%d", &order);

		if (order == 1) {
			int start_pos, end_pos;
			scanf("%d %d", &start_pos, &end_pos);
			int subArrlen = end_pos - start_pos + 1;
			flipArray(arr + start_pos, subArrlen);
			printmMSum(arr + start_pos, subArrlen);
			
		}
		else if (order == 2) {
			int start_pos, end_pos, shift;
			scanf("%d %d %d", &start_pos, &end_pos, &shift);
			int subArrlen = end_pos - start_pos + 1;
			printmMSum(arr + start_pos, subArrlen);

			if (shift < 0) shift += subArrlen;
			else if (shift == 0) continue;

			int* tempArr = (int*)malloc(sizeof(int) * shift);
			memcpy(tempArr, arr + end_pos - shift + 1, sizeof(int) * shift);
			for (int i = end_pos; i >= start_pos + shift; i--) {
				arr[i] = arr[i - shift];
			}
			memcpy(arr + start_pos, tempArr, sizeof(int) * shift);
			free(tempArr);
		}
		else if (order == 3) {
			int idx;
			scanf("%d", &idx);
			printf("%d\n", arr[idx]);
		}
		else if (order == 4) {
			int find;
			scanf("%d", &find);
			for (int i = 1; i <= arrlen; i++) {
				if (arr[i] == find) {
					printf("%d\n", i);
					break;
				}
			}
		}
	}

	for (int i = 1; i <= arrlen; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}



//
//printf("현재 배열 : ");
//for (int i = 1; i <= arrlen; i++)
//{
//	printf("%d ", arr[i]);
//}
//printf("\n");
