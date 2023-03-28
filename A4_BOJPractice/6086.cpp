//https://www.acmicpc.net/problem/6086

/*최대 유량 (Gold 3)

Solution : 네트워크 플로우
사실 네트워크 플로우를 사용하지 않고 단순히 파이프의 합성만 잘하면 되는 문제이긴 하지만 (네트워크 플로우 알고리즘은 Platinum 이상)
학습을 위하여 네트워크 플로우로 풀어본다.
네트워크 플로우의 대표적인 알고리즘은 에드몬즈-카프 알고리즘(Edmonds-Karp Algorithm) 으로, 시간복잡도는 O(V * E^2) 이다.
A. 이해하기 쉬운 사이트 : https://polohee81.tistory.com/55
B. 이론적으로 엄밀하게 설명한 사이트 : https://gazelle-and-cs.tistory.com/82

이 알고리즘은 그리디하게 BFS 탐색하면서 목적지까지 흐를 수 있는 유량을 갱신한다.
예를 들어 경로가 1->4->2->3->10 이 있는 경우, 각 에지에 (현재 흐르고 있는 유량)/(파이프 최대 유량)을 저장해 놓고
이 경로의 유량은 각 에지의 잔여 유량의 최솟값으로 부여하는 것이다.

"그리디"하다는 것은 이 알고리즘은 경로가 어떠한 순서로 탐색되더라도 결국에는 최적의 값이 나온다는 것이다.
이 알고리즘을 이해 및 구현하는데의 핵심은

1. 잔여 네트워크 위에서의 거리의 증가성 (그리디한 접근의 정당화), 증가 경로를 찾는 횟수의 상한 (시간복잡도 상한 결정) -> B 사이트 참고
2. 흐름 경로로 추가된 방향의 반대로 음의 유량을 기록한다. 
현실에는 존재하지 않지만, 이는 기존에 추가했던 흐르는 경로를 철회하고 다른 더 여유로운 경로로 대체함으로써 최적값을 찾는 데 쓰인다.
3. BFS는 해당 파이프에 용량이 남아있는 경우에만 다음 탐색할 노드로 추가될 수 있으며, 이로 인해 목적지로 도달할 수 없는 경우 탐색이 끝난다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define NODE 52
using namespace std;

int capacity[NODE][NODE];
int flowing[NODE][NODE];

int getIndex(char ch);
int maxFlow(int start, int end);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int edgeCount;
    cin >> edgeCount;

    while (edgeCount--)
    {
        char start, end; int cap;
        cin >> start >> end >> cap;
        capacity[getIndex(start)][getIndex(end)] += cap;
        capacity[getIndex(end)][getIndex(start)] += cap;
    }

    //A->Z 까지의 최대 유량
    cout << maxFlow(getIndex('A'), getIndex('Z'));
	
	return 0;
}


int getIndex(char ch)
{
    if ('a' <= ch && ch <= 'z')
        return ch - 'a';
    else if ('A' <= ch && ch <= 'Z')
        return 26 + ch - 'A';
    else
        return 999999;
}



int maxFlow(int start, int end)
{
    int result = 0;
    vector<int> flowTrace(NODE); //이번 흐름(BFS)에서 자기자신 노드에 도달하기 전 노드 번호를 기록한다.

    while (1)
    {
        fill(flowTrace.begin(), flowTrace.end(), -1);
        queue<int> bfsQueue;
        bfsQueue.push(start);
        
        while (bfsQueue.empty() == false)
        {
            int top = bfsQueue.front();
            bfsQueue.pop();

            for (int next = 0; next < NODE; next++)
            {
                //흐르는 관의 용량이 남아있고, 이번 BFS에서 아직 방문하지 않은 경우에만
                //방문 큐에 추가한다.
                if (flowing[top][next] < capacity[top][next] && flowTrace[next] == -1)
                {
                    flowTrace[next] = top;
                    bfsQueue.push(next);
                    if (next == end) break; //도착지에 도달한 경우 즉시 BFS가 끝난다.
                }
            }
        }

        if (flowTrace[end] == -1)
            break;
        

        //이번에 구한 시작->끝점 흐름의 최댓값을 구한다. (각 파이프의 남은 용량의 최솟값)
        int maxFlowing = 0x3FFFFFFF;
        for (int flow = end; flow != start; flow = flowTrace[flow])
            maxFlowing = min(maxFlowing, capacity[flowTrace[flow]][flow] - flowing[flowTrace[flow]][flow]);
        
        //현재 흐르는 값을 갱신한다. 반대 방향으로는 음의 흐름을 추가한다.
        for (int flow = end; flow != start; flow = flowTrace[flow])
        {
            flowing[flowTrace[flow]][flow] += maxFlowing;
            flowing[flow][flowTrace[flow]] -= maxFlowing;
        }

        result += maxFlowing;
    }

    return result;
}