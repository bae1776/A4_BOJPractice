//https://www.acmicpc.net/problem/17503

/*맥주 축제
내일부터 N일 동안 대구광역시에서 맥주 축제가 열립니다.
축제엔 K 종류의 맥주가 있고 매일 서로 다른 맥주 1병만 마실 수 있습니다.

전씨는 맥주를 좋아하지만, 도수가 높은 맥주를 마시면 시험을 망치게 됩니다.
그래서 의사에게 자신의 간은 강력하게 만들어 달라고 부탁했습니다.
하지만 간을 강력하게 만드는 비용은 비싸기 때문에, 가능한 한 조금만 강화할 계획을 세웠습니다.
K종류의 맥주에 각각 '선호도'와 '도수 레벨'이 주어집니다.
맥주의 도수 레벨이 전씨의 간 레벨보다 높으면 전씨는 기절합니다.
전씨는 기절하지 않고 마실 맥주 N개의 맥주 선호도 합 M을 달성하고 싶을때, 필요한 최소한의 간 레벨을 구하세요.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int festivalDay, satisfaction, beer;
    cin >> festivalDay >> satisfaction >> beer;

    vector<pair<int, int>> beerList(beer);
    for (int i = 0; i < beer; i++)
        cin >> beerList[i].second >> beerList[i].first;

    sort(beerList.begin(), beerList.end());

    priority_queue<int, vector<int>, greater<int>> myBeerList;
    
    int nowSatifSum = 0;
    int maxAlcohol = 0;
    for (int i = 0; i < festivalDay; i++)
    {
        myBeerList.emplace(beerList[i].second);
        nowSatifSum += beerList[i].second;
        maxAlcohol = beerList[i].first;
    }

    for (int i = festivalDay; i < beer && nowSatifSum < satisfaction; i++)
    {
        int lowestSatifBeer = myBeerList.top();
        myBeerList.pop();
        nowSatifSum -= lowestSatifBeer;

        myBeerList.emplace(beerList[i].second);
        nowSatifSum += beerList[i].second;
        maxAlcohol = beerList[i].first;    
    }


    if (nowSatifSum < satisfaction)
        cout << -1;
    else
        cout << maxAlcohol;


    return 0;
}
