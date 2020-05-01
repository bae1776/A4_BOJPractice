//https://www.acmicpc.net/problem/1003

//n을 입력받아 n번째 피보나치 수를 재귀적으로 구할 때, fib(0), fib(1)이 호출되는 횟수를
//먼저 입력받은 테스트 케이스 갯수만큼 각각 출력하시오.


#include <iostream>
#include <utility>
#include <array>

using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b)
{
	return pair<int, int>(a.first + b.first, a.second + b.second);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	array<pair<int, int>, 41> fiboCall;
	fiboCall[0] = make_pair(1, 0);
	fiboCall[1] = make_pair(0, 1);


	int testcase;
	cin >> testcase;

	int max = 1;

	for (int i = 0; i < testcase; i++)
	{
		int input;
		cin >> input;

		if (input > max)
		{
			for (int j = max + 1; j <= input; j++)
			{
				fiboCall[j] = fiboCall[j - 2] + fiboCall[j - 1];
			}
			max = input;
		}

		std::cout << fiboCall[input].first << ' ' << fiboCall[input].second << '\n';
	}


	return 0;

}