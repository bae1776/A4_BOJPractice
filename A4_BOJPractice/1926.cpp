//https://www.acmicpc.net/problem/1926

/* 그림 (Silver 1)
어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와 가장 넓은 그림의 넓이를 출력하여라.
그림이라는 것은 1로 연결 된 것을 한 그림이라고 정의한다. (대각선으로 연결된 것은 별개로 취급)

Solution : BFS
*/

#include <iostream>
#include <queue>
using namespace std;

int paper[500][500];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> paper[i][j];

    int pictureCount = 0, pictureMax = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (paper[i][j] == 1)
            {
                int pictureSize = 0;
                pictureCount++;
                queue<pair<int, int>> bfsQueue;
                bfsQueue.emplace(i, j);
                paper[i][j]++;

                while (bfsQueue.empty() == false)
                {
                    auto [y, x] = bfsQueue.front();
                    bfsQueue.pop();
                    pictureSize++;

                    if (y != 0 && paper[y - 1][x] == 1)
                    {
                        paper[y - 1][x]++;
                        bfsQueue.emplace(y - 1, x);
                    }

                    if (y != row - 1 && paper[y + 1][x] == 1)
                    {
                        paper[y + 1][x]++;
                        bfsQueue.emplace(y + 1, x);
                    }

                    if (x != 0 && paper[y][x - 1] == 1)
                    {
                        paper[y][x - 1]++;
                        bfsQueue.emplace(y, x - 1);
                    }

                    if (x != col - 1 && paper[y][x + 1] == 1)
                    {
                        paper[y][x + 1]++;
                        bfsQueue.emplace(y, x + 1);
                    }

                }

                pictureMax = max(pictureMax, pictureSize);
            }
        }
    }

    cout << pictureCount << '\n' << pictureMax;
    
	return 0;
}
