//https://www.acmicpc.net/problem/2587

/* 대표값2 (Bronze 2)
Solution : 정렬
*/

#include <algorithm>
#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int input[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> input[i];
		sum += input[i];
	}

	sort(input, input + 5);

	cout << sum / 5 << '\n' << input[2];

	return 0;
}


