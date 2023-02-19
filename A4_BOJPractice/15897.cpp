//https://www.acmicpc.net/problem/15897

/* 잘못 구현한 에라토스테네스의 체 (Gold 2)

Solution : 정수론
조화수열의 성질을 이용하면 2sqrt(n)에 풀 수 있다.
예를 들어 n=11인 경우, 문제에서 나온 for문은 다음과 같이 돈다.
i = 1 : j = 1 2 3 4 5 6 7 8 9 10 11
i = 2 : j = 1 3 5 7 9 11
...
i = 10 : j = 1 11
i = 11 : j = 1

조금 단순화 하기 위해 k = n-1이라하면,
i = 1 : j = 1 2 3 ... 10
i = 2 : j = 2 4 6 8 10
...
i = 10 : j = 10

여기서 나오는 j의 개수에 n을 더하면 답이 된다.
단순화된 문제는 다음과 같이 구한다.

end = k, div = 2로 시작한다.
while ()
{
    start = k / div                   -> i = [start, end) 일때 
    ans += (end - start) * (div - 1)  -> j의 개수가 div - 1개이다.
    (start == 0) break
    div = max(div + 1, k / start + 1) -> max의 오른쪽 식은, start != end가 되도록 한다.
    end = start
}

*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long input;
    cin >> input;

    long long ans, k, start, end, div;
    ans = input;
    k = end = input - 1;
    div = 2;
    
    while (true)
    {
        start = k / div;
        ans += (end - start) * (div - 1);
        if (start == 0) break;
        div = max(div + 1, k / start + 1);
        end = start;
    }

    cout << ans;

	return 0;
}


