//https://www.acmicpc.net/problem/11966

//2의 제곱인가?
//2의 제곱이면 1 아니면 0을 출력하시오

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long num;
	bool is2square = true;
	cin >> num;

	while (num >= 2)
	{
		if (num % 2 == 1)
		{
			is2square = false;
			break;
		}
		else
			num /= 2;
	}

	cout << is2square;


	return 0;
}