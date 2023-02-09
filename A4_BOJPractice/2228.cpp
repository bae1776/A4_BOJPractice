//https://www.acmicpc.net/problem/2228

/*구간 나누기 (Gold 3)

-> 다이나믹 프로그래밍
내가 푼 방법은,
DP[Left][Right][Section] = 
배열 left~Right를 Section개의 구간으로 나눴을 때 최댓값으로 정의한다.
점화식은
Section = 0이면 0
Section = 1인 경우 전처리해서 구할 수 있고
Section >= 2인 경우,
for (i = Left + (Section - 1) * 2; i <= Right; i++)
    max_element(DP[Left][i-2][Section - 1] + DP[i][Right][1])
O(n^4)

이 문제의 정해는 다음과 같이 DP를 정의한다. (더 빠름, O(n^3))

DP[n][m]은 arr[1, n]까지 m개 구간으로 나눴을 때 최댓값으로 정의한다.
그러면 점화식은
max(DP[n-1][m], for k in [2, n]: DP[k-2][m-1], sum(k, n));
여기서 왼쪽 식은 arr[n]을 포함시키지 경우이고,
오른쪽 식은 m번째 구간에 arr[n]이 포함된 경우이다.
이때 m번째 구간은 어디서 시작해야 최적인지 알 수 없으므로 구간 시작 인덱스 k에 대한 반복문을 돌린다.
*/

#include <iostream>
#include <algorithm>
using namespace std;
int DP[100][100][51];
int sum[100][100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    fill(**DP, **DP + 100 * 100 * 51, -0x3FFFFFFF);
    int arrlen, section;
    cin >> arrlen >> section;

    for (int end = 0; end < arrlen; end++)
    {
        cin >> DP[end][end][1];
        sum[end][end] = DP[end][end][1];
        for (int start = 0; start < end; start++)
        {
            DP[start][end][1] = max(DP[start][end - 1][1], sum[end][end]);
            for (int idx = end - 1; idx >= start; idx--)
                DP[start][end][1] = max(DP[start][end][1],
                    sum[idx][end] = sum[idx][end - 1] + sum[end][end]);
        }
    }

    for (int s = 2; s <= section; s++)
    {
        for (int start = 0; start < arrlen; start++)
        {
            for (int end = start + s * 2 - 2; end < arrlen; end++)
            {
                for (int emptyPos = start + s * 2 - 3; emptyPos < arrlen - 1; emptyPos++)
                    DP[start][end][s] = max(DP[start][end][s], 
                        DP[start][emptyPos - 1][s - 1] + DP[emptyPos + 1][end][1]);
            }
        }
    }

    cout << DP[0][arrlen - 1][section];

	return 0;
}
