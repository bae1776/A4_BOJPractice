//https://www.acmicpc.net/problem/20122

/*중2병 호반우

중2병에 걸린 호반우들은 인간들을 호반우빔으로 죽이는 망상을 자주 한다.
그들이 하는 망상의 내용은 구체적으로 이러하다.

1. 감옥은 N × M 크기의 격자판으로 이루어져 있고 감옥에는 사람 한 명이 갇혀있다.
2. 사람들은 호반우 도축, 호반우 감금, 호반우 우권 침해 셋 중 하나의 죄명을 가지고 있다.

호반우는 호반우빔을 사용해 이 사람들을 죽일 계획을 가지고 있다..!!

호반우빔은 격자 모양의 감옥 왼쪽 경계 혹은 위쪽 경계에서 격자와 평행한 방향으로만 발사할 수 있다.
발사한 호반우빔은 격자를 순서대로 관통해서 반대쪽 경계까지 도달한다.
호반우는 죽이기만 하면 재미없으니까 죽일 때 마다 점수를 계산하는데 
호반우 도축자를 죽이면 1명당 a점, 호반우 감금자를 죽이면 1명당 b점을 얻게 되고 호반우 우권 침해자를 죽이면 앞으로 얻을 점수가 c배가 된다.
호반우를 위해 호반우가 얻을 수 있는 최소 점수와 최대 점수를 알려주자!

(격자판의 크기는 최대 10 * 10 이며, -100 <= a, b <= 100, -2 <= c <= 2, 호반우 우권 침해자는 20명 이하이다.)
*/

#include <iostream>
#include <vector>
using namespace std;
#define MAXINT 0x3FFFFFFFFFFFFFFF
#define MININT 0xBFFFFFFFFFFFFFFF

pair<long long, int> DP[1024][1024]; //score, times
int board[10][10];
const int bitMask[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    
    int row, col, score1, score2, times;
    cin >> row >> col >> score1 >> score2 >> times;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> board[i][j];
    
    const int rowBitMax = bitMask[row];
    const int colBitMax = bitMask[col];
    
    for (int i = 0; i < rowBitMax; i++)
        for (int j = 0; j < colBitMax; j++)
            DP[i][j] = {MAXINT, 0};
    DP[0][0] = {0, 1};

    int xRazerBit, yRazerBit, nowXRazerNum, nowYRazerNum, i;

    for (xRazerBit = 0; xRazerBit < rowBitMax; xRazerBit++)
        for (yRazerBit = 0; yRazerBit < colBitMax; yRazerBit++)
        {   
            pair<long long, int> state = {0, 1};
            //xRazer Case
            for (nowXRazerNum = 0; nowXRazerNum < row; nowXRazerNum++)
            {
                if (xRazerBit & bitMask[nowXRazerNum])
                {
                    state = DP[xRazerBit & (~bitMask[nowXRazerNum])][yRazerBit];

                    for (i = 0; i < col; i++)
                    {
                        if (!(bitMask[i] & yRazerBit))
                            switch (board[nowXRazerNum][i])
                            {
                                case 1:
                                    state.first += score1 * state.second;
                                    break;
                                case 2:
                                    state.first += score2 * state.second;
                                    break;
                                case 3:
                                    state.second *= times;
                            }
                    }

                    DP[xRazerBit][yRazerBit].first = min(DP[xRazerBit][yRazerBit].first, state.first);
                }
                
            }

            //yRazer Case
            for (nowYRazerNum = 0; nowYRazerNum < col; nowYRazerNum++)
            {
                if (yRazerBit & bitMask[nowYRazerNum])
                {
                    state = DP[xRazerBit][yRazerBit & (~bitMask[nowYRazerNum])];

                    for (i = 0; i < row; i++)
                    {
                        if (!(bitMask[i] & xRazerBit))
                            switch (board[i][nowYRazerNum])
                            {
                                case 1:
                                    state.first += score1 * state.second;
                                    break;
                                case 2:
                                    state.first += score2 * state.second;
                                    break;
                                case 3:
                                    state.second *= times;
                            }
                    }
                    DP[xRazerBit][yRazerBit].first = min(DP[xRazerBit][yRazerBit].first, state.first);
                    
                }
            }

            DP[xRazerBit][yRazerBit].second = state.second;
        }  
    
    long long minScore = 0;
    for (int a = 0; a < rowBitMax; a++)
        for (int b = 0; b < colBitMax; b++)
        {
            minScore = min(DP[a][b].first, minScore);
        }
    
    cout << minScore << ' ';


    for (int a = 0; a < rowBitMax; a++)
        for (int b = 0; b < colBitMax; b++)
            DP[a][b] = {MININT, 0};
    DP[0][0] = {0, 1};



    for (xRazerBit = 0; xRazerBit < rowBitMax; xRazerBit++)
        for (yRazerBit = 0; yRazerBit < colBitMax; yRazerBit++)
        {   
            pair<long long, int> state = {0, 1};
            //xRazer Case
            for (nowXRazerNum = 0; nowXRazerNum < row; nowXRazerNum++)
            {
            
                if (xRazerBit & bitMask[nowXRazerNum])
                {
                    state = DP[xRazerBit & (~bitMask[nowXRazerNum])][yRazerBit];

                    for (i = 0; i < col; i++)
                    {
                        if (!(bitMask[i] & yRazerBit))
                            switch (board[nowXRazerNum][i])
                            {
                                case 1:
                                    state.first += score1 * state.second;
                                    break;
                                case 2:
                                    state.first += score2 * state.second;
                                    break;
                                case 3:
                                    state.second *= times;
                            }
                    }

                    DP[xRazerBit][yRazerBit].first = max(DP[xRazerBit][yRazerBit].first, state.first);
                    DP[xRazerBit][yRazerBit].second = state.second;
                }
                
            }

            //yRazer Case
            for (nowYRazerNum = 0; nowYRazerNum < col; nowYRazerNum++)
            {
                if (yRazerBit & bitMask[nowYRazerNum])
                {
                    state = DP[xRazerBit][yRazerBit & (~bitMask[nowYRazerNum])];

                    for (i = 0; i < row; i++)
                    {
                        if (!(bitMask[i] & xRazerBit))
                            switch (board[i][nowYRazerNum])
                            {
                                case 1:
                                    state.first += score1 * state.second;
                                    break;
                                case 2:
                                    state.first += score2 * state.second;
                                    break;
                                case 3:
                                    state.second *= times;        
                            }
                    }

                    DP[xRazerBit][yRazerBit].first = max(DP[xRazerBit][yRazerBit].first, state.first);
                    DP[xRazerBit][yRazerBit].second = state.second;
                         
                }
                
            }
            DP[xRazerBit][yRazerBit].second = state.second;
        }  
    
    long long maxScore = 0;
    for (int a = 0; a < rowBitMax; a++)
        for (int b = 0; b < colBitMax; b++)
            maxScore = max(DP[a][b].first, maxScore);
    
    cout << maxScore;

    return 0;
}