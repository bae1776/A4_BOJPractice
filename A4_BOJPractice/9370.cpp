//https://www.acmicpc.net/problem/9370

/*미확인 도착지

테스트케이스가 최대 100개 있고
테스트케이스마다 무방향성 양수 가중치 그래프가 주어진다. (정점 최대 2000, 간선 최대 50000개)

(취익)
B100 요원! 
서커스 예술가 한 쌍이, 도시(그래프)의 거리(간선)들을 이동하고 있다.
그들이 a 지점에서 출발한 것은 알지만, 도착 지점은 정확히 모른다.
다만 목적지 후보지는 파악해두었다. (후보지 최대 100개)
그들은 반드시 목적지까지로의 최단경로로만 이동한다. 그들의 경로를 파악하라.
(취익)


B100은 후각이 좋아서, 그들이 확실하게 지나간 거리(간선) 하나를 알아내었다.
이 정보들을 이용하여, 가능한 목적지 후보들을 간선 번호 오름차순으로 출력하시오.
- 교차로 사이의 도로는 기껏해야 1개이다.

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define INF 0x1FFFFFFF
using namespace std;
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

struct Node {
    vector<int> beforeTrack;
    vector<pair<short, int>> edgeList; //dist, endPos
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int vertex, edge, candidateCount;
        int suspectStart, suspectPass1, suspectPass2;
        cin >> vertex >> edge >> candidateCount;
        cin >> suspectStart >> suspectPass1 >> suspectPass2;

        vector<Node> graph(vertex + 1);

        for (int i = 0; i < edge; i++)
        {
            int start, end, weight;
            cin >> start >> end >> weight;

            graph[start].edgeList.emplace_back(weight, end);
            graph[end].edgeList.emplace_back(weight, start);
        }

        vector<int> candidateList(candidateCount);

        for (int i = 0; i < candidateCount; i++)
            cin >> candidateList[i];
        

        sort(candidateList.begin(), candidateList.end());

        //dijkstra Phrase
        vector<int> minDistance(vertex + 1, INF);
        vector<bool> visited(vertex + 1, false); 

        minDistance[suspectStart] = 0;

        minHeap<pair<int, int>> dijkstraPQ; //distance, nodeNumber
        dijkstraPQ.emplace(0, suspectStart);

        while (dijkstraPQ.empty() == false)
        {
            auto nowNode = dijkstraPQ.top();
            dijkstraPQ.pop();

            if (visited[nowNode.second] == true)
                continue;
            visited[nowNode.second] = true;

            for (const auto& adjEdge : graph[nowNode.second].edgeList)

                if (nowNode.first + adjEdge.first < minDistance[adjEdge.second])
                    {
                        minDistance[adjEdge.second] = nowNode.first + adjEdge.first;
                        graph[adjEdge.second].beforeTrack = vector<int>();
                        graph[adjEdge.second].beforeTrack.emplace_back(nowNode.second); 
                        dijkstraPQ.emplace(minDistance[adjEdge.second], adjEdge.second);
                    }
                else if (nowNode.first + adjEdge.first == minDistance[adjEdge.second])
                    graph[adjEdge.second].beforeTrack.emplace_back(nowNode.second);
        }

        for (const int& candidate : candidateList)
        {
            if (minDistance[candidate] == INF)
                continue;
            
            stack<pair<int, int>> dfsStack; //now, next

            for (const int& dest : graph[candidate].beforeTrack)
                dfsStack.emplace(candidate, dest);

            while (dfsStack.empty() == false)
            {
                auto beforeEdge = dfsStack.top();
                dfsStack.pop();

                if ((beforeEdge.first == suspectPass1 && beforeEdge.second == suspectPass2) || 
                        (beforeEdge.first == suspectPass2 && beforeEdge.second == suspectPass1))
                    {
                        cout << candidate << ' ';
                        break;
                    }
                
                for (const int& dest : graph[beforeEdge.second].beforeTrack)
                    dfsStack.emplace(beforeEdge.second, dest);
                

            }
        }

        cout << '\n';
    }

    return 0;
}

