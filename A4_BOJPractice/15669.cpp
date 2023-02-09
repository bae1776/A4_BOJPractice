//https://www.acmicpc.net/problem/15669

/* 나무 위의 입자 (Platinum 5)

Solution : 
정점이 최대 10만개이므로 단순 탐색으론 해결할 수 없다.

이 문제는 각 노드에 메모이제이션함으로써 해결 가능하다. (DP)
정점들을 모두 Red, Black으로 칠하는 데, 이웃된 정점은 다른 색을 칠한다.
이때, 아무 노드를 루트 노드로 삼고 각 노드에는 자신을 포함한 서브트리의 Red 노드 개수, Black 노드 개수를 저장한다.
이는 DFS 재귀 함수를 이용해 O(N)으로 처리 가능하다.

1. 어떤 실험에서 도착점 
색상이 빨간색인 경우 경로의 길이가 2, 4, 6... 임을 의미하고
색상이 검정색인 경우 경로의 길이가 1, 3, 5... 임을 의미한다.
이 말은 빨간색 실험은 출발점, 도착점의 노드 색이 같고, 검정색 실험은 색이 다르다고 할 수 있다.

2. 그 다음 U->V 실험 방향이 중요하다. 
실험(에지) 방향이 루트 노드에서 멀어지는 방향이면,
그 실험은 반드시 시작점이 (V의 서브트리에 속하지 않는 노드), 도착점은 (V 서브트리에 속한 노드)이며
실험(에지) 방향이 루트 노드로 가까워진다면, 
그 실험은 반드시 시작점이 (U의 서브트리에 속한 노드), 도착점은 (U 서브트리에 속하지 않는 노드)이다.

1. 2.를 조합하면, 구하려는 답을 아주 쉽게 구할 수 있다.
예를 들어, 한 실험 A B 1이 입력될 때, A의 depth < B의 depth라 하자.
이는 실험 방향이 루트 노드에서 멀어짐을 의미한다.
그리고 도착점 도달시 검은색이므로 1.에 의해 시작점 노드 색과, 도착점 노드 색은 다르다.
그러면 이 실험의 결과 값 = (Red[root] - Red[B]) * Black[B] + (Black[root] - Black[B]) * Red[B] 이다.
여기서 Red/Black[root] = 트리의 총 Red/Black 노드 개수와 동치이다. 
*/

#include <iostream>
#include <list>
using namespace std;

struct Node {
    int level;
    long long blackCount;
    long long redCount;
    list<int> connected;
};

Node tree[100001];
bool visited[100001];

void dfsMemoization(const int& nodeNumber, int level, bool isBlack);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int nodeCount, experimentCount;
    cin >> nodeCount >> experimentCount;

    for (int i = 0; i < nodeCount - 1; i++)
    {
        int start, end;
        cin >> start >> end;

        tree[start].connected.push_back(end);
        tree[end].connected.push_back(start);
    }    

    const int root = 1;
    dfsMemoization(root, 1, true);

    while (experimentCount--)
    {
        int parent, child; 
        bool isBlack;

        cin >> parent >> child >> isBlack;

        if (tree[parent].level > tree[child].level)
            swap(parent, child);

        long long result = 0;
        
        if (isBlack)
        {
            result += (tree[root].blackCount - tree[child].blackCount) * tree[child].redCount;
            result += (tree[root].redCount - tree[child].redCount) * tree[child].blackCount;
        } else {
            result += (tree[root].blackCount - tree[child].blackCount) * tree[child].blackCount;
            result += (tree[root].redCount - tree[child].redCount) * tree[child].redCount;
        }

        cout << result << '\n';
    }


    return 0;
}




void dfsMemoization(const int& nodeNumber, int level, bool isBlack)
{
    auto& cur = tree[nodeNumber];
    cur.level = level;
    visited[nodeNumber] = true;

    for (const int& next : cur.connected)
    {
        if (visited[next]) continue;
        
        dfsMemoization(next, level + 1, !isBlack);
        cur.blackCount += tree[next].blackCount;
        cur.redCount += tree[next].redCount;
    }

    if (isBlack)
        cur.blackCount++;
    else
        cur.redCount++;
    
}
