//https://www.acmicpc.net/problem/5073

/* 삼각형과 세 변 (Bronze 3)
Solution : 수학, 조건문
*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) break;

		int longest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
		if (a + b + c - longest <= longest)
			cout << "Invalid\n";
		else if (a == b && b == c)
			cout << "Equilateral\n";
		else if (a == b || b == c || a == c)
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}

	return 0;
}


