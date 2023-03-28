//https://www.acmicpc.net/problem/15892

/*사탕 줍는 로봇 (Platinum 4)
Solution : 네트워크 플로우 - 디닉 알고리즘

1번 방에서 n번 방까지 이동경로를 정해 로봇을 출발시키려 할 때,
최대한 많이 보낼 수 있는 경우의 수를 구하는 것이다. 로봇은 지나갈 때 사탕을 한 개씩 주으므로
일종의 한 줄기의 유체 흐름이라 볼 수 있겠다.

에드몬즈 카프 알고리즘 O(V * E^2)을 이용해도 풀리는 거 같긴 하지만 (해당 알고리즘을 사용한 문제는, 6086번 참고)
(네트워크 플로우 알고리즘들은 이론적으로 계산된 최악의 시간복잡도를 내는 경우가 매우 드물다고 한다.)
이 문제의 정점은 300개, 간선은 최대 5000개이므로 애매하다. 그래서 조금 더 개선된 알고리즘인
Dinic's Algorithm O(V^2 * E)를 이용하여 풀어본다.
-> https://www.crocus.co.kr/1088


디닉 알고리즘은, 주어진 유량 그래프에서, source에서의 레벨 그래프를 만드는데,
이때 이미 레벨이 부여되었거나 유량 한계가 가득찬 간선은 제외 시켜버린다.
(여기서 제외되지 않는 모든 유량들을 차단 유량이라 함)
그리고 레벨 그래프에 대하여 DFS하면서 유량을 계산한다.

이 레벨 그래프의 생성 및 유량 계산을 레벨 그래프가 dest에 도달 할 수 없을 때까지 반복한다.
레벨 그래프 생성 시 주의할 점은, 
1. 유량을 흘려보낸 적이 있는 간선에 대해서는 역방향의 음의 유량 간선을 포함 시킬 수 있다.
2. work 배열을 이용하여 완전히 탐색이 끝난 간선에 대해서는 다시 탐색되지 않도록 한다. (각 단계의 O(VE)를 보장하기 위함)
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int roomCount, corridorCount;
int flow[301][301];
int capacity[301][301];
int nodeLevel[301];
int work[301];
int dinicMaxFlow(int source, int destination);
int dinicDFS(int curr, const int& end, int flowAmount);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> roomCount >> corridorCount;
    
    for (int i = 0; i < corridorCount; i++)
    {
        int start, end, cap;
        cin >> start >> end >> cap;
        capacity[start][end] += cap;
        capacity[end][start] += cap;
    }

    cout << dinicMaxFlow(1, roomCount);
	
	return 0;
}



int dinicMaxFlow(int source, int destination)
{
    int totalFlow = 0;
    while (true) //다음 과정을 반복함 (한 사이클이 한 단계이다)
    {   
        //레벨 배열, work 배열 초기화
        fill(nodeLevel, nodeLevel + roomCount + 1, -1);
        fill(work, work + roomCount + 1, 1);

        //1. 각 노드에 레벨을 매긴다.
        queue<int> nodeQueue;
        nodeQueue.push(source);
        nodeLevel[source] = 0;
        
        while (nodeQueue.empty() == false)
        {
            int now = nodeQueue.front();
            nodeQueue.pop();

            for (int next = 1; next <= roomCount; next++)
            {
                //레벨 그래프에는, 보낼 수 있는 유량이 남아 있는 간선만 취급한다.
                if (nodeLevel[next] == -1 && flow[now][next] < capacity[now][next])
                {
                    nodeLevel[next] = nodeLevel[now] + 1;
                    nodeQueue.push(next);
                }
            }
        }

        //레벨 그래프가 목적지에 도달할 수 없는 경우 알고리즘 종료
        if (nodeLevel[destination] == -1)
            break;


        //2. 레벨이 증가하는 간선만 포함하는 유량 계산을 수행한다.
        int singleRouteFlow;

        //레벨 그래프를 DFS 탐색하여 찾은 흐름이 있다면, 흐름 총량에 추가하고, 없으면 다음 단계로 넘어간다.
        while (singleRouteFlow = dinicDFS(source, destination, 0x3FFFFFFF))
            totalFlow += singleRouteFlow;
    }

    return totalFlow;
}


int dinicDFS(int curr, const int& end, int flowAmount)
{
    if (curr == end)
        return flowAmount; 
    //dinicMaxFlow에서 지정한 end(destnation)에 도착하면 총 흐름량을 반환한다.

    //work 배열로 이 단계에서 더 이상 흐를 수 없는 간선은 더 이상 탐색되지 않도록 한다. (알고리즘 속도 증가)
    //(work[curr] = curr와 연결된 다음 간선의 도착 인덱스)
    for (int& next = work[curr]; next <= roomCount; ++next)
    {
        //여유 유량이 있고, 이번 단계의 레벨 그래프에 포함된 간선만 탐색함
        if (flow[curr][next] < capacity[curr][next] && nodeLevel[curr] + 1 == nodeLevel[next])
        {
            int hereFlow = dinicDFS(next, end, min(capacity[curr][next] - flow[curr][next], flowAmount));
            
            //증가 경로가 있는 경우 -> DFS 레벨그래프 탐색 성공! 흐름량 반환
            if (hereFlow > 0)
            {
                flow[curr][next] += hereFlow;
                flow[next][curr] -= hereFlow;
                return hereFlow;
            }
        }
    }

    //흐름을 아예 찾지 못한 경우 : 0 반환
    return 0;
}