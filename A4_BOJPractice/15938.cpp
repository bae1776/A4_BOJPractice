//https://www.acmicpc.net/problem/15938

/*더위 피하기 (Gold 3)
Solution : DP + BFS
성원이가 이동할 수 있는 시간은 200초에 불과하기 때문에
많이 이동해봐야 성원이의 위치에서 200만큼 움직일 수 있다.

즉, 어차피 도달할 수 없는 경우를 적당히 가지치기한 BFS를 하면 
최악의 경우에도 400 * 400 * 200 정도의 시간에 풀 수 있을 것이다.

*/

#include <iostream>
#include <queue>
#define DIV 1000000007
using namespace std;

int DP[401][401][201];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int manX, manY, timeLimit;
    DP[200][200][0] = 1;
    cin >> manX >> manY;
    cin >> timeLimit;

    int homeX, homeY;
    cin >> homeX >> homeY;
    homeX = homeX - manX + 200;
    homeY = homeY - manY + 200;

    int trapCount;
    cin >> trapCount;
    while (trapCount--)
    {
        int x, y;
        cin >> x >> y;
        x = x - manX + 200;
        y = y - manY + 200;

        if (0 <= x && x <= 400 && 0 <= y && y <= 400)
        {
            for (int i = 0; i <= timeLimit; i++)
                DP[y][x][i] = -1;
        }
    }

    if (abs(homeX - 200) + abs(homeY - 200) <= timeLimit)
    {
        queue<pair<int, int>> bfsQueue;
        bfsQueue.emplace(200, 200);

        for (int time = 0; time < timeLimit; time++)
        {
            int nowDepthCount = bfsQueue.size();

            while (nowDepthCount--)
            {
                auto [y, x] = bfsQueue.front();
                bfsQueue.pop();

                if (y == homeY && x == homeX)
                    continue;
                
                //남은 거리가 남은 시간보다 긴 경우는 어차피 집까지 갈 수 없으므로
                //가지치기한다.
                if (abs(y - homeY) + abs(x - homeX) > timeLimit - time)
                    continue;

                if (DP[y+1][x][time + 1] != -1)
                {
                    if (DP[y+1][x][time + 1] == 0)
                        bfsQueue.emplace(y + 1, x);
                    DP[y+1][x][time + 1] += DP[y][x][time];
                    DP[y+1][x][time + 1] %= DIV;
                }

                if (DP[y-1][x][time + 1] != -1)
                {
                    if (DP[y-1][x][time + 1] == 0)
                        bfsQueue.emplace(y - 1, x);
                    DP[y-1][x][time + 1] += DP[y][x][time];
                    DP[y-1][x][time + 1] %= DIV;
                }

                if (DP[y][x+1][time + 1] != -1)
                {
                    if (DP[y][x+1][time + 1] == 0)
                        bfsQueue.emplace(y, x + 1);
                    DP[y][x+1][time + 1] += DP[y][x][time];
                    DP[y][x+1][time + 1] %= DIV;
                }

                if (DP[y][x-1][time + 1] != -1)
                {
                    if (DP[y][x-1][time + 1] == 0)
                        bfsQueue.emplace(y, x - 1);
                    DP[y][x-1][time + 1] += DP[y][x][time];
                    DP[y][x-1][time + 1] %= DIV;
                }
            }
        }

        int total = 0;
        for (int time = 0; time <= timeLimit; time++)
            total = (total + DP[homeY][homeX][time]) % DIV;
        cout << total;
    } else {
        cout << 0;
    }

	return 0;
}
