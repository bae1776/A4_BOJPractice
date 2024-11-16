//https://www.acmicpc.net/problem/1896

/*파급효과 (Gold 4)
Solution : 그래프 탐색

약간 귀찮음이 섞인 그래프 탐색 문제
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Block {
    int val;
    bool up, right, down, left, visited;    
};

int r, c;
Block board[17][17];
int flag = 0;

bool poly(int i, int j)
{
    Block& here = board[i][j];
    if (here.visited)
        return true;
    here.visited = true;
    
    if (flag & (1 << here.val))
        return false; //폴리노미오 내 숫자 중복
    flag += 1 << here.val;

    bool ans = true;
    if (here.up)
        ans &= poly(i - 1, j);
    if (here.right)
        ans &= poly(i, j + 1);
    if (here.down)
        ans &= poly(i + 1, j);
    if (here.left)
        ans &= poly(i, j - 1);

    return ans;
}

bool interval(int i, int j)
{
    Block& here = board[i][j];
    int& val = board[i][j].val;

    for (int d = 1; d <= val; d++)
    {
        if (board[i+d][j].val == val)
            return false;
        if (board[i+d][j].val == 0)
            break;
    }

    for (int d = 1; d <= val; d++)
    {
        if (board[i-d][j].val == val)
            return false;
        if (board[i-d][j].val == 0)
            break;
    }

    for (int d = 1; d <= val; d++)
    {
        if (board[i][j+d].val == val)
            return false;
        if (board[i][j+d].val == 0)
            break;
    }

    for (int d = 1; d <= val; d++)
    {
        if (board[i][j-d].val == val)
            return false;
        if (board[i][j-d].val == 0)
            break;
    }


    return true;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        memset(board, 0, sizeof(board));
        cin >> r >> c;

        char line[20];
        for (int i = 1; i <= r; i++)
        {
            cin >> line;
            for (int j = 1; j <= c; j++)
                board[i][j].val = line[j-1] - '0';
        }

        int link;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cin >> link;
                board[i][j].up = link & 1;
                board[i][j].right = link & 2;
                board[i][j].down = link & 4;
                board[i][j].left = link & 8;
            }
        }

        //1. 폴리노미오 체크
        bool isValid = true;
        for (int i = 1; isValid && i <= r; i++)
            for (int j = 1; isValid && j <= c; j++)
            {
                flag = 0;
                isValid = poly(i, j);
            }

        //2. 숫자 간격 체크
        for (int i = 1; isValid && i <= r; i++)
            for (int j = 1; isValid && j <= c; j++)
            {
                isValid = interval(i, j);
            }

        if (isValid) cout << "valid\n";
        else cout << "invalid\n";

    }
    return 0;
}

