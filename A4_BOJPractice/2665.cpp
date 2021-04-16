//https://www.acmicpc.net/problem/2665

//미로 만들기
//미로에는 흰 방과 검은 방이 있고, 왼쪽 위(시작방)에서 오른쪽 아래 방(끝방)으로 가려고 한다.
//이 중 검은 방은 벽으로 둘러싸여 지나갈 수 없다.
//그러나 어떤 미로는 끝방으로 갈 수 있는 방법이 없기 때문에
//가능한 적은 수의 검은 방을 흰 방으로 바꾸어서 끝방으로 가고 싶다.
//정사각형 미로가 주어질 때, (최대 길이 50) 끝방까지 가기 위하여 바꿔야할 검은 방의 최소 개수를 구하시오.

#include <iostream>
using namespace std;
#define INF 987654321

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

    int mazeSize;
    cin >> mazeSize;

    char** maze = new char*[mazeSize];
    bool** visited = new bool*[mazeSize];
    int** minCost = new int*[mazeSize];

    for (int i = 0; i < mazeSize; i++)
    {
        maze[i] = new char[mazeSize];
        visited[i] = new bool[mazeSize];
        minCost[i] = new int[mazeSize];
        
        for (int j = 0; j < mazeSize; j++)
        {
            cin >> maze[i][j];
            maze[i][j] = '1' - maze[i][j];
            visited[i][j] = false;
            minCost[i][j] = INF;
        }
    }

    int nowVisit_y = 0, nowVisit_x = 0;
    minCost[0][0] = 0;

     do {
            visited[nowVisit_y][nowVisit_x] = true;
            
            if (nowVisit_y > 0)
                minCost[nowVisit_y - 1][nowVisit_x]
                    = min(minCost[nowVisit_y - 1][nowVisit_x], minCost[nowVisit_y][nowVisit_x] + maze[nowVisit_y - 1][nowVisit_x]);
            
            if (nowVisit_y + 1 < mazeSize)
                minCost[nowVisit_y + 1][nowVisit_x]
                    = min(minCost[nowVisit_y + 1][nowVisit_x], minCost[nowVisit_y][nowVisit_x] + maze[nowVisit_y + 1][nowVisit_x]);

            if (nowVisit_x > 0)
                minCost[nowVisit_y][nowVisit_x - 1]
                    = min(minCost[nowVisit_y][nowVisit_x - 1], minCost[nowVisit_y][nowVisit_x] + maze[nowVisit_y][nowVisit_x - 1]);

            if (nowVisit_x + 1 < mazeSize)
                minCost[nowVisit_y][nowVisit_x + 1]
                    = min(minCost[nowVisit_y][nowVisit_x + 1], minCost[nowVisit_y][nowVisit_x] + maze[nowVisit_y][nowVisit_x + 1]);

            int nowMin = INF;
            int nextMin_x = INF, nextMin_y = INF;
            for (int y = 0; y < mazeSize; y++)
                for (int x = 0; x < mazeSize; x++)
                    if (visited[y][x] == false && minCost[y][x] < nowMin)
                    {
                        nowMin = minCost[y][x];
                        nextMin_x = x; nextMin_y = y;
                    }

            nowVisit_x = nextMin_x;
            nowVisit_y = nextMin_y;

        } while (nowVisit_x != INF);

    std::cout << minCost[mazeSize - 1][mazeSize - 1];

    for (int i = 0; i < mazeSize; i++)
    {
        delete[] maze[i];
        delete[] visited[i];
        delete[] minCost[i];
    }

    delete[] maze;
    delete[] visited;
    delete[] minCost;
    
	return 0;
}
