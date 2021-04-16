//https://www.acmicpc.net/problem/14938

//서강그라운드
//어떤 한 지점에 착지하여 그 지점과 지점 인근에 있는 아이템을 최대한 많이 얻고 싶다.
//각 지점에 있는 아이템 갯수와, 지점 간의 거리가 주어지고
//착지 지점에서 아이템을 얻을 수 있는 지점의 최대 제한 거리가 주어질때
//가장 아이템을 많이 얻었을 경우의 아이템 갯수를 구하시오.

#include <vector>
#include <iostream>
#define INF 0x3FFFFFFF
using namespace std;
using Board = vector<vector<int>>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int node, coverRange, edge;
    cin >> node >> coverRange >> edge;

    vector<int> itemCountList(node);
    Board adjList(node, vector<int>(node, INF));

    for (int i = 0; i < node; i++)
    {
        cin >> itemCountList[i];
        adjList[i][i] = 0;
    }

    for (int i = 0; i < edge; i++)
    {
        int start, end, length;
        cin >> start >> end >> length;

        adjList[start - 1][end - 1] = length;
        adjList[end - 1][start - 1] = length;
    } 
    
    //Floyd
    for (int via = 0; via < node; via++)
        for (int start = 0; start < node; start++)
            for (int end = 0; end < node; end++)
                adjList[start][end] = min(adjList[start][end], adjList[start][via] + adjList[via][end]);
    

    int maxAvailableItem = 0;
    for (int landed = 0; landed < node; landed++)
    {
        int availableItem = 0;
        for (int target = 0; target < node; target++)
        {
            if (adjList[landed][target] <= coverRange)
                availableItem += itemCountList[target];
        }
        maxAvailableItem = max(availableItem, maxAvailableItem);
    }


    cout << maxAvailableItem;

	return 0;
}