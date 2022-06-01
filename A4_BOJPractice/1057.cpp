//https://www.acmicpc.net/problem/1057

/* 토너먼트 (Silver 3)

김지민은 N명이 출전하는 토너먼트에 진출했다.
토너먼트는 참가자 별로 1~N까지 매겨서 1 vs 2 / 3 vs 4 ... 로 대결을 하여 이긴 쪽이
다음 라운드에 진출하고 번호는 처음 번호의 순서를 유지하며 다시 1번부터 매긴다.
그리고 만약 라운드에 홀수 인원이 남아있다면, 마지막 번호는 부전승한다.

마침 이 대회에 임한수도 출전하는데, 김지민, 임한수가 모든 경기에서 이긴다고 가정하고
이 둘이 받은 참가자 번호가 주어질 때 이들이 몇 라운드에서 만날 수 있을지 구하시오.

 
*/


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int participant, num1, num2;

	cin >> participant >> num1 >> num2;

	int round = 0;

	while (num1 != num2)
	{
		num1 = (num1 + 1) / 2;
		num2 = (num2 + 1) / 2;
		round++;
	}

	cout << round;

	return 0;
}
