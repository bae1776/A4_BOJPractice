//https://www.acmicpc.net/problem/1049

//기타줄
//기타에서 N개의 줄이 끊어져서 새로운 줄을 사서 교체해야 한다.
//M개의 기타줄 브랜드에서 6줄 패키지 혹은 낱개 줄로 기타줄을 판매한다.

//각 기타줄 브랜드의 6줄 패키지와 낱개 가격이 주어지고,
//되도록이면 돈을 적게 쓰려고 할때, 금액 최소를 구하시오.


#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int required, brand;
	cin >> required >> brand;

	int minPackage = 0x7FFFFFFF;
	int minUnit = 0x7FFFFFFF;


	for (int i = 0; i < brand; i++)
	{
		int packagePrice, unitPrice;
		cin >> packagePrice >> unitPrice;

		if (packagePrice < minPackage) minPackage = packagePrice;
		if (unitPrice < minUnit) minUnit = unitPrice;
	}


	int result = (required / 6) * min(minPackage, minUnit * 6)
			   + min(minPackage, minUnit * (required % 6));


	cout << result;



	return 0;
}