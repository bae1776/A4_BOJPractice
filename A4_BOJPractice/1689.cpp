//https://www.acmicpc.net/problem/1689

/* 겹치는 선분 (Gold 4)

1차원 좌표계 상 선분 N개 (최대 100만)가 주어질 때, 
선분이 최대로 겹쳐있는 부분의 겹친 선분 개수를 구하시오.
단, 점에서만 만나는 건 겹치는 것으로 간주하지 않는다.

Solution : 
시작 좌표 오름차순 정렬하고 끝 좌표 오름차순 우선순위 큐와 비교
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> lineList[1000000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
        cin >> lineList[i].first >> lineList[i].second;

    sort(lineList, lineList + count);

    priority_queue<int, vector<int>, greater<int>> endq;
    size_t maxOverlay = 0;

    for (int i = 0; i < count; i++)
    {
        while (!endq.empty() && endq.top() <= lineList[i].first)
            endq.pop();
        endq.push(lineList[i].second);

        maxOverlay = max(maxOverlay, endq.size());
    }

    cout << maxOverlay;
    
    return 0;
}