//https://www.acmicpc.net/problem/1373

//2진수를 8진수로 변환하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000002];
	int strptr = 0;
	char result[500000];
	int resptr = 0;
	scanf("%s", str);

	int len = strlen(str);

	switch (len % 3) {
	case 0:
		break;
	case 1:
		result[resptr++] = str[0] - '0';
		strptr = 1;
		break;
	case 2:
		result[resptr++] = (str[0] - '0') * 2 + str[1] - '0';
		strptr = 2;
		break;
	}

	while (strptr < len) {
		result[resptr++] = (str[strptr] - '0') * 4 + (str[strptr + 1] - '0') * 2 + (str[strptr + 2] - '0');
		strptr += 3;
	}

	for (int i = 0; i < resptr; i++) {
		printf("%d", result[i]);
	}

}
