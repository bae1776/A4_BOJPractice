//https://www.acmicpc.net/problem/1238

//파티
//각 마을에 사는 학생들이 한 마을에 모여서 파티를 하려고 한다.
//최단 경로로 파티를 여는 마을에 갔다가 다시 자신의 마을로 돌아갈 때, 가장 오래 걸리는 학생의 소요시간을 구하여라.
//마을은 최대 1000개, 단방향 경로는 최대 10000개 이다.

#include <queue>
#include <vector>
#include <iostream>
using namespace std;
#define INF 987654321


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int town, road, partyTown;
    cin >> town >> road >> partyTown;

    vector<vector<pair<int, int>>> adjList(town + 1);
    int* totalDistance = new int[town + 1];
    
    for (int i = 0; i < road; i++)
    {
        int start, end, time;
        cin >> start >> end >> time;
        adjList[start].emplace_back(time, end);
    }

    

    //1. 본인 마을 -> 파티 마을 구하기
    for (int startTown = 1; startTown <= town; startTown++)
    {
        if (startTown == partyTown)
        {
            totalDistance[startTown] = 0;
            continue;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra_minHeap;
        vector<int> shortestDist(town + 1, INF);
        vector<bool> visited(town + 1, false);
        dijkstra_minHeap.emplace(0, startTown);
        shortestDist[startTown] = 0;
        
        do {
            pair<int, int> elem = dijkstra_minHeap.top();
            dijkstra_minHeap.pop();
            
            if (visited[elem.second] == true)
                continue;
            visited[elem.second] = true;

            for (auto& roadFromTown : adjList[elem.second])
            {
                if (shortestDist[roadFromTown.second] > shortestDist[elem.second] + roadFromTown.first)
                {
                    shortestDist[roadFromTown.second] = shortestDist[elem.second] + roadFromTown.first;
                    if (visited[roadFromTown.second] == false)
                        dijkstra_minHeap.emplace(shortestDist[roadFromTown.second], roadFromTown.second);
                }
            }

        } while (dijkstra_minHeap.empty() == false);

        totalDistance[startTown] = shortestDist[partyTown];
    }


    //2. 파티 마을->자신 마을 거리 구하기
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra_minHeap;
    vector<int> shortestDist(town + 1, INF);
    vector<bool> visited(town + 1, false);
    dijkstra_minHeap.emplace(0, partyTown);
    shortestDist[partyTown] = 0;
       
    do {
       pair<int, int> elem = dijkstra_minHeap.top();
       dijkstra_minHeap.pop();
           
       if (visited[elem.second] == true)
           continue;
       visited[elem.second] = true;
        for (auto& roadFromTown : adjList[elem.second])
        {
            if (shortestDist[roadFromTown.second] > shortestDist[elem.second] + roadFromTown.first)
            {
                shortestDist[roadFromTown.second] = shortestDist[elem.second] + roadFromTown.first;
                if (visited[roadFromTown.second] == false)
                    dijkstra_minHeap.emplace(shortestDist[roadFromTown.second], roadFromTown.second);
            }
        }
    } while (dijkstra_minHeap.empty() == false);
    

    int maxDist = 0;
    for (int i = 1; i <= town; i++)
    {
        totalDistance[i] += shortestDist[i];
        maxDist = max(maxDist, totalDistance[i]);
    }

    cout << maxDist;

    delete[] totalDistance;


	return 0;
}
