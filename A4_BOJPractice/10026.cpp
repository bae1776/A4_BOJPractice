//https://www.acmicpc.net/problem/10026

/*적록색약 (Gold 5)
적록색약인 사람은 빨간색과 초록색의 차이를 거의 느끼지 못한다.
R, G, B 중 하나로 칸이 구성된 최대 100x100 보드를 보았을때,
일반인, 적록색약인이 볼 수 있는 구역 개수를 구하시오.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int bfs(const vector<string>& board)
{
    int result = 0;
    int boardLength = board.size();
    queue<pair<int, int>> bfsCoordQueue;
    vector<vector<char>> visited(boardLength, vector<char>(boardLength, false));

    for (int i = 0; i < boardLength; i++)
    {
        for (int j = 0; j < boardLength; j++)
        {
            
            if (visited[i][j] == false)
            {
                visited[i][j] = true;
                char color = board[i][j];
                result++;

                bfsCoordQueue.emplace(i, j);

                while (bfsCoordQueue.empty() == false)
                {
                    const auto& coord = bfsCoordQueue.front();

                    if (coord.first != 0 && visited[coord.first - 1][coord.second] == false && board[coord.first - 1][coord.second] == color)
                    {
                        visited[coord.first - 1][coord.second] = true;
                        bfsCoordQueue.emplace(coord.first - 1, coord.second);
                    }

                    if (coord.first != boardLength - 1 && visited[coord.first + 1][coord.second] == false && board[coord.first + 1][coord.second] == color)
                    {
                        visited[coord.first + 1][coord.second] = true;
                        bfsCoordQueue.emplace(coord.first + 1, coord.second);
                    }

                    if (coord.second != 0 && visited[coord.first][coord.second - 1] == false && board[coord.first][coord.second - 1] == color)
                    {
                        visited[coord.first][coord.second - 1] = true;
                        bfsCoordQueue.emplace(coord.first , coord.second - 1);
                    }

                    if (coord.second != boardLength - 1 && visited[coord.first][coord.second + 1] == false && board[coord.first][coord.second + 1] == color)
                    {
                        visited[coord.first][coord.second + 1] = true;
                        bfsCoordQueue.emplace(coord.first, coord.second + 1);
                    }

                    bfsCoordQueue.pop();
                }
            }

            
        }
    }
    
    return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    vector<string> board;
    int boardSize;
    cin >> boardSize;

    board.reserve(boardSize);

    while (boardSize--)
    {
        string str;
        cin >> str;
        board.emplace_back(str);
    }

    cout << bfs(board) << ' ';

    for (auto& str : board)
        for (char& ch : str)
            if (ch == 'R') ch = 'G';

    cout << bfs(board);

}