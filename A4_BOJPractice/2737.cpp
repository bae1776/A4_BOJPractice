//https://www.acmicpc.net/problem/2737

/*연속 합 (Gold 3)

Solution :

주어진 정수 P에 대하여
예를 들어,
2개의 연속된 자연수 합의 종류는 1+2 = 3, 2+3 = 5, 3+4 = 7... 이다.
n개의 연속된 자연수 합의 종류는 n(n+1) / 2 + kn이다. (n은 2 이상, k는 0 이상)
즉 P = n(n+1)/2 + kn을 만족하는 n, k 쌍의 개수가 이 문제의 정답이고,
n이 제곱으로 늘어나므로 P(2^31)에 대해 n은 2^16 까지 정도 계산하면 되며, 
이는 60000 정도로 완전 탐색으로 해결 가능하다.
*/

#include <iostream>
using namespace std;

int accSum[70000] = {0, 1, 3, };
int accSumSize = 2;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (true)
    {
        accSum[accSumSize + 1] = accSum[accSumSize] + accSumSize + 1;
        if (accSum[accSumSize + 1] < accSum[accSumSize])
            break;
        accSumSize++;
    }
    
    int input;
    while (testcase--)
    {
        cin >> input;
        int answer = 0;
        for (int i = 2; i <= accSumSize; i++)
        {
            if (input < accSum[i])
                break;
            if ((input - accSum[i]) % i == 0)
                answer++;
        }

        cout << answer << '\n';
    }

	return 0;
}
