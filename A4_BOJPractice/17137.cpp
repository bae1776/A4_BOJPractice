//https://www.acmicpc.net/problem/17137

/*사탕 놀이 (Gold 1)

Solution : 다이나믹 프로그래밍

먼저 아이들을 아는 숫자 갯수의 오름차순으로 정렬한다.
그 다음, DP[n][k] = 1~n-1번째가 비내림차순으로 정렬되면서, n번째 아이가 k를 말하는 경우의 수
참고로 아이 A는 5, 아이 B는 3을 부른 것과 A가 3, B가 5를 부른 것은 같은 경우({3, 5})이므로, 
결국 아이들의 숫자 부름 순서는 아무런 상관이 없다.
DP[n][k] = DP[n-1][1] + DP[n-1][2] ... + DP[n-1][k]
기저인 DP[1][k]는 k가 1번 아이가 말할 수 있는 숫자면 1, 아니면 0 값을 부여한다.
시간복잡도는 O(n*k^2).

*/

#include <iostream>
#include <algorithm>
using namespace std;
#define DIV 1000000007

int DP[201][201];
int childNumber[201];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        fill(*DP, *DP + 201 * 201, 0);
        
        int childCount;
        cin >> childCount;

        for (int i = 1; i <= childCount; i++)
            cin >> childNumber[i];

        sort(childNumber + 1, childNumber + childCount + 1);

        //기저
        for (int i = 1; i <= childNumber[1]; i++)
            DP[1][i] = 1;
        
        for (int idx = 2; idx <= childCount; idx++)
        {
            for (int k = 1; k <= childNumber[idx]; k++)
            {
                for (int i = 1; i <= k; i++)
                    DP[idx][k] = (DP[idx][k] + DP[idx - 1][i]) % DIV;
            }
        }

        long long answer = 0;
        for (int i = 1; i <= childNumber[childCount]; i++)
            answer = (answer + DP[childCount][i]) % DIV;

        answer = (answer * childCount) % DIV;

        cout << answer << '\n';
    }
    

	return 0;
}


