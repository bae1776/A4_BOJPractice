//https://www.acmicpc.net/problem/2751

//nlogn 정렬 알고리즘만을 사용하여 정렬해보자.
//(문제 풀이는 힙 정렬 사용)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int hipchanger(int *befarray, int *aftarray, int parent) {
	if (*befarray < *aftarray) {
		int temp = *befarray;
		*befarray = *aftarray;
		*aftarray = temp;
	}
	return parent;
}


void hsort(int arrayh[], int arraynum) {
	int *temparray = (int *)calloc(arraynum + 1, sizeof(int));
	temparray[0] = arrayh[0];
	for (int i = 1; i < arraynum; i++) {
		temparray[i] = arrayh[i];
		int j = i;
		while (hipchanger(&temparray[(j - 1) / 2], &temparray[j], (j - 1) / 2)) j = (j - 1) / 2;
	}
	temparray[arraynum] = -1000001;

	//array 대입단계

	for (int k = arraynum - 1; k >= 1; k--) {
		arrayh[k] = temparray[0];
		temparray[0] = temparray[k];
		temparray[k] = -1000001;
		int i = 0;
		int larger = (temparray[1] > temparray[2]) ? 1 : 2;
		while (hipchanger(&temparray[i], &temparray[larger], larger)) {
			if (larger * 2 <= k - 1) {
				i = larger;
				larger = (temparray[2 * i + 1] > temparray[2 * i + 2]) ? 2 * i + 1 : 2 * i + 2;
			}
			else break;
		}
	}
	arrayh[0] = temparray[0];

	free(temparray);

}


int main() {
	int testcase;
	scanf("%d", &testcase); //1. 자료 갯수를 입력 후 Enter.

	int *arbnum = (int *)malloc(sizeof(int) * testcase);

	for (int i = 0; i < testcase; i++) {
		scanf("%d", &arbnum[i]); //2. 공백 혹은 행 단위로 자료를 입력해주세요.
	}

	hsort(arbnum, testcase); //정렬할 배열, 배열의 갯수, (오름차순 sort)

	for (int i = 0; i < testcase; i++) {
		printf("%d\n", arbnum[i]);
	}
	free(arbnum);
}

//             0
//        1          2
//     3    4     5     6
//    7 8 9  10 11 12 13 14
//

//arraynum = 9, 10    i = 4까지만
//arraynum = 11,12    i = 5까지만