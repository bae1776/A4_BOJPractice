//https://www.acmicpc.net/problem/2150

/*Strongly Connected Component (Platinum 5)

방향 그래프의 강한 연결 요소 기본 문제

강한 연결 요소 알고리즘은 대표적으로 2가지 인데, 코사라주/타잔 중
타잔 알고리즘을 이용함. https://hyeo-noo.tistory.com/130

*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edgeList[10001];
vector<vector<int>> sscList;
int vertexId[10001];
bool finished[10001];
stack<int> sscStack;
int vertex, edge, id;

int SSC(int x);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> vertex >> edge;

    while (edge--)
    {
        int start, end;
        cin >> start >> end;
        edgeList[start].emplace_back(end);
    }

    for (int i = 1; i <= vertex; i++)
        if (vertexId[i] == 0) SSC(i);

    cout << sscList.size() << '\n';
    
    for (int i = 0; i < sscList.size(); i++)
        sort(sscList[i].begin(), sscList[i].end());

    sort(sscList.begin(), sscList.end(), [](const auto& vec1, const auto& vec2) -> bool {
        return vec1[0] < vec2[0];
    });

    for (const auto& vec : sscList)
    {   
        for (const auto& vecElement : vec)
            cout << vecElement << ' ';
        cout << -1 << '\n';
    }

	return 0;
}


int SSC(int x)
{
    int result = vertexId[x] = ++id;
    //정점 방문 순서대로 전역 스택에 정점 번호를 push.
    sscStack.push(x);

    for (const auto& nextVertex : edgeList[x])
    {
        //vertexId는 DFS의 방문 순서대로 매겨진다.
        //First If : 아직 방문하지 않은 인접 정점을 방문한다.
        if (vertexId[nextVertex] == 0)
            result = min(result, SSC(nextVertex));
        //Second If : 방문은 했으나 SSC를 이루지 못한 정점인 경우,
        //result 값으로 그 정점의 방문 순서값(vertexId)를 취할 수 있다. (단, 그 정점이 먼저 방문했을 경우만)
        else if (finished[nextVertex] == false)
            result = min(result, vertexId[nextVertex]);
    }

    //다음 조건을 만족하면 ssc를 하나 생성한다. 조건의 만족 조건은
    //1. 해당 노드(x)에서 출발하는 간선이 없는 경우 (위 for문이 아예 돌지도 않고 홀로 SSC)
    //2. 자신 x가 먼저 방문된 노드이면서(vertexID[x]가 다른 것들보다 제일 작음) 
    //   그 이후 방문한 노드들이 x보다 먼저 방문한 노드로 갈 수 없는 경우 
    //->(First If의 반환값인 SSC(nextVertex)가 result보다 더 작은 값으로 만들어 주지 못함)
    //또한 Second If의 반환값에 의해, 모든 x의 자식 노드들이 x로 돌아 올 수 있음
    if (result == vertexId[x])
    {
        int stackElement;
        sscList.emplace_back(vector<int>());
        do {
            stackElement = sscStack.top();
            finished[stackElement] = true;
            sscStack.pop();
            sscList.rbegin()->push_back(stackElement);
        } while (stackElement != x);
    }

    return result;
}