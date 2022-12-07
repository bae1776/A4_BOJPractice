//https://www.acmicpc.net/problem/2419

/*사수아탕 (Platinum 1)
수아는 수평선 상에 0 위치에 앉아있고, 수평선 상에는 n(최대 300)개의 사탕바구니가 있고, 각 사탕 바구니에는 똑같이 m(최대 100만)개의 사탕이 들어있다.
수아는 단위 시간당 1 만큼을 움직일 수 있고, 사탕바구니에 도달하는 순간 전부 먹을 수 있다.
그런데 날씨가 더워서 모든 사탕바구니는 단위 시간마다 사탕이 1씩 줄어든다.

수아가 먹을 수 있는 사탕의 최대 개수를 구하시오.
(사탕바구니의 위치는 -10000 이상 10000 이하이다)
*/

/*
풀이 : 2315 가로등 끄기 문제의 업그레이드 문제이다.
가로등 끄기 문제는 left, right, isRight(bool) 로 풀 수 있었지만,
이 문제는 다음과 같이 DP를 정의한다.
DP(left, right, isRight, basket) = left-right는 이미 다 먹은 상태로 가정하고, isRight ? right : left에 수아가 위치하고 있을때, 추가로 basket개의 사탕 바구니를 더 먹으려할 때, 먹으려고 하는 바구니의 최소 손실값
그러면 
isRight = true일때, DP(l, r, b) = min{DP(l-1, r, b-1) + b * (Point(r) - Point(l-1)) , DP(l, r+1, b-1) + b * (Point(r+1) - Point(r))}
isRight =false일때, DP(l, r, b) = min{DP(l-1, r, b-1) + b * (Point(l) - Point(l-1)) , DP(l, r+1, b-1) + b * (Point(r+1) - Point(l))}

여기서 우리는 b개의 사탕바구니만 더 먹을꺼기 때문에, 다른 바구니의 손해량은 고려할 필요가 없다.

우리가 구하려고 하는 결과값은
max{b * m - DP(0, 0, k) : for k in [0, n)} 이라 할 수 있다.

이때, 사탕바구니 좌표 중 0이 없는 경우, 임의로 0을 추가하고 결과값에서 m(바구니 사탕 갯수)를 제외 하면 된다.

영어 원문 해설 찾아보기 : https://boi.cses.fi/tasks.php  : 2009년 day 1 1번 문제

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candyBasket, candyCount;
vector<int> basketLocationList;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int result = 0;

    cin >> candyBasket >> candyCount;
    basketLocationList = vector<int>(candyBasket);

    for (int i = 0; i < candyBasket; i++)
        cin >> basketLocationList[i];
    

    basketLocationList.emplace_back(0);


    int DP[2][2][303][303] = {0}; //[before/now][isright][left][right]

    sort(basketLocationList.begin(), basketLocationList.end());
    int zeroIndex = find(basketLocationList.begin(), basketLocationList.end(), 0) - basketLocationList.begin();

    for (int remainBasket = 1; remainBasket < candyBasket; remainBasket++)
    {
        int before = remainBasket % 2;
        int now = 1 - before;

        for (int left = 0; left < candyBasket; left++)
        {
            for (int right = left; right < candyBasket; right++)
            {
                DP[now][false][left][right] = DP[now][true][left][right] = 0x1FFFFFFF;
                if (candyBasket - (right - left + 1) >= remainBasket)
                {
                    if (left > 0)
                    {
                        DP[now][false][left][right] = min(DP[now][false][left][right], DP[before][false][left - 1][right] + remainBasket * (basketLocationList[left] - basketLocationList[left - 1]));
                        DP[now][true][left][right] = min(DP[now][true][left][right], DP[before][false][left - 1][right] + remainBasket * (basketLocationList[right] - basketLocationList[left - 1]));
                    }
                    if (right < candyBasket)
                    {
                        DP[now][false][left][right] = min(DP[now][false][left][right], DP[before][true][left][right + 1] + remainBasket * (basketLocationList[right + 1] - basketLocationList[left]));
                        DP[now][true][left][right] = min(DP[now][true][left][right], DP[before][true][left][right + 1] + remainBasket * (basketLocationList[right + 1] - basketLocationList[right]));
                    }
                    }
            }
        }

        result = max(result, remainBasket * candyCount - DP[now][true][zeroIndex][zeroIndex]);
    }

    cout << result;

	
	return 0;
}


