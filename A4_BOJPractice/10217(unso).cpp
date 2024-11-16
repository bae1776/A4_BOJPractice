//https://www.acmicpc.net/problem/10217

/*KCM Travel (Platinum 5)
LA에서 구글 코드 대회에 출전하게 된 찬민이는 구글이 항공비에 상한을 둔 것을 알게 되었다.
각 공항들간 항공비와 이동시간이 주어질 때, 인천에서 LA로 갈 수 있는 (제한된 항공비 내에서) 가장 빠른 길을 찾아, 그 시간을 출력하시오.
항공비 제한 안에 LA로 갈 수 없다면 Poor KCM을 출력하시오.
항상 인천은 1번, LA는 N번 공항이며, 여러 Testcase가 주어지고 각 Testcase 당 공항 수는 최대 100개,
지원 경비는 최대 10000, 경로 수는 최대 10000개 이다.

비용에 대한 다익스트라를 하고, 주어진 경비를 초과했거나 더 비효율적인 경로에 대해서는 자른다.

DP와 다익스트라를 섞어서 풀어야한다.
맞왜틀 런타임에러(Out OF Bound) 억까임 안함
*/

#include <iostream>
#define INF 98765432
using namespace std;

struct Airline {
    int dest;
    int time;
    int cost;
};


int DP[102][10002];             //DP[dest][cost] = time 
bool visited[102];
int minTime[102];
int airCount[102];
Airline airlineInfo[102][10002];//airlineInfo[start][index] = Airline(dest, time, cost)


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int airport, costLimit, airlineCount;
        cin >> airport >> costLimit >> airlineCount;

        for (int air = 0; air <= airport; air++)
        {
            visited[air] = false;
            minTime[air] = INF;
            airCount[air] = 0;
            for (int cost = 0; cost <= costLimit; cost++)
                DP[air][cost] = INF;
        }


        for (int i = 0; i < airlineCount; i++)
        {
            int start, end, cost, time;
            cin >> start >> end >> cost >> time;
            airCount[start]++;
            airlineInfo[start][airCount[start]].dest = end;
            airlineInfo[start][airCount[start]].cost = cost;
            airlineInfo[start][airCount[start]].time = time;
        }

        DP[1][0] = 0;
        int nowVisit = 1;

        do {
            visited[nowVisit] = true;
            for (int to = 1; to <= airCount[nowVisit]; to++)
            {
                int& dest = airlineInfo[nowVisit][to].dest;
                int& time = airlineInfo[nowVisit][to].time;
                int& cost = airlineInfo[nowVisit][to].cost;

                for (int c = 0; c + cost <= costLimit; c++)
                {
                    if (DP[nowVisit][c] + time < DP[dest][c + cost])
                    {
                        DP[dest][c + cost] = DP[nowVisit][c] + time;
                        minTime[dest] = min(minTime[dest], DP[dest][c + cost]);
                    }
                }
            }

            nowVisit = 0;
            for (int next = 1; next <= airlineCount; next++)
            {
                if (visited[next] == false && minTime[next] < minTime[nowVisit])
                    nowVisit = next;
            }
        } while (nowVisit != 0);

        int result = INF;
        for (int cost = 0; cost <= costLimit; cost++)
            result = min(result, DP[airport][cost]);

        if (result == INF)
            cout << "Poor KCM";
        else
            cout << result;
        cout << '\n';

    }


    return 0;
}

