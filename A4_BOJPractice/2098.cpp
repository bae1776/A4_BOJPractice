//https://www.acmicpc.net/problem/2098

/*외판원 순회 (Gold 1)

1~N(최대 16개)까지 번호가 매겨져 있는 도시들이 있고, 
도시들 사이에 비용이 드는 길이 있다. 이 길은 없을 수도 있으며 비용이 대칭적이지 않다.

외판원은 모든 도시를 정확히 한 번씩만 거친 뒤에 다시 처음 도시로 돌아간다.
이 때, 가장 적은 비용을 들이는 외판원의 순회 시 드는 비용을 구하시오.
(순회할 수 없는 경우는 주어지지 않음)
*/

#include <iostream>
using namespace std;
#define INF 0x2FFFFFFF

int DP[0xFFFF + 1][16]; //visitBit, lastVisit
int matrix[16][16];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cities;
    cin >> cities;

    for (int i = 0; i < cities; i++)
        for (int j = 0; j < cities; j++)
            cin >> matrix[i][j];
    
    int tip = (0xFFFF + 1) * 16;
    for (int i = 0; i < tip; i++)
        *(*DP + i) = INF;

    DP[1][0] = 0;

    int endBit = (1 << cities) - 1;
    for (int mask = 3; mask <= endBit; mask += 2)
    {
        for (int lastCity = 1; lastCity < cities; lastCity++)
        {
            int cityMask = 1 << lastCity;
            if ((mask & cityMask) == 0)
                continue;
            else if (cityMask > mask)
                break;
            
            for (int last = 0; last < cities; last++)
            {
                if (matrix[last][lastCity] != 0)
                    DP[mask][lastCity] 
                        = min(DP[mask][lastCity], DP[mask - cityMask][last] + matrix[last][lastCity]);
            }
                
        }
    }

    int result = INF;
    for (int i = 1; i < cities; i++)
        if (matrix[i][0] != 0)
            result = min(result, DP[endBit][i] + matrix[i][0]);

    cout << result;
	
	return 0;
}