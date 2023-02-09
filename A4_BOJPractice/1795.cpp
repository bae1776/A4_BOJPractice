//https://www.acmicpc.net/problem/1795

/*마알 (Gold 4)

각 말에 대해 특정 보드 칸에 도달할 수 있는 최소 이동 횟수를 BFS로 구한뒤에
이를 각 원소끼리 모두 합친다. 합친 행렬에서 최소 원소값이 최소 이동 횟수이다.
칸의 수는 최대 N = 100이고, 시간 복잡도 O(N^2)에 풀 수 있다.
*/

#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <tuple>
using namespace std;
constexpr int MAX = 0x7FFFFF;
int row, col;
constexpr int kx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int ky[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

vector<vector<int>> knightBFS(int startY, int startX, int maxMove);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;
    list<vector<vector<int>>> knightMoveList;

    char input;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> input;
            if (input != '.')
                knightMoveList.emplace_back(knightBFS(i, j, input - '0'));
        }

    vector<vector<int>> knightMoveSum(row, vector<int>(col, 0));
    for (const auto& knightBoard : knightMoveList)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                knightMoveSum[i][j] += knightBoard[i][j];
    }

    int result = MAX;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result = min(result, knightMoveSum[i][j]);
    
    if (result == MAX)
        cout << -1;
    else    
        cout << result;

	return 0;
}


vector<vector<int>> knightBFS(int startY, int startX, int maxMove)
{
    vector<vector<int>> moveBoard(row, vector<int>(col, MAX));
    
    moveBoard[startY][startX] = 0;
    queue<tuple<int, int, int>> bfsQueue;
    bfsQueue.emplace(startY, startX, 0);

    while (bfsQueue.empty() == false)
    {
        auto [y, x, move] = bfsQueue.front();
        bfsQueue.pop();

        for (int k = 0; k < 8; k++)
        {
            if (0 <= y + ky[k] && y + ky[k] < row && 0 <= x + kx[k] && x + kx[k] < col
                && moveBoard[y + ky[k]][x + kx[k]] == MAX)
            {
                bfsQueue.emplace(y + ky[k], x + kx[k], move + 1);
                moveBoard[y + ky[k]][x + kx[k]] = move / maxMove + 1;
            }    
        }
    }



    return moveBoard;

}