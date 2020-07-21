//https://www.acmicpc.net/problem/10164

//격자상의 경로
//어렵지 않은 경우의 수 문제

#include <iostream>
using namespace std;

long long factorial(int num, int divnum = 1);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col, viaNumber;
	cin >> row >> col >> viaNumber;


	int via_x = (viaNumber - 1) % col; //Start to 0
	int via_y = (viaNumber - 1) / col; 


	long long result;

	if (viaNumber != 0)
		result = factorial(via_x + via_y, via_x) / factorial(via_y)
		* factorial(col - via_x + row - via_y - 2, col - via_x - 1) / factorial(row - via_y - 1);
	else
		result = factorial(row + col - 2, row - 1) / factorial(col - 1);

	cout << result;


	return 0;
}


long long factorial(int num, int divnum)
{
	long long result = 1;

	for (int i = num; i > divnum; i--)
		result *= i;

	return result;
}