//https://www.acmicpc.net/problem/13909

/* 창문 닫기 (Silver 5)
Solution : n^2 꼴의 정수만 창문이 열린 상태가 된다.
K번 창문은 K의 약수 개수만큼 열고 닫는 작업을 하는데, 열고 닫는 작업을 홀수번해야 창문이 열린 상태가 된다.
그러한 K는 n^2 꼴만 존재한다. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double input;
	cin >> input;
	cout << (int)sqrt(input);

	return 0;
}
