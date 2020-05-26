//https://www.acmicpc.net/problem/4796

//캠핑
//김강산과 가족들이 함께 캠핑을 떠났다. 하지만, 캠핑장에는 다음과 같은 경고문이 쓰여 있었다.
//캠핑장은 연속하는 P일 중 L일 동안만 사용할 수 있습니다.
//김강산 씨는 이제 막 V일 휴가를 시작했다. 이번 휴가 기간 동안 강산이는 캠핑장을 며칠 동안 사용할 수 있을까?

//입력은 L P V로 주어진다.

#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int permitted, interval, vacation;
	int caseOrder = 1;

	while (true)
	{
		cin >> permitted >> interval >> vacation;
		if (permitted == 0) 
			break;

		int fullCycle = vacation / interval;
		int leftCycle = vacation % interval;

		cout << "Case " << caseOrder++ << ": " <<
			fullCycle * permitted + [](int a, int b) {return a > b ? b : a; } (permitted, leftCycle) << '\n';
	}


	return 0;
}