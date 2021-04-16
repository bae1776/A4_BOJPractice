//https://www.acmicpc.net/problem/999 (문제 번호)

//내려가기.
//(모든 경우에 대한 DP 테이블을 메모리 초과가 일어난다.)


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int temp[3] = { 0 }, minDP[3] = { 0 }, maxDP[3] = { 0 };
    int line;
    cin >> line;

    for (int i = 0; i < line; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        temp[0] = minDP[0]; temp[1] = minDP[1]; temp[2] = minDP[2];
        minDP[0] = a + min(temp[0], temp[1]);
        minDP[1] = b + min(min(temp[0], temp[1]), temp[2]);
        minDP[2] = c + min(temp[1], temp[2]);

        temp[0] = maxDP[0]; temp[1] = maxDP[1]; temp[2] = maxDP[2];
        maxDP[0] = a + max(temp[0], temp[1]);
        maxDP[1] = b + max(max(temp[0], temp[1]), temp[2]);
        maxDP[2] = c + max(temp[1], temp[2]);
    }

    int totalMax = max(max(maxDP[0], maxDP[1]), maxDP[2]);
    int totalMin = min(min(minDP[0], minDP[1]), minDP[2]);

    cout << totalMax << ' ' << totalMin;

	return 0;
}