//https://www.acmicpc.net/problem/10870

//��͸� ����Ͽ� �Ǻ���ġ ���� ��������.

#include <stdio.h>

int fibbonachi(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return fibbonachi(num - 2) + fibbonachi(num - 1);
}
int main(void)
{
	int input;
	scanf("%d", &input);
	printf("%d", fibbonachi(input));
	return 0;
}