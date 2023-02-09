//https://www.acmicpc.net/problem/24392

/* 영재의 징검다리 (Silver 1)
영재는 마지막 행부터 첫 행까지 한 행씩 점프하여 유리 징검다리를 건너는데,
자신의 바로 앞, 좌우 대각선 방향으로만 진행할 수 있고, 강화유리만을 밟을 수 있다.
징검다리를 안전하게 건너는 경우의 수는? (너무 커질 수 있으므로 모듈러 연산한다)

Solution : DP
*/


#include <iostream>
using namespace std;
unsigned int DP[1001][1a001];
bool isTempered[1001][1001];

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int row, col;
    cin >> row >> col;

    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> isTempered[i][j];

    for (int j = 1; j <= col; j++)
        if (isTempered[1][j])
            DP[1][j] = 1;

    for (int i = 1; i <= row - 1; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (!isTempered[i][j]) continue;

            for (int nextJ = j - 1; nextJ <= j + 1; nextJ++)
                if (isTempered[i + 1][nextJ])
                    DP[i + 1][nextJ] = (DP[i + 1][nextJ] + DP[i][j]) % 1000000007;
        }
    }

    unsigned int result = 0;
    for (int j = 1; j <= col; j++)
        result = (result + DP[row][j]) % 1000000007;

    cout << result;

    return 0;
}
