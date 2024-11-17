//https://www.acmicpc.net/problem/2485

/* 가로수 (Silver 4)
Solution :
인접한 배열 값 간의 차들의 최대공약수를 구한다.
*/

#include <set>
#include <string>
#include <iostream>
using namespace std;

int diff[100004];

int gcd(int a, int b)
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

	int cnt, first;
	cin >> cnt >> first;

	int second, gcdval = 0;
	for (int i = 1; i < cnt; i++)
	{
		cin >> second;
		diff[i] = second - first;
		gcdval = gcd(diff[i], gcdval);
		first = second;
	}

	int ans = 0;
	for (int i = 1; i < cnt; i++)
		ans += diff[i] / gcdval - 1;

	cout << ans;

	return 0;
}


