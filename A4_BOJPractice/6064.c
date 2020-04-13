//https://www.acmicpc.net/problem/6064

//Ä«À× ´Þ·Â

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Uclead(int *A, int *B);

int main() {
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		int L, R, l, r;
		scanf("%d %d %d %d", &L, &R, &l, &r);

		int RL = L; int RR = R;
		int Cfactor = L * R;

		while (L != 0 && R != 0) {
			Uclead(&L, &R);
		}
		Cfactor /= (L > R) ? L : R;
		
		int varl = l;
		int varr = r;
		int conclusion = 0;

		while (varl <= Cfactor && varr <= Cfactor) {
			if (varl == varr) {
				conclusion = varl;
				break;
			}
			else {
				if (varl > varr) varr += RR; 
				else varl += RL;
			}
		}
		if (conclusion == 0) conclusion--;
		
		printf("%d\n", conclusion);

	}
}

void Uclead(int *A, int *B) {
	int temp = (*A > *B) ? *B  : *A;
	*B = (*A > *B) ? (*A) % (*B) : (*B) % (*A);
	*A = temp;
}


// 3 13 23 33 43 53 ...
// 9 21 33 45 57 69 ...