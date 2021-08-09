//https://www.acmicpc.net/problem/2470

/*두 용액
KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 
각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다.  
산성 용액의 특성값은 양의 정수로 나타내고,
알칼리성 용액의 특성값은 음의 정수로 나타낸다.

이 중 2개의 용액을 혼합하여 가장 0에 가까운 용액을 만들려고 한다.
두 용액을 혼합했을 때 특성값은, 각 용액의 특성값 합이다.

용액의 특성값 리스트가 주어질때, 가장 0에 가까운 혼합 용액을 만드는 용액 2개를 출력하시오.


*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrlen;
    cin >> arrlen;

    vector<int> arr;
    arr.reserve(arrlen);

    int input;
    for (int i = 0; i < arrlen; i++)
    {
        cin >> input;
        arr.emplace_back(input);
    }

    sort(arr.begin(), arr.end());
    
    int leftPtr = 0, rightPtr = arrlen - 1;
    int result1, result2;
    int gap = 0x7FFFFFFF;
    while (leftPtr != rightPtr)
    {
        const int compositeValue = arr[leftPtr] + arr[rightPtr];
        if (abs(compositeValue) < gap)
        {
            result1 = arr[leftPtr];
            result2 = arr[rightPtr];
            gap = abs(compositeValue);
        }

        if (compositeValue <= 0)
            leftPtr++;
        else
            rightPtr--;
    }

    cout << result1 << ' ' << result2;
	return 0;
}
