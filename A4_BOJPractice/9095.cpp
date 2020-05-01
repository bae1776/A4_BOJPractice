//https://www.acmicpc.net/problem/9095

//정수 1 ~ 10을 1, 2, 3의 합 꼴로 나타낼 수 있는 갯수를 구하시오.

#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int DP[11] = { 0, 1, 2, 4 };

	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int input;
		cin >> input;

		if (DP[input] == 0)
		{
			for (int i = 4; i <= input; i++)
			{
				DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
			}
		}

		cout << DP[input] << '\n';
	}

	return 0;
}