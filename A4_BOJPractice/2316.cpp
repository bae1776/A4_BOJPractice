//https://www.acmicpc.net/problem/2316

/*전구와 스위치 (Gold 3)

Solution : 네트워크 플로우

1번 도시를 Source, 2번 도시를 Sink로 하는 네트워크 플로우를 하면 된다.
그런데, 이 문제의 조건은 모든 정점은 단 1번만 방문해야 하기 때문에 그래프를 변형해야 한다.
모든 도시 k에 대해 k-in, k-out 이라는 2개의 정점으로 쪼개고 
in은 k로 들어오는 간선, out은 k에서 나가는 간선만 취급하며 k-in -> k-out 으로 가는 용량이 1만 부여된 간선을 추가한다.

그리고 참고 사항으로,
1. 석원이 1, 2번 도시를 왔다갔다해서 순방향, 역방향이 되는 것은 생각할 필요 없이
2번 편도로 갈 수 있다면 1번 왔다갔다 할 수 있는 것이다.
2. 각 간선의 가중치는 다 1을 부여한다. (어차피 2번 지날 수 없다)

에드몬즈-카프 알고리즘을 사용하였다.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
enum {IN, OUT};
#define Node(a, b) a*2-b

int nodeCount, edgeCount;
int flow[802][802], capacity[802][802];
int maxFlow(int start, int end);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> nodeCount >> edgeCount;

    for (int num = 1; num <= nodeCount; num++)
        capacity[Node(num, IN)][Node(num, OUT)] = 1;
    

    int start, end;
    while (edgeCount--)
    {
        cin >> start >> end;
        capacity[Node(start, OUT)][Node(end, IN)]++;
        capacity[Node(end, OUT)][Node(start, IN)]++;    
    }

    cout << maxFlow(1, 2);

	return 0;
}


int maxFlow(int start, int end)
{
    int result = 0;
    int flowTrace[802];

    start = Node(start, OUT);
    end = Node(end, IN);
    
    while (true)
    {
        fill(flowTrace, flowTrace + nodeCount * 2 + 1, -1);
        queue<int> bfsQueue;
        bfsQueue.push(start);
        flowTrace[start] = flowTrace[start + 1] = 0;
        bool bfsTerminate = false;

        while (!bfsTerminate && !bfsQueue.empty())
        {
            int nowIndex = bfsQueue.front();
            bfsQueue.pop();

            if (nowIndex % 2 == IN)
            {
                //현재 노드가 IN 노드인 경우, 다른(본인 포함) 노드의 OUT 노드로만 갈 수 있다.
                //음의 유량에 대해 연산 할 수 있으려면 다른 OUT 노드로 갈 수 있어야 함
                for (int next = 1; next <= nodeCount * 2; next += 2)
                {
                    if (flow[nowIndex][next] < capacity[nowIndex][next] && flowTrace[next] == -1)
                    {
                        flowTrace[next] = nowIndex;
                        bfsQueue.push(next);
                    }
                }
            } else {
                //현재 노드가 OUT 노드인 경우, 다른(본인 포함) 노드의 IN 노드로만 갈 수 있다.
                //음의 유량에 대해 연산 할 수 있으려면 본인 IN 노드로도 갈 수 있어야 함.
                for (int next = 2; next <= nodeCount * 2; next += 2)
                {
                    if (flow[nowIndex][next] < capacity[nowIndex][next] && flowTrace[next] == -1)
                    {
                        flowTrace[next] = nowIndex;
                        bfsQueue.push(next); 
                        if (next == end)
                        {
                            bfsTerminate = true;
                            break;
                        }
                    }
                }
            }
        }

        if (flowTrace[end] == -1)
            break;

        //어차피 유량은 1이므로, flow 배열 갱신만 해준다.
        for (int dest = end; dest != start; dest = flowTrace[dest])
        {
            flow[flowTrace[dest]][dest]++;
            flow[dest][flowTrace[dest]]--;
        }

        result++;
    }

    return result;
}