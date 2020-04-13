//https://www.acmicpc.net/problem/1541

//덧셈과 뺄셈만 있는 수식이 있다. (길이는 최대 50)
//이 수식에 괄호를 쳐서 이 식의 값을 최소로 만들 때, 그 최소값을 출력하시오.
//식은 문자열 형식으로 주어지고, 수는 0으로 시작할 수 있다.
//+ 5자리 이상 숫자는 나오지 않는다.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char operstr[51];

int tointeger(int start_pos) {
	int sum = 0;
	while (operstr[start_pos] >= '0' && operstr[start_pos] <= '9') {
		sum = sum * 10 + (operstr[start_pos] - '0');
		start_pos++;
	}
	return sum;
}

int main(void) {
	int operatoridx[25];
	int operatoridxlen = 0;
	scanf("%s", operstr);

	char minusflag = 0;
	for (int i = 0; i < (int)strlen(operstr); i++) {
		if (operstr[i] == '+')
		{
			operatoridx[operatoridxlen++] = i;
			if (minusflag) operstr[i] = '-';
		}
		else if (operstr[i] == '-') {
			operatoridx[operatoridxlen++] = i;
			if (minusflag == 0) minusflag = i;
		}
	}

	int sum = tointeger(0);
	for (int i = 0; i < operatoridxlen; i++) {
		switch (operstr[operatoridx[i]]) {
		case '+':
			sum += tointeger(operatoridx[i] + 1);
			break;
		case '-':
			sum -= tointeger(operatoridx[i] + 1);
			break;
		}
	}

	printf("%d", sum);
	
}