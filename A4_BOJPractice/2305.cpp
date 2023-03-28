//https://www.acmicpc.net/problem/2305

/*자리 배치 (Gold 1)

Solution : 수학 + 다이나믹 프로그래밍

함수를 다음과 같이 정의한다.
[1, 2, 3, 4] 와 같이 4명이 자리를 다 채웠을 때 경우의 수를 f(4)라 하자.
이때, f(x) = f(x - 1) + f(x - 2)
f(x - 1)은 swap(1, 2)를 하지 않은 경우, f(x - 2)는 swap(1, 2)를 한 경우이다.

[x, 2, 3, 4] 와 같이 좌석 4개에 가장자리 하나가 비어있을 때 경우의 수를 g(4)라 하자
이때, g(x) = f(x - 1) + g(x - 1)
f(x - 1)은 swap(x, 2)를 하지 않은 경우, g(x - 1)는 swap(x, 2)를 한 경우이다.

[1, 2, x, 4, 5] 와 같이 좌석 5개에 3번째 자리가 비어있을 때 경우의 수를 h(5, 3)이라 하자.
이때, h(x, k) = g(k) * f(x - k) + f(k - 1) * g(x - k) 이다.
g(k) * f(x - k)는 swap(x, 4)를 하지 않은 경우, f(k - 1) * g(x - k)는 swap(x, 4)를 한 경우 이다.
여기서 h(x, 1) = f(x - 1) + g(x - 1) = g(x)가 된다 (f(0)을 1이라 가정하면)
그리고 h(x, x) = g(x) (g(0)을 0이라 가정하면)
여기서 g는 h의 일부가 됨을 알 수 있다.

그리고
다음과 같이 주어질 때, [1, 2, 3, 4, 5, X, 7, 8, 9]
경우의 수를 다음과 같이 나눈다.
1. 자유석을 아무도 앉지 않을 때
왼쪽 5명, 오른쪽 3명에 대해 f(5) * f(3)

2. 1번이 자유석일때,
g(5) * f(3)
3. 2번이 자유석일때, ...

위 경우를 모두 합하면 답이 된다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int f[41];
int h[41][41];
int& fFunc(const int& val);
int& hFunc(const int& val1, const int& val2);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int seatCount, freeSeat;
	cin >> seatCount >> freeSeat;

	fill(f, f + 41, -1);
	fill(*h, *h + 41 * 41, -1);

	//점화식 기저 값
	h[0][1] = 0;
	f[0] = f[1] = h[1][1] = 1;
	f[2] = h[2][1] = 2;

	int result = 0;
	
	//자유석에 아무도 없는 경우
	result += fFunc(freeSeat - 1) * fFunc(seatCount - freeSeat);
	
	//자유석에 freeSeater가 앉고, 그 사람이 원래 자유석 왼쪽에 있었던 사람인 경우
	for (int freeSeater = 1; freeSeater < freeSeat; ++freeSeater)
		result += hFunc(freeSeat - 1, freeSeater) * fFunc(seatCount - freeSeat);
	
	//자유석에 freeSeater가 앉고, 그 사람이 원래 자유석 오른쪽에 있었던 사람인 경우
	for (int freeSeater = freeSeat + 1; freeSeater <= seatCount; ++freeSeater)
		result += fFunc(freeSeat - 1) * hFunc(seatCount - freeSeat, freeSeater - freeSeat);
	
	cout << result;

	return 0;
}


//f(x) = f(x - 1) + f(x - 2)
int& fFunc(const int& val)
{
	if (f[val] != -1)
		return f[val];
	return f[val] = fFunc(val - 1) + fFunc(val - 2);
}


//h(x, k) = g(k) * f(x - k) + f(k - 1) * g(x - k)
//h(x, 1) = g(x)
int& hFunc(const int& val1, const int& val2)
{
	if (h[val1][val2] != -1)
		return h[val1][val2];
	return h[val1][val2] = hFunc(val2, 1) * fFunc(val1 - val2) + fFunc(val2 - 1) * hFunc(val1 - val2, 1);
}