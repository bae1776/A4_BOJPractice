//https://www.acmicpc.net/problem/1753

//최단 경로
//다익스트라 연습 문제
//최대 정점은 2만개, 최대 경로는 30만개이다.

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int vertex, edge, start;
    cin >> vertex >> edge >> start;
    start--;

    vector<vector<pair<int, int>>> adjList(vertex); //pair : end, weight
    int* shortestPath = new int[vertex];
    bool* visited = new bool[vertex];
    
    for (int i = 0; i < vertex; i++)
    {
        shortestPath[i] = INF;
        visited[i] = false;
    }

    for (int i = 0; i < edge; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        adjList[start - 1].emplace_back(end - 1, weight);
    }
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, 
        greater<pair<int, int>>> dijkstra_minHeap; //pair : Dist, vertexNumber

    dijkstra_minHeap.emplace(0, start);
    shortestPath[start] = 0;


    while (dijkstra_minHeap.empty() == false)
    {
        auto element = dijkstra_minHeap.top();
        dijkstra_minHeap.pop();

        if (visited[element.second] == true)
            continue;
        visited[element.second] = true;

        for (const auto& adjEdge : adjList[element.second])
        {
            shortestPath[adjEdge.first] = 
                min(shortestPath[adjEdge.first], shortestPath[element.second] + adjEdge.second);
        
            if (visited[adjEdge.first] == false)
                dijkstra_minHeap.emplace(shortestPath[adjEdge.first], adjEdge.first);
        }

    };


    for (int i = 0; i < vertex; i++)
    {
        if (shortestPath[i] == INF)
            cout << "INF";
        else
            cout << shortestPath[i];

        cout << '\n';
    }
    
    delete[] shortestPath;
    delete[] visited;

	return 0;
}
