//https://www.acmicpc.net/problem/14716

/* 현수막 (Silver 1)
현수막에 글자가 쓰여 있을 때, 글자가 몇 개인지 알아보는 프로그램을 만드세요.
현수막에서 글씨인 부분은 1, 글씨가 아닌 부분은 0으로 쓰여 있다.
글자인 부분 1이 상, 하, 좌, 우, 대각선으로 인접하여 서로 연결되어 있다면 한 개의 글자로 간주한다.

Solution : BFS
*/

#include <iostream>
#include <queue>
using namespace std;

int paper[250][250];
int py[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int px[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

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

    int charCount = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (paper[i][j] == 1)
            {
                charCount++;
                queue<pair<int, int>> bfsQueue;
                bfsQueue.emplace(i, j);
                paper[i][j]++;

                while (bfsQueue.empty() == false)
                {
                    auto [y, x] = bfsQueue.front();
                    bfsQueue.pop();

                    for (int move = 0; move < 8; move++)
                        if (0 <= y + py[move] && y + py[move] < row && 
                            0 <= x + px[move] && x + px[move] < col &&
                            paper[y + py[move]][x + px[move]] == 1)
                        {
                            paper[y + py[move]][x + px[move]]++;
                            bfsQueue.emplace(y + py[move], x + px[move]);
                        }

                }

            }
        }
    }

    cout << charCount;
    
	return 0;
}
