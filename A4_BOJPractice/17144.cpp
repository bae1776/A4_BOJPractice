//https://www.acmicpc.net/problem/17144

/* 미세먼지 안녕 (Gold 4)
미세먼지 제거를 위해 방에 공기청정기를 설치했다. 
방에서 미세먼지를 측정할 단위를 격자형(R * C, 각각 최대 50)으로 나누었다.
각 칸에는 숫자가 들어가는 데, -1인 경우 공기청정기, 0이면 깨끗한 공기이며
자연수인 경우 미세먼지 농도를 나타낸다.
1초 동안 다음과 같은 일이 순서대로 일어난다.

1. 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산하는데, 인접한 방향에 공기청정기가 있거나 칸이 없는 경우에는 확산하지 않는다.
확산되는 양은 A(r,c)/5 (소수점 버림)이고, 확산된 만큼 A(r,c)의 미세먼지는 줄어든다.

2. 공기청정기를 작동한다.
공기청정기에서는 바람이 나오는데, 공기청정기의 위쪽 바람은 반시계, 아랫쪽 바람은 시계방향으로 순환한다.
바람에 영향을 받는 모든 미세먼지는 한 칸씩 이동하며, 공기청정기에서 나오는 바람은 깨끗한 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

공기청정기는 항상 1열에 위치하며, 두 행을 차지하며, 가장 위, 아랫 행과 2칸 이상 떨어져있다.
방의 정보가 주어졌을 때, T(최대 1000)초 후의 방의 미세먼지 총량을 구하여라.

Solution : 시뮬레이션 (브루트포스/구현)
*/

#include <iostream>
#include <queue>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int row, col, time;
    cin >> row >> col >> time;

    int airPurifierLoc;
    vector<vector<int>> room(row, vector<int>(col));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1)
                airPurifierLoc = i;
        }

    while (time--)
    {
        //1. 미세먼지 확산 페이즈
        vector<vector<int>> emptyRoom(row, vector<int>(col, 0));
        emptyRoom[airPurifierLoc - 1][0] = emptyRoom[airPurifierLoc][0] = -1;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int diffuse = room[i][j] / 5;
                if (diffuse <= 0)
                {
                    if (room[i][j] > 0)
                        emptyRoom[i][j] += room[i][j];
                    continue;
                }

                int diffuseCount = 0;

                if (i != 0 && emptyRoom[i - 1][j] != -1)
                {
                    diffuseCount++;
                    emptyRoom[i - 1][j] += diffuse;
                }

                if (i != row - 1 && emptyRoom[i + 1][j] != -1)
                {
                    diffuseCount++;
                    emptyRoom[i + 1][j] += diffuse;
                }

                if (j != 0 && emptyRoom[i][j - 1] != -1)
                {
                    diffuseCount++;
                    emptyRoom[i][j - 1] += diffuse;
                }

                if (j != col - 1 && emptyRoom[i][j + 1] != -1)
                {
                    diffuseCount++;
                    emptyRoom[i][j + 1] += diffuse;
                }

                emptyRoom[i][j] += room[i][j] - diffuseCount * diffuse;
                
            }
        }

        //2. 공기 청정기 페이즈
        //상부 반시계 방향
        for (int i = airPurifierLoc - 2; i >= 1; i--)
            emptyRoom[i][0] = emptyRoom[i - 1][0];
        for (int i = 0; i < col - 1; i++)
            emptyRoom[0][i] = emptyRoom[0][i + 1];
        for (int i = 0; i < airPurifierLoc - 1; i++)
            emptyRoom[i][col - 1] = emptyRoom[i + 1][col - 1];
        for (int i = col - 1; i >= 2; i--)
            emptyRoom[airPurifierLoc - 1][i] = emptyRoom[airPurifierLoc - 1][i - 1];
        emptyRoom[airPurifierLoc - 1][1] = 0;

        //하부 시계 방향
        for (int i = airPurifierLoc + 1; i < row - 1; i++)
            emptyRoom[i][0] = emptyRoom[i + 1][0];
        for (int i = 0; i < col - 1; i++)
            emptyRoom[row - 1][i] = emptyRoom[row - 1][i + 1];
        for (int i = row - 1; i > airPurifierLoc; i--)
            emptyRoom[i][col - 1] = emptyRoom[i - 1][col - 1];
        for (int i = col - 1; i >= 2; i--)
            emptyRoom[airPurifierLoc][i] = emptyRoom[airPurifierLoc][i - 1];
        emptyRoom[airPurifierLoc][1] = 0;

        room = emptyRoom;
    }

    int dustSum = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (room[i][j] > 0)
                dustSum += room[i][j];
        }

    cout << dustSum;

    return 0;
}