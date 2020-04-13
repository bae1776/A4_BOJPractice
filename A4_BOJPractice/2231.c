//https://www.acmicpc.net/problem/2231

//입력된 자연수의 가장 큰 생성자를 구하는 문제.
//생성자 : 216 = 198 + 1 + 9 + 8를 만족시킬때, 198은 216의 생성자라고 한다.
//생성자가 없는 경우 0 출력.

#include <stdio.h>

int diSum(int number, int target)
{
	int result = number;
	int tempnum = number;
	int judge = number;

	while (tempnum != 0)
	{
		judge += tempnum % 10;
		tempnum /= 10;
	}

	return (judge == target) ? number : 0;
}


int main(void)
{
	int num;
	scanf("%d", &num);

	int result = 0;
	

	for (int i = num - 54; i < num; i++)
	{
		if (i >= 1 && (result = diSum(i, num))) break;
	}

	printf("%d", result);
	
	return 0;
}


