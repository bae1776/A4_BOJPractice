//https://www.acmicpc.net/problem/14215

/* 세 막대 (Bronze 3)
Solution : 수학, 조건문
*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	int longest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

	if (a + b + c - longest > longest)
		cout << a + b + c;
	else
		cout << (a + b + c - longest) * 2 - 1;

	return 0;
}


