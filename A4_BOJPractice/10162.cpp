//https://www.acmicpc.net/problem/10162

//전자레인지
//전자레인지에 시간을 조절할 수 있는 5분, 1분, 10초 버튼 3개가 있다.
//해당 버튼을 누를 때마다 그 시간이 동작시간에 더해진다.
//요리시간(초)이 주어질 때 버튼 누르는 횟수를 최소로 할때,
//각 버튼을 눌러야 하는 횟수를 구하시오.


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int time;
	cin >> time;

	int A, B, C;

	A = time / 300;
	time %= 300;
	B = time / 60;
	time %= 60;
	C = time / 10;
	time %= 10;

	if (time == 0)
	{
		cout << A << ' ' << B << ' ' << C;
	} else {
		cout << -1;
	}
	return 0;
}
