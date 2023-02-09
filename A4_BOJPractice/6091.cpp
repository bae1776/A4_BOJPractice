//https://www.acmicpc.net/problem/6091

/*핑크 플로이드 (Gold 1)

트리에 대한 플로이드 워샬 인접 행렬을 보고 트리 모양을 출력하는 문제이다.

Solution : MST
플로이드 워샬 인접 행렬에 의해 만들어지는 그래프는 완전 그래프이다.
여기서 MST를 뽑아내면 원래의 트리로 돌아간다.
왜냐하면, 바로 갈 수 없는 (거쳐 가야 하는) 경로는 반드시 MST를 이루는 간선보다 크므로,
MST를 만들게 된다면 경유 경로는 절대로 선택 되지 않는다.
*/

#include <iostream>
#include <queue>
using namespace std;

int graph[1025][1025];
int dist[1025], startPos[1025];
bool visited[1025];
priority_queue<int, vector<int>, greater<int>> treeEdge[1025];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int size;
    cin >> size;

    dist[0] = 0x3FFFFFFF;
    for (int start = 1; start <= size; start++)
    {
        dist[start] = 0x3FFFFFFF;
        for (int end = start + 1; end <= size; end++)
        {
            int input;
            cin >> input;
            graph[start][end] = graph[end][start] = input;
        }
    }

    //MST Prim 알고리즘에 에지 연결 정보 추가
    int now = 1;
    dist[now] = 0;
    for (int i = 0; i < size - 1; i++)
    {
        visited[now] = true;
        int next = 0;

        //dist 배열 갱신
        for (int j = 1; j <= size; j++)
            if (graph[now][j] < dist[j])
            {
                dist[j] = graph[now][j];
                startPos[j] = now;
            }

        //비방문 노드 중 가장 작은 dist를 지는 노드 선택
        for (int j = 1; j <= size; j++)
            if (visited[j] == false && dist[j] < dist[next])
                next = j;
        
        //에지 정보 추가
        treeEdge[next].push(startPos[next]);
        treeEdge[startPos[next]].push(next);
        now = next;
    }
    

    for (int nodeNumber = 1; nodeNumber <= size; nodeNumber++)
    {
        cout << treeEdge[nodeNumber].size() << ' ';
        while (treeEdge[nodeNumber].empty() == false)
        {
            cout << treeEdge[nodeNumber].top() << ' ';
            treeEdge[nodeNumber].pop();
        }
        cout << '\n';
    }

	return 0;
}
