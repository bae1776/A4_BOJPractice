//https://www.acmicpc.net/problem/10101

/* �ﰢ�� �ܿ�� (Bronze 4)
Solution : ����, ���ǹ�
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

	int sum = a + b + c;

	if (sum != 180)
		cout << "Error";
	else if (a == b && b == c)
		cout << "Equilateral";
	else if (a == b || b == c || a == c)
		cout << "Isosceles";
	else
		cout << "Scalene";

	return 0;
}


