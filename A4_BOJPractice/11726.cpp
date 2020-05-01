//https://www.acmicpc.net/problem/11726

//2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int DP[1001] = { 0, 1, 2 };

	int input;
	cin >> input;

	for (int i = 3; i <= input; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}


	cout << DP[input];
	


	return 0;
}