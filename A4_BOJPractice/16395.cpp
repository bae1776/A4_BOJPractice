//https://www.acmicpc.net/problem/16395

//파스칼의 삼각형
//주어진 n, k에 대하여 n-1 C k-1 을 구하세요.
//n, k는 30 이하의 자연수.


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    n--; k--;
    if (k > n / 2)
        k = n - k;

    long long result = 1;
    for (int i = 1; i <= k; i++)
    {
        result *= n - i + 1;
        result /= i;
    }

    cout << result;


	return 0;
}
