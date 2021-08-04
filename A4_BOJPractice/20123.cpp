//https://www.acmicpc.net/problem/20123

/*L-트로미노 계단

■       모양의 계단을
■■      ■ 
■■■     ■■ (L자의 블럭) 만으로 만드려고 한다.
■■■■    이 L 블럭은 회전할 수 있으나, 계단에 겹쳐 붙이는 것은 허용되지 않는다.

층 수가 주어질 때(최대 1000층)
붙이는 방법을 구하시오. 불가능하다면 불가능하다고 출력하시오.

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> blockBoard;

void draw_top6(const int& startRow);
void draw_top9();
void draw_middle6(const int& startRow, const int& bottomLength);
void draw_bottom2(const int& startRow);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int level;
    cin >> level;

    blockBoard = vector<vector<char>>(level);
    for (int i = 0; i < level; i++)
        blockBoard[i] = vector<char>(i + 1);

    bool isValid = true;

    if (level < 6)
    {
        if (level == 2)
        {
            blockBoard[0][0] = '|';
            blockBoard[1][0] = 'b';
            blockBoard[1][1] = '-';
        } else {
            isValid = false;
        }
    } else {
        switch (level % 6)
        {
            case 0:
                draw_top6(0);
                draw_middle6(6, level);
                break;
            case 2:
                draw_top6(0);
                draw_middle6(6, level - 2);
                draw_bottom2(level - 2);
                break;
            case 3:
                draw_top9();
                draw_middle6(9, level);
                break;
            case 5:
                draw_top9();
                draw_middle6(9, level - 2);
                draw_bottom2(level - 2);
                break;
            default:
                isValid = false;
        }
    }

    if (isValid == true)
    {
        for (const auto& rowVec : blockBoard)
        {
            for (const auto& ch : rowVec)
                cout << ch;
            cout << '\n';
        }
    } else {
        cout << "impossible";
    }

    return 0;
}


void draw_top6(const int& startRow)
{
    const static char* sixFloors[6] = {
        "|",
        "b-",
        "p-|",
        "||b-",
        "|b-||",
        "b--db-"
    };

    for (int row = 0; row < 6; row++)
        for (int col = 0; col <= row; col++)
            blockBoard[startRow + row][startRow + col] = sixFloors[row][col];

}

void draw_top9()
{
    const static char* nineFloors[9] = {
        "|",
        "b-",
        "p-|",
        "|-d|",
        "p--d|",
        "|-q|b-",
        "p-|b--q",
        "||p-||||",
        "-d|-db-b-"
    };

    for (int row = 0; row < 9; row++)
        for (int col = 0; col <= row; col++)
            blockBoard[row][col] = nineFloors[row][col];

}

void draw_middle6(const int& startRow, const int& bottomLength)
{
    const static char* sixThreeBlock[6] = {
        "|-q",
        "b-|",
        "|-q",
        "b-|",
        "|-q",
        "b-|"
    };

    for (int row = startRow; row < bottomLength; row += 6)
    {
        for (int col = 0; col < row; col += 3)
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 3; j++)
                    blockBoard[row + i][col + j] = sixThreeBlock[i][j];
        
        draw_top6(row);
    }
}


void draw_bottom2(const int& startRow)
{
    const static char* twoThreeBlock[2] = {
        "|-q",
        "b-|"
    };

    for (int col = 0; col < startRow; col += 3)
        for (int j = 0; j < 3; j++)
        {
            blockBoard[startRow][col + j] = twoThreeBlock[0][j];
            blockBoard[startRow+1][col + j] = twoThreeBlock[1][j];
        }
    
    blockBoard[startRow][startRow] = '|';
    blockBoard[startRow+1][startRow] = 'b';
    blockBoard[startRow+1][startRow+1] = '-';
    
}