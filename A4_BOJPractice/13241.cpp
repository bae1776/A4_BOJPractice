//https://www.acmicpc.net/problem/13241

/* 최소공배수 (Silver 5)
Solution : 유클리드 호제법과 혼합
*/

#include <set>
#include <string>
#include <iostream>
using namespace std;


long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long a, b;
	cin >> a >> b;
	cout << a * b / gcd(a, b);

	return 0;
}


