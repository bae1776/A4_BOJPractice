//https://www.acmicpc.net/problem/16441

/*아기돼지와 늑대

아기돼지는 N*M 격자형의 고리분지에 독립하여 새 집을 지으려 합니다.
고리분지엔 돼지 뿐만 아니라 늑대들도 살고 있는데, 늑대가 갈 수 있는 곳엔 아기돼지가 살 수 없습니다.

고리분지는 산, 빙판, 초원, 늑대가 살고 있는 곳(초원)으로 이루어져 있습니다.
늑대는 초원 지형에선 산 지형이 아닌 인접 상하좌우 칸으로 자유롭게 움직일 수 있습니다. 
그런데 이동한 칸이 빙판 지형인 경우 빙하가 끝나는 지점 혹은 산에 부딪힐 때까지 미끄러집니다.
산에 부딪힌 경우, 빙판 지형인 경우라도 다시 상하좌우로 움직일 수 있습니다.

늑대가 도달할 수 없고 지형이 초원인 곳을 '안전한 곳'이라고 합니다.
고리분지가 주어졌을 때, '안전한 곳'을 표시해주세요.
(고리분지는 최대 100 * 100이며, 고리분지의 외곽부분은 항상 산입니다.)

*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using DIRECTION = enum {LEFT, RIGHT, UP, DOWN, VISIT};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int row, col;
    cin >> row >> col;

    vector<pair<int, int>> wolfDirList;
    vector<vector<char>> goriBasin(row, vector<char>(col));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> goriBasin[i][j];
            if (goriBasin[i][j] == 'W')
            {
                wolfDirList.emplace_back(i, j);
                goriBasin[i][j] = '.';
            }
        }

    vector<vector<vector<bool>>> wasMovedList(row, vector<vector<bool>>(col, vector<bool>(5, false)));
    vector<vector<char>> goriBasinOrg(goriBasin);

    for (auto& wolfDir : wolfDirList)
    {  
        vector<vector<char>> goriBasinCase(goriBasinOrg);
        deque<pair<int, int>> wolfDirQueue;
        deque<char> lastMoveQueue;

        wolfDirQueue.push_back(wolfDir);
        lastMoveQueue.push_back('N');

        while (!wolfDirQueue.empty())
        {
            pair<int, int> nowWolfDir = wolfDirQueue.front();
            int lastMove = lastMoveQueue.front();
            wolfDirQueue.pop_front();
            lastMoveQueue.pop_front();

            if (wasMovedList[nowWolfDir.first][nowWolfDir.second][VISIT] == true &&
                goriBasinOrg[nowWolfDir.first][nowWolfDir.second] == '.')
                continue;
            wasMovedList[nowWolfDir.first][nowWolfDir.second][VISIT] = true;   
            goriBasinCase[nowWolfDir.first][nowWolfDir.second] = 'W';

            //on Ice land and Sliding Case
            if (goriBasinOrg[nowWolfDir.first][nowWolfDir.second] == '+')
            { 
                if (lastMove == 'L' && (goriBasinOrg[nowWolfDir.first][nowWolfDir.second - 1] == '+' || 
                                        goriBasinOrg[nowWolfDir.first][nowWolfDir.second - 1] == '.'))
                {
                    wolfDirQueue.push_front(make_pair(nowWolfDir.first, nowWolfDir.second - 1));
                    lastMoveQueue.push_front('L');

                    continue;
                }
                if (lastMove == 'R' &&  (goriBasinOrg[nowWolfDir.first][nowWolfDir.second + 1] == '+' ||
                                         goriBasinOrg[nowWolfDir.first][nowWolfDir.second + 1] == '.'))
                {
                    wolfDirQueue.push_front(make_pair(nowWolfDir.first, nowWolfDir.second + 1));
                    lastMoveQueue.push_front('R');

                    continue;
                }
                if (lastMove == 'U' && (goriBasinOrg[nowWolfDir.first - 1][nowWolfDir.second] == '+' || 
                                         goriBasinOrg[nowWolfDir.first - 1][nowWolfDir.second] == '.'))
                {
                    wolfDirQueue.push_front(make_pair(nowWolfDir.first - 1, nowWolfDir.second));
                    lastMoveQueue.push_front('U');

                    continue;
                }
                if (lastMove == 'D' && (goriBasinOrg[nowWolfDir.first + 1][nowWolfDir.second] == '+' || 
                                         goriBasinOrg[nowWolfDir.first + 1][nowWolfDir.second] == '.'))
                {
                    wolfDirQueue.push_front(make_pair(nowWolfDir.first + 1, nowWolfDir.second));
                    lastMoveQueue.push_front('D');

                    continue;
                }
            }

            //Left move case
            if (goriBasinCase[nowWolfDir.first][nowWolfDir.second - 1] != '#' && 
                wasMovedList[nowWolfDir.first][nowWolfDir.second][LEFT] == false && 
                !(goriBasinCase[nowWolfDir.first][nowWolfDir.second - 1] == 'W' &&
                    goriBasinOrg[nowWolfDir.first][nowWolfDir.second - 1] == '.'))
            {
                wasMovedList[nowWolfDir.first][nowWolfDir.second][LEFT] = true;
                wolfDirQueue.push_back(make_pair(nowWolfDir.first, nowWolfDir.second - 1));
                lastMoveQueue.push_back('L');
            }

            //Right
            if (goriBasinCase[nowWolfDir.first][nowWolfDir.second + 1] != '#' && 
                wasMovedList[nowWolfDir.first][nowWolfDir.second][RIGHT] == false && 
                !(goriBasinCase[nowWolfDir.first][nowWolfDir.second + 1] == 'W' &&
                    goriBasinOrg[nowWolfDir.first][nowWolfDir.second + 1] == '.'))
            {
                wasMovedList[nowWolfDir.first][nowWolfDir.second][RIGHT] = true;
                wolfDirQueue.push_back(make_pair(nowWolfDir.first, nowWolfDir.second + 1));
                lastMoveQueue.push_back('R');
            }

            //Up
            if (goriBasinCase[nowWolfDir.first - 1][nowWolfDir.second] != '#' && 
                wasMovedList[nowWolfDir.first][nowWolfDir.second][UP] == false && 
                !(goriBasinCase[nowWolfDir.first - 1][nowWolfDir.second] == 'W' &&
                    goriBasinOrg[nowWolfDir.first - 1][nowWolfDir.second] == '.'))
            {
                wasMovedList[nowWolfDir.first][nowWolfDir.second][UP] = true;
                wolfDirQueue.push_back(make_pair(nowWolfDir.first - 1, nowWolfDir.second));
                lastMoveQueue.push_back('U');
            }

            if (goriBasinCase[nowWolfDir.first + 1][nowWolfDir.second] != '#' && 
                wasMovedList[nowWolfDir.first][nowWolfDir.second][DOWN] == false && 
                !(goriBasinCase[nowWolfDir.first + 1][nowWolfDir.second] == 'W' &&
                    goriBasinOrg[nowWolfDir.first + 1][nowWolfDir.second] == '.'))
            {
                wasMovedList[nowWolfDir.first][nowWolfDir.second][DOWN] = true;
                wolfDirQueue.push_back(make_pair(nowWolfDir.first + 1, nowWolfDir.second));
                lastMoveQueue.push_back('D');
            }
            

        }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (goriBasinCase[i][j] == 'W')
                    goriBasin[i][j] = 'W';
            }

    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (goriBasin[i][j] == '.' && goriBasinOrg[i][j] == '.')
                goriBasinOrg[i][j] = 'P';

        
    for (auto& wolfDir : wolfDirList)
        goriBasinOrg[wolfDir.first][wolfDir.second] = 'W';
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << goriBasinOrg[i][j];
        cout << '\n';
    }

    return 0;
}