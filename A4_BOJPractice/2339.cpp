//https://www.acmicpc.net/problem/2339

/* 석판 자르기 (Gold 1)
* 하나 이상의 불순물과 보석 결정체로 이루어진 석판을 여러 조각으로 나누어 가공해서, 보다 높은 가치를 얻을 수 있도록 만들어야 한다.
* 이때, 높은 가치의 석판을 만들기 위해서는 석판을 여러 조각으로 나누되 각 조각에는 불순물이 없도록 해야하고, 보석 결정체도 단 하나씩만 포함하게 해야한다.
* 석판을 자를 때 불순물을 없애기 위해서는 불순물을 포함하고 있는 지점을 중심으로 잘라야 한다.
* 그리고 잘린 석판은 이전과 같은 방향으로 자를 수 없다. (처음 자를 때는 가로, 세로 중 아무 방향이나 가능)
* 결정체가 있는 곳은 자를 수 없다.
*
* 다음은 잘 잘린 석판의 예시이다. O는 일반 구역, *은 보석, X는 불순물 구역이다.
*
* OOOOO*OO        OOO|O*OO
* OOOOOOXO        OOO|----
* OO*XOO*O        OO*|OO*O
* OXOOOOOO   -->  --------
* OOOOOOOO        OOOO|OOO
* OOO*XOOO        OOO*|OOO
* OOOOOO*O        OOOO|O*O
* OOOOOOOO        OOOO|OOO
*
* 각각의 석판 안에 불순물이 없으면서 단 하나의 보석 결정체만이 있도록 주어진 석판을 자르는 방법의 수를 구하시오. (없으면 -1 출력)
* 석판의 크기는 최대 20 (정사각), 보석 결정체의 수는 15개 이하이다.
*/


#include <iostream>
#include <vector>
using namespace std;

enum { STONE, TRASH, JEWERLY };
vector<vector<short>> board;

int getSplitCount(const int& startX, const int& endX, const int& startY, const int& endY, bool isXDirection);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int boardSize;
    cin >> boardSize;

    board = vector<vector<short>>(boardSize, vector<short>(boardSize));
    for (auto& boardRow : board)
        for (auto& boardElement : boardRow)
            cin >> boardElement;

    int result = getSplitCount(0, boardSize, 0, boardSize, true) + getSplitCount(0, boardSize, 0, boardSize, false);

    if (result == 0)
        cout << -1;
    else
        cout << result;

    return 0;
}




int getSplitCount(const int& startX, const int& endX, const int& startY, const int& endY, bool isXDirection)
{
    const int boardX = endX - startX;
    const int boardY = endY - startY;

    int boardComponent[3] = { 0, };
    bool xNotCut[20] = { false }, yNotCut[20] = { false };

    for (int y = startY; y < endY; y++)
        for (int x = startX; x < endX; x++)
        {
            if (board[y][x] == JEWERLY)
            {
                xNotCut[y] = true;
                yNotCut[x] = true;
            }
            ++boardComponent[board[y][x]];
        }

    int total = 0;
    if (boardComponent[JEWERLY] == 0)
        return 0;
    else if (boardComponent[JEWERLY] == 1)
    {
        if (boardComponent[TRASH] == 0)
            return 1;
        else
            return 0;
    }
    else {
        if (boardY >= 3 && isXDirection == true)
        {
            for (int xSplitIndex = startY + 1; xSplitIndex < endY - 1; ++xSplitIndex)
            {
                if (xNotCut[xSplitIndex] == false)
                    total += getSplitCount(startX, endX, startY, xSplitIndex, false) *
                    getSplitCount(startX, endX, xSplitIndex + 1, endY, false);
            }
        }

        if (boardX >= 3 && isXDirection == false)
        {
            for (int ySplitIndex = startX + 1; ySplitIndex < endX - 1; ++ySplitIndex)
            {
                if (yNotCut[ySplitIndex] == false)
                    total += getSplitCount(startX, ySplitIndex, startY, endY, true) *
                    getSplitCount(ySplitIndex + 1, endX, startY, endY, true);

            }

        }

    }


    return total;

}
