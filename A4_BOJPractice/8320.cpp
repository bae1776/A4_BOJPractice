//https://www.acmicpc.net/problem/8320

//직사각형을 만드는 방법
//길이가 1인 정사각형이 n개 있을 때, 서로 다른 직사각형을 몇 개나 만들 수 있을까?

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int unitSquare;
	cin >> unitSquare;

	int total = 0;

	for (int row = 1; row * row <= unitSquare; row++)
		total += unitSquare / row - (row - 1);
	
	cout << total;


	return 0;
}