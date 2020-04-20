//https://www.acmicpc.net/problem/17496

//스타후르츠를 재배하자
//재배 가능 기간, 재배 소요 기간, 재배 가능 칸, 개당 수익이 주어질 때
//얼마를 벌 수 있을지 구하시오.


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int totalDay, perDay, size, price;
	cin >> totalDay >> perDay >> size >> price;

	int totalFruits = (totalDay - 1) / perDay * size;

	cout << totalFruits * price;


	return 0;
}