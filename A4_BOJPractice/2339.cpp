//https://www.acmicpc.net/problem/2339

/* ���� �ڸ��� (Gold 1)
* �ϳ� �̻��� �Ҽ����� ���� ����ü�� �̷���� ������ ���� �������� ������ �����ؼ�, ���� ���� ��ġ�� ���� �� �ֵ��� ������ �Ѵ�.
* �̶�, ���� ��ġ�� ������ ����� ���ؼ��� ������ ���� �������� ������ �� �������� �Ҽ����� ������ �ؾ��ϰ�, ���� ����ü�� �� �ϳ����� �����ϰ� �ؾ��Ѵ�.
* ������ �ڸ� �� �Ҽ����� ���ֱ� ���ؼ��� �Ҽ����� �����ϰ� �ִ� ������ �߽����� �߶�� �Ѵ�.
* �׸��� �߸� ������ ������ ���� �������� �ڸ� �� ����. (ó�� �ڸ� ���� ����, ���� �� �ƹ� �����̳� ����)
* ����ü�� �ִ� ���� �ڸ� �� ����.
*
* ������ �� �߸� ������ �����̴�. O�� �Ϲ� ����, *�� ����, X�� �Ҽ��� �����̴�.
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
* ������ ���� �ȿ� �Ҽ����� �����鼭 �� �ϳ��� ���� ����ü���� �ֵ��� �־��� ������ �ڸ��� ����� ���� ���Ͻÿ�. (������ -1 ���)
* ������ ũ��� �ִ� 20 (���簢), ���� ����ü�� ���� 15�� �����̴�.
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
