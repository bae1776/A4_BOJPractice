//https://www.acmicpc.net/problem/2469

/* 사다리 타기 (Gold 5)

1행에는, 참가 인원 수(3 ~ 26)가 주어진다.
2행에는, 가로줄의 갯수(3 ~ 1000)가 주어지고
3행에는, ABCD... 순으로 사다리타기를 시작했을 때 나와야 할 사다리 결과가 주어진다.
이후 줄에는, 각 가로줄의 상태가 주어진다.
이때 가로줄을 놓을 수 있는 공간이 하나 비어있는 채로 사다리타기 판이 주어진다.
(그곳에는 같은 높이의 가로선만 추가할 수 있고, 게임 규칙 상 가로선이 만나는 경우는 생각하지 않음)

3행의 결과를 만들 수 있는 비어있는 가로줄의 완성 형태를 출력하시오.
(불가능한 경우 xxxxxxxxx... 출력)

Solution : 구현
*/


#include <iostream>
using namespace std;
char ladderBoard[1000][26];
int players, lineCount;

void joinXLine(char playerState[], char lineState[]);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    //플레이어 수와 줄 수 입력
    cin >> players >> lineCount;

    char start[27] = {'\0'}, result[27];
    for (int i = 0; i < players; i++)
        start[i] = i + 'A';
    
    //사다리 결과 입력
    cin >> result;

    int curiousIndex;
    for (int i = 0; i < lineCount; i++)
    {
        cin >> ladderBoard[i];
        if (ladderBoard[i][0] == '?')
            curiousIndex = i;
    }

    //위에서부터의 결과 가져오기
    for (int i = 0; i < curiousIndex; i++)
        joinXLine(start, ladderBoard[i]);

    //아래에서부터의 결과 가져오기
    for (int i = lineCount - 1; i > curiousIndex; i--)
        joinXLine(result, ladderBoard[i]);


    for (int col = 0; col < players - 1; col++)
    {
        if (start[col] == result[col])
            ladderBoard[curiousIndex][col] = '*';
        else {
            swap(start[col], start[col + 1]);
            if (start[col] == result[col] && start[col + 1] == result[col + 1])
                ladderBoard[curiousIndex][col] = '-';
            else {
                for (int i = 0; i < players - 1; i++)
                    ladderBoard[curiousIndex][i] = 'x';
                break;
            }
        }
    }

    cout << ladderBoard[curiousIndex];

    return 0;
}


void joinXLine(char playerState[], char lineState[])
{
    for (int i = 0; i < players - 1; i++)
    {
        if (lineState[i] == '-')
            swap(playerState[i], playerState[i + 1]);
    }
}