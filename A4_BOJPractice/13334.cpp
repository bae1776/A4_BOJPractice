//https://www.acmicpc.net/problem/13334

/*철로 (Gold 2)

집과 사무실을 통근하는 N명(최대 10만)의 사람들이 있다.
각 사람의 집과 사무실은 수평선 상에 있는 서로 다른 점에 위치하고 있다.

통근자들의 편의를 위하여 일직선 상의 어떤 두 점을 잇는 철로를 건설하여 기차를 운행하려 하는데,
지을 수 있는 철로의 길이는 한정되어있다. 또한, 구간별로 끊을 수 없고 한 선분으로 연속적으로만 놓을 수 있다.

사람들의 집, 사무실 위치와, 철로의 최대 길이가 주어질 때,
철로의 혜택을 받을 수 있는 최대 인원 수를 구하시오. 
(집과 사무실이 모두 철로 선분 안에 있어야 혜택을 받는다고 정의한다.)
좌표는 최하 -1억, 최대 +1억이며, 철로의 최대 길이는 2억이다.

Solution : (집, 사무실) 위치 쌍의
뒤쪽 좌표를 기준으로 정렬 시키고, 우선순위 최소 큐를 생성 후,
정렬된 쌍을 순회하면서, 앞쪽 좌표를 최소 큐에 집어 넣는다.
그리고 뒤쪽 좌표를 기준으로 철로 제한 길이를 뺐을 때 더 큰 원소만 큐에 남긴다.
예를 들어 (10, 20), (20, 30), (25, 30), (5, 40) 이고 (편의상 이미 정렬됨) 선로 길이가 30이다.
순회 인덱스 = 0일 때, end = 20이고, PQ = 10 이며 start = -10이므로 노선 1개
순회 인덱스 = 1일 때, end = 30이고, PQ = 10, 20 이며 start = 0 -> 노선 2개 
순회 인덱스 = 2일 때, end = 30이고, PQ = 10, 20, 25 이며 start = 0 -> 노선 3개 
순회 인덱스 = 3일 때, end = 40이고, PQ = 5, 10, 20, 25 이며 start = 10 이므로 PQ 원소 하나 제거 -> 노선 3개

각 순회에 대해 우선 순위 큐의 길이가 결정되는데, 그 순회 직후 길이들 중 최댓값이 답이 된다. 


*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> startLocationPQ;
    vector<pair<int, int>> commuterList;

    int people;
    cin >> people;
    commuterList.reserve(people);

    while (people--)
    {
        int start, end;
        cin >> start >> end;
        if (start > end) swap(start, end);
        commuterList.emplace_back(start, end); 
    }

    sort(commuterList.begin(), commuterList.end(), [](const auto& a, const auto& b) -> bool {
        return a.second < b.second;
    });
    int maxRailLength;
    cin >> maxRailLength;

    int result = 0;
    for (const auto& commuterPair : commuterList)
    {
        int railEnd = commuterPair.second;
        startLocationPQ.push(commuterPair.first);

        int railStart = railEnd - maxRailLength;
        while (startLocationPQ.empty() == false && startLocationPQ.top() < railStart)
            startLocationPQ.pop();

        result = max(result, (int)startLocationPQ.size());
    }

    cout << result;

    return 0;
}