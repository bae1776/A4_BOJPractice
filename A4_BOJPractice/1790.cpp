//https://www.acmicpc.net/problem/1790

/*수 이어 쓰기 2 (Gold 5)

Solution : 규칙성을 이용해 구현하기
*/

#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    //한자리 숫자는 1에서 시작하고 9개 존재한다는 뜻
    long long digit = 1;
    long long base = 1; 
    long long count = 9;
    
    long long pointingNumber, pointingNumberIndex;
    while (true)
    {
        if (k > digit * count)
        {
            k -= digit * count;
            base *= 10;
            count *= 10;
            digit++;
        } else {
            long long digitIndex = (k - 1) / digit;
            pointingNumber = base + digitIndex;
            pointingNumberIndex = (k - 1) % digit;
            break;
        }
    }

    if (pointingNumber > n)
        cout << -1;
    else {
        for (int i = digit - 1; i >= 0; i--)
        {
            long long val = pointingNumber % 10;
            if (i == pointingNumberIndex)
            {
                cout << val;
                break;
            } else {
                pointingNumber /= 10;
            }
        }
    }


	return 0;
}
