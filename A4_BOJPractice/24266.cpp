//https://www.acmicpc.net/problem/24266

/* 알고리즘 수업 - 알고리즘의 수행 시간 5 (Bronze 3)
Solution :
입력의 크기 n일때,
수행 횟수는 n^3이고 시간복잡도는 3차임.
int 범위 초과됨에 유의
*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long inputsize;
	cin >> inputsize;

	cout << inputsize * inputsize * inputsize << '\n' << 3;

	return 0;
}


