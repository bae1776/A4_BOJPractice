//https://www.acmicpc.net/problem/1181

//입력 받은 문자열 정렬
//1. 짧은 문자열을 먼저 출력    2. 길이가 같은 문자열은 사전식으로 배열   3. 중복 문자열은 1번만 출력함.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
	char word[51];
	char length;
} str;

int compare(const void *a, const void *b) { //여기를 주목 - string.length만을 기준으로 정렬하는 compare 함수
	str *pa = (str *)a;
	str *pb = (str *)b;
	return pa->length - pb->length;
}

int compare2(const void *a, const void *b) {
	str *pa = (str *)a;
	str *pb = (str *)b;
	return strcmp(pa->word, pb->word);
}

int main() {
	int testcase;
	scanf("%d", &testcase);

	str *strs = malloc(sizeof(str) * testcase);

	for (int i = 0; i < testcase; i++) {
		scanf("%s", (strs+i)->word);
		(strs + i)->length = strlen((strs + i)->word);
	}

	qsort(strs, testcase, sizeof(strs[0]), compare);
	
	for (int i = 0; i < testcase;) {
		int targetnum = 1;
		for (int j = 1; j + i < testcase; j++) {
			if (strs->length == (strs+j)->length) targetnum++;
			else break;
		}
		if (targetnum == 1) printf("%s\n", (strs)->word); 
		else {
			qsort(strs, targetnum, sizeof(strs[0]), compare2);
			for (int j = 0; j < targetnum; j++) {
				if (strcmp((strs+j)->word, (strs+j+1)->word)) printf("%s\n", (strs + j)->word);
			}
		}
		i += targetnum;
		strs += targetnum;
	}

}