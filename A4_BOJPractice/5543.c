//https://www.acmicpc.net/problem/5543

//��ٳ���

/*
��ٳ��忡�� ���� �� �ȸ��� �޴��� ��Ʈ �޴��̴�. 
�ֹ��� ��, �ڽ��� ���ϴ� �ܹ��ſ� ���Ḧ �ϳ��� ��� ��Ʈ�� �����ϸ�, ���� �տ��� 50���� ���εȴ�.
�ܹ��Ŵ� �� 3���� �������, �ߴ�����, �ϴ����Ű� �ְ�, ����� �ݶ�� ���̴� �� ������ �ִ�.
�ܹ��ſ� ������ ������ 5�ٿ� ���� �־����� ��, ���� �� ��Ʈ �޴��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int cheapBurger = 10000000;
	for (int i = 0; i < 3; i++)
	{
		int input;
		scanf("%d", &input);
		if (input < cheapBurger) cheapBurger = input;
	}

	int cheapDrink = 10000000;
	for (int i = 0; i < 2; i++)
	{
		int input;
		scanf("%d", &input);
		if (input < cheapDrink) cheapDrink = input;
	}

	printf("%d", cheapBurger + cheapDrink - 50);


	return 0;
}


