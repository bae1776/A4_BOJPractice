//https://www.acmicpc.net/problem/2231

//�Էµ� �ڿ����� ���� ū �����ڸ� ���ϴ� ����.
//������ : 216 = 198 + 1 + 9 + 8�� ������ų��, 198�� 216�� �����ڶ�� �Ѵ�.
//�����ڰ� ���� ��� 0 ���.

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


