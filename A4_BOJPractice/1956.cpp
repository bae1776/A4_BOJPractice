//https://www.acmicpc.net/problem/1956

/*운동

단방향성 양수 가중치 그래프가 주어진다. (정점 최대 400개)

그래프에서 가장 짧은 사이클을 구하여라.
사이클이 하나도 없다면 -1을 출력하시오.

*/

#include <iostream>
#include <vector>
using namespace std;
#define INF 0x3FFFFFFF

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int vertex, edge;
    cin >> vertex >> edge;

    vector<vector<int>> edgeList(vertex + 1, vector<int>(vertex + 1, INF));

    int start, end, weight;
    for (int i = 0; i < edge; i++)
    {
        cin >> start >> end >> weight;
        edgeList[start][end] = weight;
    }

    for (int i = 1; i <= vertex; i++)
        edgeList[i][i] = 0;

    //Floyd-Wershall
    for (int via = 1; via <= vertex; via++)
        for (start = 1; start <= vertex; start++)
            for (end = 1; end <= vertex; end++)
                if (edgeList[start][via] + edgeList[via][end] < edgeList[start][end])
                    edgeList[start][end] = edgeList[start][via] + edgeList[via][end];

    int result = INF;

    for (start = 1; start <= vertex; start++)
        for (int midPoint = start + 1; midPoint <= vertex; midPoint++)
            if (edgeList[start][midPoint] + edgeList[midPoint][start] < result)
                result = edgeList[start][midPoint] + edgeList[midPoint][start];

    if (result == INF)
        cout << "-1";
    else
        cout << result;

    return 0;

}