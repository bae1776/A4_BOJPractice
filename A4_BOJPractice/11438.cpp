//https://www.acmicpc.net/problem/11438

/*LCA 2 (Platinum 5)
Solution : BFS, 다이나믹 프로그래밍, 이분 탐색

최소 공통 조상 문제로 LCA 기본 문제와 달리 정점이 10만개, 쿼리가 10만개이므로
각 쿼리가 최대 트리의 깊이인 단순 선형 탐색으로 조상을 찾는 것은 시간이 너무 오래 걸린다.

아래와 같은 방법을 이용하면 각 쿼리를 O(log(TreeHeight))로 처리할 수 있어
정점 10만개가 완전 편향트리여도 시간 내에 충분히 풀 수 있다.

parent[Node][k] = Node번의 2^k 번째 조상이라고 하자. (조상이 없는 경우 0)
이때 점화식
parent[Node][k] = parent[parent[Node][k-1]][k-1]이 성립한다.
그리고 트리를 BFS 탐색하면 기저인 parent[Node][0]은 바로(O(1)) 알 수 있다.

위 배열을 이용하면 최소 공통 조상을 찾는 함수를 짜는 데 어려움은 없을 것이다.
(두 노드의 높이 맞추기) -> (parent의 k를 하나씩 줄여가면서 공통 조상 찾기)
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;
#define NODE 100001

int parent[NODE][18];
int level[NODE];
list<int> adj[NODE];

int LCA(int a, int b);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeCount;
    cin >> nodeCount;

    for (int i = 0; i < nodeCount - 1; i++)
    {
        int start, end;
        cin >> start >> end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    //트리 bfs 돌면서 level 배열과 parent 배열값을 모두 구해준다.

    queue<pair<int, int>> bfsQueue; //parent, now
    bfsQueue.emplace(0, 1);

    int depth = 0;
    int maxJump = 0;
    
    while (bfsQueue.empty() == false)
    {
        int queueSize = bfsQueue.size();

        while (queueSize--)
        {
            auto& now = bfsQueue.front();

            level[now.second] = depth;
            parent[now.second][0] = now.first;
            for (int jump = 1; jump < maxJump; jump++)
                parent[now.second][jump] 
                    = parent[parent[now.second][jump - 1]][jump - 1];

            for (auto& next : adj[now.second])
            {
                if (next != now.first)
                    bfsQueue.emplace(now.second, next);
            }

            bfsQueue.pop();
        }
        
        depth++;
        if (depth >= (1 << maxJump))
            maxJump++;
    }


    //최대 공통 조상 쿼리 입력
    int queryCount;
    cin >> queryCount;

    while (queryCount--)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

	return 0;
}


int LCA(int a, int b)
{
    int levelGap = level[b] - level[a];

    //1. a, b의 레벨 관계가 a <= b로 일관되게 한다.
    if (levelGap < 0)
    {
        swap(a, b);
        levelGap = -levelGap;
    }

    //2. a, b의 레벨을 똑같이 맞춘다. (b의 레벨을 올린다)
    //제곱으로 올려야 log 내에 처리된다.
    for (int jump = 0; levelGap != 0; jump++)
    {
        if (levelGap & (1 << jump))
        {
            levelGap -= (1 << jump);
            b = parent[b][jump];
        }
    }

    //3. a, b의 레벨을 공통 조상이 될 때까지 제곱으로 올린다.
    if (a != b)
    {
        int maxJump = 0;
        while (level[a] > (2 << maxJump))
            maxJump++;
        //예를 들어 a, b이 16 Level이면 +8, +4, +2, +1 순으로 탐색해야 하므로
        //maxJump = 3이 된다.


        //a, b가 10 Level이고 공통 조상이 1 Level이라 하자.
        //maxJump = 3 이고
        //첫번째 루프에서 a, b는 갱신된다. (2 Level인 서로 다른 두 노드)
        //두번째 루프에서 갱신되지 않는다. if (0 != 0) 에서 걸림
        //세번째 루프에서 갱신되지 않는다.
        //네번째 루프에서 갱신되지 않는다. 그리고 반복문을 빠져 나온다.
        for ( ; maxJump >= 0; maxJump--)
        {
            if (parent[a][maxJump] != parent[b][maxJump])
            {
                a = parent[a][maxJump];
                b = parent[b][maxJump];
            }
        }

        //위 루프가 끝나면 두 노드는 반드시 공통 조상 바로 다음 레벨에 존재한다.
        return parent[a][0];
    }
    
    //-> 2.에서 레벨을 똑같이 맞춘것만으로도 공통 조상이 된 경우
    return a;
}
