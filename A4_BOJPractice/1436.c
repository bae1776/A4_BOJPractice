//https://www.acmicpc.net/problem/1436

//666이 포함된 숫자를 종말의 수라고 하자.
//n번째 종말의 수를 출력하는 문제
//입력 : n

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char terminal[9] = { '0', '0', '0', '0', '0', '6', '6', '5', '\0' };
	int order;
	scanf("%d", &order);

	int now_order = 0;

	while (now_order < order)
	{
		terminal[7]++;
		for (int i = 7; i > 0; i--)
		{
			if (terminal[i] > '9') {
				terminal[i - 1]++;
				terminal[i] = '0';
			}
			else break;
		}

		for (int i = 0; i <= 8 - 3; i++)
		{
			if (terminal[i] == '6' && terminal[i + 1] == '6' && terminal[i + 2] == '6')
			{
				now_order++;
				break;
			}
		}
	}

	printf("%d", atoi(terminal));


	return 0;
}