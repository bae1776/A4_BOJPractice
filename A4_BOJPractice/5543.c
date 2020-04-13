//https://www.acmicpc.net/problem/5543

//상근날드

/*
상근날드에서 가장 잘 팔리는 메뉴는 세트 메뉴이다. 
주문할 때, 자신이 원하는 햄버거와 음료를 하나씩 골라 세트로 구매하면, 가격 합에서 50원이 할인된다.
햄버거는 총 3종류 상덕버거, 중덕버거, 하덕버거가 있고, 음료는 콜라와 사이다 두 종류가 있다.
햄버거와 음료의 가격이 5줄에 거쳐 주어졌을 때, 가장 싼 세트 메뉴의 가격을 출력하는 프로그램을 작성하시오.
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


