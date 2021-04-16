//https://www.acmicpc.net/problem/13977 

//이항 계수와 쿼리
//nCk % 1000000007 을 구하세요.
//n, k는 최대 4백만이고, 1초 안에 최대 10만개를 구해야하므로
//시간복잡도가 logn 이하여야 합니다.


#include <iostream>
using namespace std;
#define PRIME 1000000007

int combination(const int& n, const int& k);
inline long long factorial(const int& num);
long long expMod(long long num, long long expNum);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int n, k;
        cin >> n >> k;

        cout << combination(n, k) << '\n';
    }

	return 0;
}


int combination(const int& n, const int& k)
{
    if (k == n || k == 0)
        return 1;
    
    long long A = factorial(n);
    long long B = factorial(k) * factorial(n - k) % PRIME;

    return A * expMod(B, PRIME - 2) % PRIME;
}


inline long long factorial(const int& num)
{
    static long long factorialDP[4000001] = {1, 0};
    static long long savedIndex = 1;
    if (factorialDP[num] != 0)
        return factorialDP[num];

    for (long long i = savedIndex; i <= num; i++)
        factorialDP[i] = (factorialDP[i - 1] * i) % PRIME;

    return factorialDP[num];
}


long long expMod(long long num, long long expNum)
{
    switch (expNum)
    {
        case 0:
            return 1;
        case 1:
            return num % PRIME;
    }

    long long half = expMod(num, expNum / 2);
    if (expNum % 2 == 0)
        return (half * half) % PRIME;
    else   
        return (((half * half) % PRIME) * num) % PRIME;
}
