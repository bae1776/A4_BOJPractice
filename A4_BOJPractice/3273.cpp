//https://www.acmicpc.net/problem/3273

/*두 수의 합

최대 길이 10만의 수열이 있다. 각 원소는 1~1000000 자연수 값을 갖는다.
a(i) + a(j) = x 를 만족하는 i, j 쌍의 수를 구하시오. (i < j)
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arraySize;
    cin >> arraySize;

    vector<int> arr;
    arr.reserve(arraySize);

    int element;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> element;
        arr.emplace_back(element);
    }

    sort(arr.begin(), arr.end());

    int x;
    cin >> x;

    int leftPtr = 0, rightPtr = arraySize - 1;

    int count = 0;
    while (leftPtr != rightPtr)
    {
        if (arr[leftPtr] + arr[rightPtr] == x)
        {
            count++;
            int leftGap = arr[leftPtr + 1] - arr[leftPtr];
            int rightGap = arr[rightPtr] - arr[rightPtr - 1];

            if (leftGap <= rightGap)
                leftPtr++;
            else
                rightPtr--;

        } else if (arr[leftPtr] + arr[rightPtr] < x)
            leftPtr++;
        else
            rightPtr--;
    }

    cout << count;
    
    return 0;

}