//https://www.acmicpc.net/problem/1541

//������ ������ �ִ� ������ �ִ�. (���̴� �ִ� 50)
//�� ���Ŀ� ��ȣ�� �ļ� �� ���� ���� �ּҷ� ���� ��, �� �ּҰ��� ����Ͻÿ�.
//���� ���ڿ� �������� �־�����, ���� 0���� ������ �� �ִ�.
//+ 5�ڸ� �̻� ���ڴ� ������ �ʴ´�.


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