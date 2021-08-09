//https://www.acmicpc.net/problem/1806

/*부분합
10000 이하의 자연수로 이루어진 배열이 주어진다. (최대 길이 10만)
이 수열에서 연속된 수들의 부분합 중에 
그 합이 K(~1억) 이상이 되는 것 중, 가장 짧은 것의 길이를 구하시오.

*/

#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrlen, sum;
    cin >> arrlen >> sum;

    vector<int> arr;
    arr.reserve(arrlen);
    
    int element;
    for (int i = 0; i < arrlen; i++)
    {
        cin >> element;
        arr.emplace_back(element);
    }

    int leftPtr = 0, rightPtr = 0;
    int rangeSum = arr[0];
    int minlen = 999999;

    while (true)
    {
        if (rangeSum >= sum)
        {
            if (rightPtr - leftPtr + 1 < minlen)
                minlen = rightPtr - leftPtr + 1;
            
            rangeSum -= arr[leftPtr++];
        } else {
            if (rightPtr == arrlen - 1)
                break;
            rangeSum += arr[++rightPtr];
        }
    }

    if (minlen == 999999)
        cout << 0;
    else
        cout << minlen;

    return 0;
}
