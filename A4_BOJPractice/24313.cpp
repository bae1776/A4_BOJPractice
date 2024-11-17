//https://www.acmicpc.net/problem/24313

/* 알고리즘 수업 - 점근적 표기 1 (Silver 5)
Solution :
O(n) 정의의 만족 조건 두 가지 (모두 만족해야함)
1. n = n0에서 f(n) <= c*g(n) 이다.
2. f(n)의 일차항 계수가 c보다 작거나 같다. (n이 매우 커질때 부등식 만족 조건)

*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	cout << ((a1 * n0 + a0 <= c * n0) && (a1 <= c));

	return 0;
}


