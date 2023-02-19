//https://www.acmicpc.net/problem/1202

/*보석도둑 (Gold 2)

Solution : 그리디 알고리즘

이 문제는 가방에 보석을 최대 1개만 넣을 수 있으므로
냅색 문제가 아니다.
보석을 가치 내림차순으로 정렬한 뒤, 넣을 수 있다면 가장 제한 무게에 근접하는
가방에다가 집어넣어 훔쳐가는 선택 방식이 최적이다.
*/

#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> jewelList[300000]; //<price, weight>
multiset<int> bagList;
long long answer = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int jewelCount, bagCount;
    cin >> jewelCount >> bagCount;

    for (int i = 0; i < jewelCount; i++)
        cin >> jewelList[i].second >> jewelList[i].first;
    
    int bagWeight;
    for (int i = 0; i < bagCount; i++)
    {
        cin >> bagWeight;
        bagList.insert(bagWeight);
    }

    sort(jewelList, jewelList + jewelCount, [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    });

    
    for (int i = 0; i < jewelCount; i++)
    {
        auto it = bagList.lower_bound(jewelList[i].second);

        if (it != bagList.end())
        {
            answer += jewelList[i].first;
            bagList.erase(it);
        }
    }

    cout << answer;

	return 0;
}

