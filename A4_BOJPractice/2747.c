//https://www.acmicpc.net/problem/2747

//�Ǻ���ġ ��
//n��° �Ǻ���ġ ���� ����Ͻÿ�. (n <= 45)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int fib(int input) { //input <= 45
	int arr[46] = { 0, 1 };
	for (int i = 2; i <= input; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[input];
	
}



int main(void)
{
	int input;
	scanf("%d", &input);
	printf("%d", fib(input));
	return 0;
}
