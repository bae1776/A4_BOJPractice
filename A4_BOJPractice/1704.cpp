//https://www.acmicpc.net/problem/1704

/*붕어빵 타이쿤 (Platinum 5)

Solution : 
칸의 개수는 최대 225이고, 모든 칸은 1번 넘게 뒤집을 필요가 없다. (2번 뒤집으면 원래대로 돌아간다.)
그렇다 하더라도 완전 탐색으로는 해결할 수 없다.
그런데 이 문제는,
1행의 뒤집기, 안 뒤집기 선택이 다른 줄의 뒤집기 여부를 결정한다는 것을 알 수 있다. (의존적임)
예를 들어 (1, 1), (1, 2)의 뒤집기 여부를 결정하고 나면 (2, 1)은 (1, 1), (1, 2)에 의존적으로 결정되어 버린다.
그리고 맨 마지막 줄은
(n, k) 뒤집기가 (n, k - 1), (n - 1, k)를 결정해버리는데, 두 결정 결과가 모순이 날 수 있다. 이 경우 IMPOSSIBLE이다.

결국 이 문제는 n * n 보드 (n <= 15)에 대해
O(2^n * n * n)으로 풀 수 있다.
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int VAL = 225;
int row, col, boardMax;
bitset<VAL> board;
bitset<VAL> DP[1024 * 32]; //DP[bitMask] = flipLog
vector<pair<int, int>> ansCandidate; //<count, index>

void breadFlip(bitset<VAL>& board, const int& index);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> row >> col;

    boardMax = row * col;
    bool input;
    for (int i = 0; i < boardMax; i++)
    {
        cin >> input;
        board[i] = input;
    }
	
    int dpMax = (1 << col) - 1;

    for (int bit = 0; bit <= dpMax; bit++)
    {
        int flipCount = 0;
        bool isValid = true;
        bitset<VAL> boardCopy(board);
        for (int shift = 0; shift < col; shift++)
            if (bit & ((dpMax + 1) >> (shift + 1)))
            {
                DP[bit][shift] = true;
                breadFlip(boardCopy, shift);
                flipCount++;
            }

        if (row >= 2)
        {
            for (int sure = col; sure <= boardMax - col; sure++) 
            //2~(마지막 - 1)줄, 그리고 마지막 줄 1열은 아무 제약 없이 그냥 의존적으로 결정됨
            {
                if (boardCopy[sure - col])
                {
                    DP[bit][sure] = true;
                    breadFlip(boardCopy, sure);
                    flipCount++;
                }
            }

            for (int check = boardMax - col + 1; check < boardMax - 1; check++)
            //마지막 줄 2열 ~ 마지막 줄 (마지막-1)열은 모순이 되지 않아야 함
            {
                if (boardCopy[check - col] == boardCopy[check - 1])
                {
                    if (boardCopy[check - col])
                    {
                        DP[bit][check] = true;
                        breadFlip(boardCopy, check);
                        flipCount++;
                    }
                } else {
                    isValid = false;
                    break;
                }
            }

            //마지막 줄 마지막 열은 3가지 모두 모순이 아니여야함
            int last = boardMax - 1;
            if (boardCopy[last] == boardCopy[last - 1] && boardCopy[last] == boardCopy[last - col])
            {
                if (boardCopy[last])
                {
                    DP[bit][last] = true;
                    breadFlip(boardCopy, last);
                    flipCount++;
                }
            } else {
                isValid = false;
            }

        } else {
            const bitset<VAL> zero(0);
            isValid = (zero == boardCopy);
        }

        if (isValid) 
            ansCandidate.emplace_back(flipCount, bit);
    }


    

    if (ansCandidate.empty())
        cout << "IMPOSSIBLE";
    else {
        sort(ansCandidate.begin(), ansCandidate.end());

        const bitset<VAL>& ans = DP[ansCandidate[0].second];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << ans[i * col + j] << ' ';

            cout << '\n';
        }
    }

	return 0;
}


void breadFlip(bitset<VAL>& board, const int& index)
{
    board.flip(index);

    int rest = index % col;
    //left
    if (rest)
        board.flip(index - 1);
    
    //right
    if (rest != col - 1)
        board.flip(index + 1);
    
    //down
    if (index + col < boardMax)
        board.flip(index + col);
    
    //up
    if (index - col >= 0)
        board.flip(index - col);
}