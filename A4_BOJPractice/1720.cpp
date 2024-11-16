//https://www.acmicpc.net/problem/1720

/*타일 코드 (Gold 4)
Solution : 점화식 찾기 (수학)
중복을 생각하지 않는다면, 점화식은
f(n) = 2f(n-2) + f(n-1).
여기서 중복인 경우를 지우는 것으로 생각해야 한다.
답을 g라고 할 때,
어떤 타일 배치가 좌우 대칭이면 중복이 아니다.는 것을 유념한다.
1. n이 홀수 : g(n) = (f(n) - f(n/2)) / 2 + f(n/2)
2. n이 짝수 : g(n) = (f(n) - f(n/2+1)) / 2 + f(n/2+1)
*/

#include <iostream>
using namespace std;

long long f[31] = {1, 1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n; cin >> n;

    for (int i = 2; i <= n; i++)
        f[i] = f[i-2] * 2 + f[i-1];
    
    if (n % 2)
        cout << (f[n] - f[n/2]) / 2 + f[n/2];
    else
        cout << (f[n] - f[n/2+1]) / 2 + f[n/2+1];
        
    return 0;
}
