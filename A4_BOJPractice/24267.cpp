//https://www.acmicpc.net/problem/24267

/* 알고리즘 수업 - 알고리즘의 수행 시간 6 (Bronze 2)
Solution :
입력의 크기 n일때,
수행 횟수는 (n-2) + (n-1) + ... + 1 + (n-3) + (n-2) + ... + 1 + ...
= sum of i(i+1)/2 for i in range(1, n-1) 에 해당된다.
시간복잡도는 3차임.
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

	long long op = 0;
	for (long long i = 1; i <= inputsize - 2; i++)
		op += i * (i + 1) / 2;
	cout << op << '\n' << 3;

	return 0;
}


