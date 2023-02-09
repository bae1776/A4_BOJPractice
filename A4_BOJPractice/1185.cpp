//https://www.acmicpc.net/problem/1185

/* Cheering up the Cows (Platinum 4)

농부 존은 게을러서 더 이상 목초지(1 ~ N(최대 10000)번)들을 잇는 길을 유지하고 싶지 않았다.
각 목초지에는 소가 한 마리씩 있기 때문에 존은 모든 목초지의 연결은 유지하면서 길은(최대 10만) 최대한 줄이려고 한다.
즉, 길을 N-1개로 줄여야한다.

소들은 길이 줄어드는 걸 슬퍼하기 때문에 그들을 힘내게 하기 위해서 모든 소(목초지)들을 방문하려 한다.
길마다 이동시간이 주어지며, 목초지에 방문할 때마다 (이미 온 적이 있더라도) 소와 대화시간이 소요된다.
존은 임의의 목초지에서 출발할 수 있으나 반드시 처음 목초지와 마지막 방문 목초지는 같아야 한다.
이때, 총 최소 소요시간을 구하시오.

Solution : MST (Prim with Priorityqueue)

길을 N-1개만 남기면 트리 형태가 되는데, 이 형태에서 존이 모든 목초지를 방문하여 원래 위치로 돌아온다고 하면, 
각 간선을 모두 한번씩 왔다갔다하는 경로가 만들어지고 정확히 2회를 지나야 한다.
각 정점에 방문비용(소와 대화시간)을 고려해야 하므로
MST로 이 문제를 푸려면, 간선의 비용 = 원래 간선 비용 * 2 + 출발 정점 비용 + 도착 정점 비용 으로 변형해야 한다.
그리고 여기에 출발 목초지의 정점 비용을 추가한다. (출발할 때 방문이 1번 추가된다.) 
당연히 총 비용이 최소가 되려면, 출발 정점은 제일 방문 비용이 낮은 정점이 되야할 것이다.
*/

#include <iostream>
#include <queue>
#include <list>
using namespace std;

bool visited[10001];
int nodeCost[10001];
list<pair<int, int>> edgeList[10001]; //[start] = {cost, end};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int result = 0x3FFFFFFF, nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    for (int i = 1; i <= nodeCount; i++)
    {
        cin >> nodeCost[i];
        result = min(result, nodeCost[i]);
    }

    while (edgeCount--)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        cost = cost * 2 + nodeCost[start] + nodeCost[end];

        edgeList[start].emplace_back(cost, end);
        edgeList[end].emplace_back(cost, start);
    }

    using T = pair<int, int>;
    priority_queue<T, vector<T>, greater<T>> primPQ;

    int nowVisit = 1;

    for (int i = 0; i < nodeCount - 1; i++)
    {
        visited[nowVisit] = true;

        for (const auto& nowVisitEdge : edgeList[nowVisit])
        {
            if (visited[nowVisitEdge.second] == false)
                primPQ.emplace(nowVisitEdge);
        }

        pair<int, int> nextEdge = primPQ.top();
        while (visited[nextEdge.second])
        {
            primPQ.pop();
            nextEdge = primPQ.top();
        }

        result += nextEdge.first;
        nowVisit = nextEdge.second;
    }

    cout << result;

    return 0;
}

