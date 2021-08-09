//https://www.acmicpc.net/problem/2293

/*동전 1

n(~100)가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 
이 동전을 적당히 사용해서, 그 가치의 합이 k(~10000)원이 되도록 하고 싶다. 
그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.
사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

(메모리 제한이 4MB로, int 100만개가 넘으면 시간 초과가 됨을 유의할 것)
*/

#include <iostream>
using namespace std;
int DP[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int coinCount, goal;
    cin >> coinCount >> goal;
    DP[0] = 1;

    int coinValue;
    while (coinCount--)
    {
        cin >> coinValue;

        for (int i = 0; i <= goal; i++)
            if (i - coinValue >= 0)
                DP[i] += DP[i - coinValue];
    }

    cout << DP[goal];

    return 0;
}
