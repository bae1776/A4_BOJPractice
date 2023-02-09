//https://www.acmicpc.net/problem/5719

/*거의 최단 경로 (Platinum 5)

거의 최단 경로란, 최단 경로에 포함되지 않은 도로로만 이루어진 경로 중에서 가장 짧은 것을 의미한다.
도로 정보 각각에 대하여
'거의 최단 경로'의 길이를 구하세요. 구할 수 없는 경우 -1을 출력하세요.

각 도로 정보는
정점 최대 500개, 단방향 도로 최대 1만개, 도로 길이는 1 ~ 1000 이며
출발지 A에서 도착지 B로 가는 도로는 유일하며 A != B이다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using RoadList = vector<vector<int>>;

vector<int> dijkstra(const RoadList& roadList, int start, int end);
void deleteShortestPath(const vector<int>& minDist, RoadList& roadList, int start, int end);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    while (true)
    {
        int city, road, start, end;
        cin >> city >> road;

        if (city == 0) break;

        cin >> start >> end;

        RoadList roadList(city, vector<int>(city));
        while (road--)
        {
            int start, end, len;
            cin >> start >> end >> len;
            roadList[start][end] = len;
        }

        auto minDistList = dijkstra(roadList, start, end);
        deleteShortestPath(minDistList, roadList, start, end);
        auto almostMinDistList = dijkstra(roadList, start, end);

        if (almostMinDistList.empty())
            cout << -1 << '\n';
        else
            cout << almostMinDistList[end] << '\n';
    }
	
	return 0;
}


vector<int> dijkstra(const RoadList& roadList, int start, int end)
{
    vector<int> minDist(roadList.size() + 1, 0x3FFFFFFF);
    vector<char> visited(roadList.size(), false);

    int nowVisit = start;
    minDist[start] = 0;

    while (nowVisit != roadList.size())
    {
        visited[nowVisit] = true;
        for (int dest = 0; dest < roadList.size(); dest++)
        {
            if (roadList[nowVisit][dest] != 0)
                minDist[dest] = min(minDist[dest], minDist[nowVisit] + roadList[nowVisit][dest]);
        }

        nowVisit = roadList.size();
        for (int next = 0; next < roadList.size(); next++)
            if (visited[next] == false && minDist[next] < minDist[nowVisit])
                nowVisit = next;
    }

    if (minDist[end] == 0x3FFFFFFF)
        return vector<int>();

    minDist.pop_back();
    return minDist;
}

void deleteShortestPath(const vector<int>& minDist, RoadList& roadList, int start, int end)
{
    if (minDist.empty()) return;

    //역추적
    vector<char> queued(roadList.size(), false);
    queue<int> searchQueue;

    searchQueue.emplace(end);
    queued[end] = true;


    while (searchQueue.empty() == false)
    {
        int nowVisit = searchQueue.front();
        searchQueue.pop();
        
        for (int dest = 0; dest < roadList.size(); dest++)
        {
            if (roadList[dest][nowVisit] != 0 && minDist[dest] + roadList[dest][nowVisit] == minDist[nowVisit])
            {
                roadList[dest][nowVisit] = 0;
                if (queued[dest] == false)
                {
                    queued[dest] = true;
                    searchQueue.emplace(dest);
                }
            }
        }
    }
}