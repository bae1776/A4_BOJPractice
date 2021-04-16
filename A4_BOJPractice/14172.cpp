//https://www.acmicpc.net/problem/14172

//Moocast
//존 목장의 소들은 moo-cast라는 시스템으로 그들끼리 중요한 메시지를 전달하길 원합니다.
//소들은 먼 거리에서 서로 음메하는 대신, 무전기를 사용하기로 했습니다.
//그런데 각 소가 가진 무전기에는 파워 P가 있어 P가 넘는 거리로는 송신할 수 없습니다.
//다행히, 각 소들은 모든 소들한태 일일히 직접 전달할 필요 없이, 다른 소를 거쳐서 송신하는 것은 가능합니다.

//소마다 송신 능력이 다르기 때문에, 몇몇 소가 더 많은 소에게 메시지를 전달하기 유리합니다.
//가장 많은 소에게 메시지를 전달할 수 있는 소를 찾아서 그 소의 메시지를 받을 수 있는
//최대 수신자 수를 구하세요. (수신자는 전달하는 소 자신도 포함함)

//첫 번째 줄엔 소 마리 수 N이 주어지고 (최대 200마리)
//그 다음 N줄의 각 소의 x, y 좌표(0 ~ 25000), 무전기 송신 파워 P가 각각 주어집니다.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
enum { X_POS, Y_POS, POWER };

int dfs(const vector<vector<int>>& adjList, const int& cow, int startCow);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int cow;
    cin >> cow;

    vector<vector<int>> adjList(cow);
    vector<int[3]> cowInfo(cow);

    for (int cowA = 0; cowA < cow; cowA++)
    {
        cin >> cowInfo[cowA][X_POS] >> cowInfo[cowA][Y_POS] >> cowInfo[cowA][POWER];
        cowInfo[cowA][POWER] *= cowInfo[cowA][POWER];

        for (int cowB = 0; cowB < cowA; cowB++)
        {
            int distSquare = (cowInfo[cowA][X_POS] - cowInfo[cowB][X_POS]) * (cowInfo[cowA][X_POS] - cowInfo[cowB][X_POS])
                            +(cowInfo[cowA][Y_POS] - cowInfo[cowB][Y_POS]) * (cowInfo[cowA][Y_POS] - cowInfo[cowB][Y_POS]);
            
            if (distSquare <= cowInfo[cowA][POWER])
                adjList[cowA].push_back(cowB);

            if (distSquare <= cowInfo[cowB][POWER])
                adjList[cowB].push_back(cowA);
        }
    }
    
    int maxCount = 1;
    for (int startCow = 0; startCow < cow && maxCount != cow; startCow++)
        maxCount = max(maxCount, dfs(adjList, cow, startCow));

    cout << maxCount;

	return 0;
}


int dfs(const vector<vector<int>>& adjList, const int& cow, int startCow)
{
    int visitedCount = 0;
    bool* visited = new bool[cow];
    for (int i = 0; i < cow; i++)
        visited[i] = false;
    
    queue<int> dfsQueue;
    dfsQueue.push(startCow);

    do {
        int nowCow = dfsQueue.front();
        dfsQueue.pop();

        if (visited[nowCow] == true)
            continue;
        visited[nowCow] = true;
        visitedCount++;

        for (const int& adjNumber : adjList[nowCow])
            if (visited[adjNumber] == false)
                dfsQueue.push(adjNumber);
    } while (dfsQueue.empty() == false);
    
    delete[] visited;
    return visitedCount;
}