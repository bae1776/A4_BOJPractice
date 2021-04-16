//https://www.acmicpc.net/problem/10217

//KCM Travel (Gold 1)
//LA에서 구글 코드 대회에 출전하게 된 찬민이는 구글이 항공비에 상한을 둔 것을 알게 되었다.
//각 공항들간 항공비와 이동시간이 주어질 때, 인천에서 LA로 갈 수 있는 (제한된 항공비 내에서) 가장 빠른 길을 찾아, 그 시간을 출력하시오.
//항공비 제한 안에 LA로 갈 수 없다면 Poor KCM을 출력하시오.
//항상 인천은 1번, LA는 N번 공항이며, 여러 Testcase가 주어지고 각 Testcase 당 공항 수는 최대 100개, 경로 수는 최대 10000개 이다.

//DP와 다익스트라를 섞어서 풀어야한다.

#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int timeDP[101][10001]; //Time for airport and cost 

struct Airline {
    int dest;
    int time;
    int cost;

    Airline(int d, int t, int c) : dest(d), time(t), cost(c) {};
    
    bool operator<(const Airline& right) const 
    {
        return this->time > right.time;
    }
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int testcase;
    cin >> testcase;

    for (int tc = 0; tc < testcase; tc++)
    {
        int airport, maxCost, airlineCount;
        cin >> airport >> maxCost >> airlineCount;

        for (int i = 1; i <= airport; i++)
            for (int j = 0; j <= maxCost; j++)
                timeDP[i][j] = INF;

        vector<vector<Airline>> airlineInfo(airport + 1);
        for (int i = 0; i < airlineCount; i++)
        {
            int start, end, cost, time;
            cin >> start >> end >> cost >> time;
            airlineInfo[start].emplace_back(end, time, cost);
        }

        priority_queue<Airline> dijkstra_pQueue;
        timeDP[1][0] = 0;
        dijkstra_pQueue.emplace(1, 0, 0);

        do {
            Airline nowState = dijkstra_pQueue.top();
            dijkstra_pQueue.pop();

            if (nowState.time > timeDP[nowState.dest][nowState.cost])
                continue;

            for (Airline& airline : airlineInfo[nowState.dest])
            {
                int totalTime = nowState.time + airline.time;
                int totalCost = nowState.cost + airline.cost;

                if (totalCost <= maxCost && totalTime < timeDP[airline.dest][totalCost])
                {
                    timeDP[airline.dest][totalCost] = totalTime;
                    dijkstra_pQueue.emplace(airline.dest, totalTime, totalCost);
                } else
                    continue;
            }
        } while (dijkstra_pQueue.empty() == false);

        int minCost = INF;
        for (int cost = 0; cost <= maxCost; cost++)
            minCost = min(minCost, timeDP[airport][cost]);

        if (minCost == INF)
            cout << "Poor KCM";
        else
            cout << minCost;
        cout << '\n';
        
    }


	return 0;
}

