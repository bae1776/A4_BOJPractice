//https://www.acmicpc.net/problem/11657

/*타임머신

단방향성 정수 가중치 그래프가 주어진다. (정점 최대 500, 간선 최대 6000개)

타임머신을 타고 도시 사이를 이동하는데, 어떤 이동 경로는 시간이 거꾸로 되돌아 갈 수도 있다.
1번 도시에서 2~N번 도시로 가는데 걸리는 최소 시간을 출력하시오.
만약 어떤 도시로 가는 과정에서 시간을 무한정 오래 전으로 돌릴 수 있으면, -1만 출력하시오.
특정 도시로 가는 경로가 없으면 -1을 출력하시오.

벨만-포드 알고리즘을 사용하라.

*/

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define INF 0x3FFFFFFFFFFFFFFFll

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int vertex, edge;
    cin >> vertex >> edge;

    vector<long long> minDist(vertex + 1, INF);
    minDist[1] = 0;
    vector<tuple<int, int, int>> edgeList(edge);

    for (int i = 0; i < edge; i++)
        cin >> get<0>(edgeList[i]) >> get<1>(edgeList[i]) >> get<2>(edgeList[i]);

    bool infiniteCycle = false;
    for (int i = 1; i <= vertex; i++)
    {
        int start, end, weight;
        for (int j = 0; j < edge; j++)
        {
            tie(start, end, weight) = edgeList[j];
            if (minDist[start] == INF)
                continue;

            if (minDist[start] + weight < minDist[end])
            {
                minDist[end] = minDist[start] + weight;
                if (i == vertex) //Vertex번째 갱신이 실제로 되면 안된다.
                {
                    infiniteCycle = true;
                    break;
                }
            }
        }
        if (infiniteCycle)  break;
    }

    if (infiniteCycle)
        cout << "-1";
    else
        for (int i = 2; i <= vertex; i++)
            if (minDist[i] == INF)
                cout << "-1\n";
            else
                cout << minDist[i] << '\n';

    return 0;
}
