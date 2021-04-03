//https://www.acmicpc.net/problem/16920

//확장 게임
//벽이 있을 수 있는 격자판에서 정해진 규칙에 따라 자신의 영역을 확장했을 때,
//최종 결과를 출력하시오. (자세한 규칙은 사이트 참고)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//using DIRECTION = enum { UP, DOWN, LEFT, RIGHT };

vector<int> spreadList;
vector<vector<char>> board;
vector<queue<pair<int, int>>> spreadQueue;

void spread_all_players();
void do_spreading_once(const pair<int, int>& coord, const int player);
bool all_blocked();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int depth, width, player;
    cin >> depth >> width >> player;

    spreadList = vector<int>(player);
    for (int& spread : spreadList)
        cin >> spread;

    //보드
    board = vector<vector<char>>(depth, vector<char>(width));
    //확장될수 있는 말의 좌표를 각 플레이어마다 담는 큐
    spreadQueue = vector<queue<pair<int, int>>>(player, queue<pair<int, int>>());

    for (unsigned int y = 0; y < depth; ++y)
        for (unsigned int x = 0; x < width; ++x)
        {
            cin >> board[y][x];

            if (board[y][x] >= '1' && board[y][x] <= '9')
                spreadQueue[board[y][x] - '1'].emplace(y, x);
        }

    do
    {
        spread_all_players();

    } while (!all_blocked());


    //Test : 보드 출력
    // for (unsigned int y = 0; y < depth; ++y)
    // {
    //     for (unsigned int x = 0; x < width; ++x)
    //         cout << board[y][x];
    //     cout << endl;
    // }

    vector<int> playerBlockList(player, 0);

    for (unsigned int y = 0; y < depth; ++y)
        for (unsigned int x = 0; x < width; ++x)
            if (board[y][x] >= '1' && board[y][x] <= '9')
                playerBlockList[board[y][x] - '1']++;

    for (int& stat : playerBlockList)
        cout << stat << ' ';

    return 0;

}


void spread_all_players()
{
    for (unsigned int player = 0; player < spreadList.size(); player++)
    {
        int spreadCount = spreadList[player];
        int nowTotalSpreadBlocks = (int)spreadQueue[player].size();

        while (nowTotalSpreadBlocks && spreadCount)
        {
            pair<int, int> spreadCoord = spreadQueue[player].front();
            spreadQueue[player].pop();

            do_spreading_once(spreadCoord, player);
            nowTotalSpreadBlocks--;

            if (nowTotalSpreadBlocks == 0)
            {
                spreadCount--;
                nowTotalSpreadBlocks = (int)spreadQueue[player].size();
            }
        }
    }
}


void do_spreading_once(const pair<int, int>& coord, const int player)
{
    //UP spreading
    if (coord.first != 0 && board[coord.first - 1][coord.second] == '.')
    {
        board[coord.first - 1][coord.second] = player + '1';
        spreadQueue[player].emplace(coord.first - 1, coord.second);
    }

    //LEFT spreading
    if (coord.second != 0 && board[coord.first][coord.second - 1] == '.')
    {
        board[coord.first][coord.second - 1] = player + '1';
        spreadQueue[player].emplace(coord.first, coord.second - 1);
    }

    //DOWN spreading
    if (coord.first + 1 < (int)board.size() && board[coord.first + 1][coord.second] == '.')
    {
        board[coord.first + 1][coord.second] = player + '1';
        spreadQueue[player].emplace(coord.first + 1, coord.second);
    }

    //RIGHT spreading
    if (coord.second + 1 < (int)board[0].size() && board[coord.first][coord.second + 1] == '.')
    {
        board[coord.first][coord.second + 1] = player + '1';
        spreadQueue[player].emplace(coord.first, coord.second + 1);
    }
}


bool all_blocked()
{
    unsigned int mask = 0;
    for (auto& queueElement : spreadQueue)
        mask = mask | queueElement.size();

    return mask == 0;
}