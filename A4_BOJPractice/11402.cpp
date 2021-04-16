//https://www.acmicpc.net/problem/11402

//이항 계수 4 (Platinum 5)
//nCk % M을 구하세요.
//n, k는 최대 10^18 이며, M은 2~2000 사이의 소수이다.
//뤼카의 정리를 이용해야 풀 수 있다. 참고 : https://bowbowbow.tistory.com/2


#include <iostream>
#include <vector>
using namespace std;

vector<int> modSet(long long num, const int& mod);
int combination(int left, int right, const int& mod);
inline int factorialMod(const int& num, const int& mod);
int expMod(int num, int expnum, const int& mod);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    long long left, right;
    int mod;

    cin >> left >> right >> mod;

    vector<int> leftModSet = modSet(left, mod);
    vector<int> rightModSet = modSet(right, mod);

    unsigned calcSize = min(leftModSet.size(), rightModSet.size());
    int result = 1;

    for (int i = 0; i < calcSize; i++)
    {
        int& left = leftModSet[i];
        int& right = rightModSet[i];

        result = (result * combination(left, right, mod)) % mod;
        if (result == 0)
            break;
    }

    cout << result;

	return 0;
}


vector<int> modSet(long long num, const int& mod)
{
    vector<int> result;

    while (num)
    {
        result.push_back(num % mod);
        num /= mod;
    }

    return result;
}

int combination(int left, int right, const int& mod)
{ //Faster Combination
    if (left < right)
        return 0;
    else if (right == 0 || right == left)
        return 1;

    int A = factorialMod(left, mod);
    int B = factorialMod(right, mod) * factorialMod(left - right, mod) % mod;

    return A * expMod(B, mod - 2, mod) % mod;
}



inline int factorialMod(const int& num, const int& mod)
{
    static int factorialDP[2001] = {1, 0};
    static int savedIndex = 1;
    if (factorialDP[num] != 0)
        return factorialDP[num];

    for (int i = savedIndex; i <= num; i++)
        factorialDP[i] = (factorialDP[i - 1] * i) % mod;

    return factorialDP[num];
};

int expMod(int num, int expnum, const int& mod)
{
    switch (expnum)
    {
        case 0:
            return 1;
        case 1:
            return num % mod;
    }

    int half = expMod(num, expnum / 2, mod);
    if (expnum % 2 == 0)
        return (half * half) % mod;
    else   
        return (((half * half) % mod) * num) % mod;

}
