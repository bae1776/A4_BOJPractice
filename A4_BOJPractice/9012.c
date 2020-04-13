//https://www.acmicpc.net/problem/9012

//유효한 괄호 찾기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		char vps[51] = { 0 };
		scanf("%s", vps);
		int validity = 0;
		for (int j = 0; vps[j] != 0; j++) {
			if (vps[j] == '(') validity++;
			else if (vps[j] == ')') validity--;

			if (validity < 0) break;
		}

		if (validity) printf("NO\n");
		else printf("YES\n");
	}

}

