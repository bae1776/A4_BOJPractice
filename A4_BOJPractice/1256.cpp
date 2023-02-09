//https://www.acmicpc.net/problem/1256

/*사전 (Gold 2)

Solution : 경우의 수 - 조합을 이용한 문제이다.
조합 결과를 메모이제이션(DP)한 뒤 쉽게 풀 수 있다.
*/

#include <iostream>
using namespace std;
#define INF 2222222222ll

long long combinationDP[201][201];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int cLeft = 1; cLeft <= 200; cLeft++)
        for (int cRight = 0; cRight <= cLeft; cRight++)
        {
            if (cRight == 0 || cRight == cLeft)
                combinationDP[cLeft][cRight] = 1;
            else {
                combinationDP[cLeft][cRight] = min(INF, 
                    combinationDP[cLeft - 1][cRight - 1] + combinationDP[cLeft - 1][cRight]);
            }
        }

    long long aCount, zCount, K;
    cin >> aCount >> zCount >> K;

    if (K > combinationDP[aCount + zCount][aCount])
    {
        cout << -1;
        return 0;
    }

    while (aCount && zCount)
    {
        if (K > combinationDP[aCount + zCount - 1][aCount - 1])
        {
            K -= combinationDP[aCount + zCount - 1][aCount - 1];
            cout << 'z';
            zCount--;
        } else {
            cout << 'a';
            aCount--;
        }
    }

    while (aCount--)
        cout << 'a';
    while (zCount--)
        cout << 'z';

	return 0;
}

