//https://www.acmicpc.net/problem/2618

/*DSLR
네 개의 명령어 D, S, L, R를 이용하는 간단한 계산기가 있다.
이 계산기는 네 자리 자연수를 저장한다.
각 명령어는 저장된 자연수 n을 다음과 같이 변환한다.

D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다.
S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다.
R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 

[주의] 1000 에 
L 을 적용하면 결과는 0001 = 1 이 된다. 
R 을 적용하면 결과는 0100 = 100 이 된다.

A, B가 주어질 때
A->B로 바꾸는데 필요한 최소한의 명령어 나열을 출력하세요.
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        queue<pair<short, string>> BFSQueue;
        vector<bool> visited(10000, false);

        int A, B;
        cin >> A >> B;

        BFSQueue.emplace(A, string());
        visited[A] = true;
        
        while (true)
        {
            auto& nowElement = BFSQueue.front();
            if (nowElement.first == B)
                break;

            int calValue[4] = { 
                (nowElement.first >= 5000) ? (nowElement.first * 2 - 10000) : nowElement.first * 2,
                (nowElement.first == 0) ? 9999 : (nowElement.first - 1),
                nowElement.first % 1000 * 10 + nowElement.first / 1000,
                nowElement.first % 10 * 1000 + nowElement.first / 10
            };
            const static char calChar[4] = {'D', 'S', 'L', 'R'};
            
            for (int i = 0; i < 4; i++)
            {
                if (visited[calValue[i]] == false)
                {
                    visited[calValue[i]] = true;
                    BFSQueue.emplace(calValue[i], nowElement.second + calChar[i]);
                }
            }

            BFSQueue.pop();
        }

        cout << BFSQueue.front().second << '\n';

    }
    return 0;
}