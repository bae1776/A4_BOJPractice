//https://www.acmicpc.net/problem/17613

/* 점프 (Platinum 2)

개구리가 수직선 위의 0에서 출발해서 오른쪽(x좌표 증가) 방향으로 점프를 수행하여
어떤 수 x에 도달 하려고 한다. 이때, 점프 간격은 1로부터 시작해서 항상 직전 점프 간격의 2배로 증가해야한다.
만일 점프간격을 2배씩 증가시켜 마지막 점프에서 목표 수 x를 지나칠 것 같으면, 다시 처음 상태인 간격 1로 돌아갈 수 있다.

예를 들어 x = 19에 도달하기 위해선 (1+2+4+8)+(1+2)+(1)=19 와 같이 7번의 점프로 도달할 수 있다.
개구리가 0에서 출발해서 어떤 자연수 N에 도달하기 위한 점프 횟수의 최소값을 J(N)이라 하자.

우리는 특정 구간 a, b가 주어질 때 w = max{J(i) | a <= i <= b}를 구해야한다.
그리고 이 값의 범위는 최대 10억이며, 최대 2000회를 1초안에 계산하여라.

*/

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<int, 32> DP = {0, 1,}; //DP[i] = 0 ~ 2^i - 1까지의 max(J)이며, 이는 점화식 DP[i + 1] = DP[i] + i를 만족시킨다.
array<int, 32> twoPow{0, 1,}; //twoPow[i] = 2^i - 1; (-> i번 점프하면 twoPow[i]칸 만큼 전진한다)
int maxJump(const int& a, const int& b); 

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i < 32; i++)
	{
		DP[i] = DP[i - 1] + i - 1;
		twoPow[i] = (twoPow[i-1] << 1) + 1;
	}

	int count;
	cin >> count;

	while (count--)
	{
		int a, b;
		cin >> a >> b;
		cout << maxJump(a, b) << endl;
	}
}

//최대 재귀 깊이 : 기껏해야 30
int maxJump(const int& a, const int& b)
{
	if (b <= 2) return b;

	int left = upper_bound(twoPow.begin(), twoPow.end(), a) - twoPow.begin() - 1;
	int right = upper_bound(twoPow.begin(), twoPow.end(), b) - twoPow.begin() - 1;

	if (left == right)
	{
		return left + maxJump(a - twoPow[left], b - twoPow[left]);
	} else {
		left = right - 1;
		return max(left + DP[left], right + maxJump(0, b - twoPow[right]));
	}

	/* Example
	maxJump(318, 400) 이라 하자.
	그러면 left = right = 9(upper_bound(318/400)) - 1 = 8이다.
	이는 조건 분기에 따라 8 + maxJump(63, 145)를 호출한다. (개구리가 먼저 연속 8번 점프하고 점프 길이 초기화하여 45~145칸을 뛰는 경우)
	maxJump(63, 145) 에 대하여,
	left = 7(upper_bound(63)) - 1 = 6, right = 7이다.
	조건 분기에 따라
	maxJump(63, 145) = max(6 + DP[6], 7 + maxJump(0, 18))
	이때 max의 왼쪽은 개구리가 6번(63칸) 먼저 뛰고, 점프해야할 길이 [0, 63]일때 최대 점프횟수 (=DP[6])
	    max의 오른쪽은 개구리가 7번(127칸) 먼저 뛰고, 점프해야할 길이 [0, 18]일때 최대 점프 횟수 (다시 재귀)

	재귀 종료 조건은 b <= 2일때로, maxJump(0, 0) = 0, maxJump(?, 1) = 1, maxJump(?, 2) = 2는 자명하기 때문이다.
	
	*/
}