//https://www.acmicpc.net/problem/16430

//제리와 톰
//대회 링크 : https://www.acmicpc.net/category/detail/1949
//제리가 1kg 치즈 중에 A/Bkg 훔쳤다.
//남은 치즈는?

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	cout << b-a << ' ' << b;


	return 0;
}