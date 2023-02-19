//https://www.acmicpc.net/problem/1480

/*보석 모으기 (Gold 1)

Solution : DP

DP[bagIndex][nowWeight][jewelState] 로 정의한다.
 = 1~(bagIndex - 1)번 가방까지 다 이용한 상태이고, bagIndex번 가방에 nowWeight 만큼 채운 상태이며, 
 jewelState 만큼 보석을 이미 사용한 상태일 때, 더 넣을 수 있는 보석의 수.

그러면 답은 DP[0][0][0]이 된다.
수가 최대한 크더라도 DP의 크기는 160만이므로 메모리는 부족하지 않다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

short DP[10][21][1 << 13]; 
short jewelList[13];
short jewelCount, bagCount, bagLimit;
short& DPFunction(int bagIndex, int nowWeight, short jewelState);
short allSelected;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> jewelCount >> bagCount >> bagLimit;
    for (int i = 0; i < jewelCount; i++)
        cin >> jewelList[i];

    allSelected = (1 << jewelCount) - 1;
    fill(**DP, **DP + 10 * 21 * (1 << 13), (short)-1);

    cout << DPFunction(0, 0, 0);

	return 0;
}


short& DPFunction(int bagIndex, int nowWeight, short jewelState)
{
    if (bagIndex == bagCount)
        return DP[0][0][1]; //반드시 -1

    short& self = DP[bagIndex][nowWeight][jewelState];

    if (self != -1)
        return self;

    if (jewelState == allSelected)
        return self = 0;
    

    self = 0;
    for (int i = 0; i < jewelCount; i++)
    {
        if (jewelState & (1 << i)) continue;
        if (nowWeight + jewelList[i] > bagLimit)
            self = max(self, DPFunction(bagIndex + 1, 0, jewelState));
        else
            self = max(self + 0, DPFunction(bagIndex, nowWeight + jewelList[i], jewelState | (1 << i)) + 1);
    }

    return self;
}



