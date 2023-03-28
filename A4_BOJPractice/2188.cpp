//https://www.acmicpc.net/problem/2188

/*축사 배정 (Platinum 4)

Solution : 이분 매칭 (Bipartite Matching)
https://www.crocus.co.kr/499

이분 매칭은, 네트워크 플로우(대표문제 6086번)의 특수 버전으로
source 노드 집합의 한 노드에서에서 dest 노드 집합을 1개만 대응 시킬 수 있을때,
최대 매칭 수를 찾는 것으로, 대응되는 간선이 네트워크 플로우에서 나타내는 유량이 모두 1인 경우이다.
이분 매칭은 DFS로 진행하며 시간복잡도는 O(VE) 이다.

네트워크 플로우와 다른 점은, 음의 유량을 모두 체크해 가면서 노드를 탐색하는 것이 아니라,
중복되는 dst를 요구하는 src가 있을때, src를 기준으로 먼저 들어간 src가 양보해 본다는 느낌으로 프로그램이 진행된다는 것이다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

//src[i] -> dst[j] 로 가는 경로가 있는지 여부
bool adj[201][201]; 

//이분 매칭에서 각 src에 대한 DFS에 대해 src[i]가 방문했는 했는지 체크
bool visited[201]; 

//j = src[i], i = dst[j]
int cowMatched[201], shedMatched[201]; 
int cow, shed;
bool dfs(int src);
int bipartiteMatch(); 



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> cow >> shed;

    for (int cowIndex = 1; cowIndex <= cow; cowIndex++)
    {
        int shedCount;
        cin >> shedCount;
        int shedIndex;
        for (int j = 0; j < shedCount; j++)
        {
            cin >> shedIndex;
            adj[cowIndex][shedIndex] = true;
        }
    }

    cout << bipartiteMatch();
    

	return 0;
}


int bipartiteMatch()
{
    int matchCount = 0;

    for (int src = 1; src <= cow; src++)
    {
        fill(visited, visited + cow + 1, false);

        //src(소)에 대해 매칭할 수 있는 헛간을 DFS로 찾는다.
        if (dfs(src)) matchCount++;
    }

    return matchCount;
}


bool dfs(int src)
{
    if (visited[src] == true)
        return false; 
    //이미 방문한 곳에 다시 온 경우, 무한으로 순환 파생되므로 불가 판정

    visited[src] = true;

    for (int dst = 1; dst <= shed; dst++)
    {
        if (adj[src][dst])
        {
            //dst(헛간)을 점유하고 있는 src(소)가 없거나
            //혹은, 이미 점유하고 있는 소를 쫓아내서 다른 곳에 넣는 것이 가능하면, 비워진 dst(헛간)에 src(소)를 넣고 true 반환
            if (shedMatched[dst] == 0 || dfs(shedMatched[dst]))
            {
                cowMatched[src] = dst;
                shedMatched[dst] = src;
                return true;
            }
        }
    }

    //src(소)가 매칭 될 곳이 없는 경우.
    return false; 
}