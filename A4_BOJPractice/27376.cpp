//https://www.acmicpc.net/problem/27376

/*참살이길 (Silver 4)

Solution : 시뮬레이션 (구현)
근데 이게 실버 4라고?
*/

#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
using TSign = tuple<int, int, int>;

TSign signList[100000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int roadLen, trafficSign;
    cin >> roadLen >> trafficSign;

    for (int i = 0; i < trafficSign; i++)
    {
        auto& [loc, period, start] = signList[i];
        cin >> loc >> period >> start;
    }

    sort(signList, signList + trafficSign);

    int nowLocation = 0;
    long long timePassed = 0;
    for (int i = 0; i < trafficSign; i++)
    {
        auto& [signLoc, signPeriod, signStart] = signList[i];
        
        //이동하기
        timePassed += signLoc - nowLocation;
        nowLocation = signLoc;

        //신호 대기
        if (timePassed <= signStart)
        {
            //신호가 안 켜진 경우 대기해야 함
            timePassed = signStart;
        } else {
            int nowWherePeriod = (timePassed - signStart) % (signPeriod * 2);

            if (nowWherePeriod >= signPeriod) //빨간불이므로 대기해야함
                timePassed += signPeriod * 2 - nowWherePeriod;
        }
    }

    //마지막 신호등 건너고 이동...
    timePassed += roadLen - get<0>(signList[trafficSign - 1]);

    cout << timePassed;

	return 0;
}