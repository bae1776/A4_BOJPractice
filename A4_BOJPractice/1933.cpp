//https://www.acmicpc.net/problem/1933

/*스카이라인 (Gold 1)
N개의 직사각형 모양의 건물들이 주어졌을 때, 스카이라인을 구해내세요.
스카이라인은 건물 전체의 윤곽을 의미하며, 이 뜻은 각각의 건물을 직사각형으로 표현했을 때,
직사각형들의 합집합을 의미한다.

N은 최대 10만이고, 건물의 위치 정보 및 높이는 최대 10억이다.

Solution :
건물 정보를 건물 시작 좌표 오름차순으로 정렬한 뒤, 
하나씩 multiset과 priority_queue(건물 끝 좌표 오름차순)에 집어넣는다.
multiset의 최댓값이 그 좌표에서의 최대 높이이다.
다음 건물의 시작 좌표와, 이미 포함된 건물의 가장 처음 끝 좌표 (priority_queue의 top)을 비교하면서
건물을 추가하거나 제거한다.
*/

#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using tuple3 = tuple<int, int, int>;

struct lastXgreater {
    bool operator() (const tuple3& a, const tuple3& b) {
        return get<2>(a) > get<2>(b);
    }
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int buildings;
    cin >> buildings;

    vector<tuple3> buildingList(buildings);
    for (auto& building : buildingList)
        cin >> get<0>(building) >> get<1>(building) >> get<2>(building);
    
    sort(buildingList.begin(), buildingList.end());
    
    multiset<int> currentBuildingHeights;
    priority_queue<tuple3, vector<tuple3>, lastXgreater> exceptBuildingList;

	auto bListIterator = buildingList.begin();
    int currentHeight = 0;

    while (true)
    {
        const int nextBuildingX = (bListIterator == buildingList.end()) ? 0x7FFFFFFF : get<0>(*bListIterator);
        const int nextExceptX = (exceptBuildingList.empty()) ? 0x7FFFFFFF : get<2>(exceptBuildingList.top());

        if (nextBuildingX == 0x7FFFFFFF && nextExceptX == 0x7FFFFFFF)
            break;

        if (nextBuildingX <= nextExceptX)
        {//추가될 건물이 사라질 건물보다 먼저 있는 경우 -> 추가
            while (bListIterator != buildingList.end() && get<0>(*bListIterator) == nextBuildingX)
            {
                currentBuildingHeights.emplace(get<1>(*bListIterator));
                exceptBuildingList.emplace(*bListIterator);
                bListIterator++;
            }
        }
            
        if (nextBuildingX >= nextExceptX) 
        {//삭제될 건물이 추가될 건물보다 먼저 있는 경우 -> 삭제
            while (exceptBuildingList.empty() == false && get<2>(exceptBuildingList.top()) == nextExceptX)
            {
                currentBuildingHeights.erase(currentBuildingHeights.find(get<1>(exceptBuildingList.top())));
                exceptBuildingList.pop();
            }
        }
        //(삭제해야할 건물과 추가해야할 건물이 동시에 있는 경우 둘다 일어남)

        const int nextHeight = (currentBuildingHeights.empty()) ? 0 : *(currentBuildingHeights.rbegin());
        //건물/추가 삭제 작업으로 건물의 높이가 달라지면 출력
        if (currentHeight != nextHeight)
                cout << min(nextBuildingX, nextExceptX) << ' ' << (currentHeight = nextHeight) << ' ';

    }


	return 0;
}
