//https://www.acmicpc.net/problem/1916

/*최소비용 구하기 (Gold 5)

흔한 다익스트라 문제
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cityCount, busCount;
    cin >> cityCount >> busCount;

    vector<vector<pair<int, int>>> busList(cityCount);
    vector<char> visited(cityCount, false);
    vector<int> distance(cityCount + 1, 0x3FFFFFFF);

    while (busCount--)
    {
        int busStart, busEnd, busCost;
        cin >> busStart >> busEnd >> busCost;
        
        busList[busStart - 1].emplace_back(busEnd - 1, busCost);
    }

    int start, end;
    cin >> start >> end;

    int nowVisit = start - 1;
    distance[start - 1] = 0;

    while (nowVisit != cityCount)
    {
        visited[nowVisit] = true;

        for (const auto& cityBus : busList[nowVisit])
        {
            distance[cityBus.first] = min(distance[cityBus.first], distance[nowVisit] + cityBus.second);
        }

        nowVisit = cityCount;
        for (int i = 0; i < cityCount; i++)
        {
            if (visited[i] == false && distance[i] < distance[nowVisit])
                nowVisit = i;
        }
    }

    cout << distance[end - 1];



	
	return 0;
}
