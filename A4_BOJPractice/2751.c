//https://www.acmicpc.net/problem/2751

//nlogn ���� �˰����� ����Ͽ� �����غ���.
//(���� Ǯ�̴� �� ���� ���)

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

	//array ���Դܰ�

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
	scanf("%d", &testcase); //1. �ڷ� ������ �Է� �� Enter.

	int *arbnum = (int *)malloc(sizeof(int) * testcase);

	for (int i = 0; i < testcase; i++) {
		scanf("%d", &arbnum[i]); //2. ���� Ȥ�� �� ������ �ڷḦ �Է����ּ���.
	}

	hsort(arbnum, testcase); //������ �迭, �迭�� ����, (�������� sort)

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

//arraynum = 9, 10    i = 4������
//arraynum = 11,12    i = 5������