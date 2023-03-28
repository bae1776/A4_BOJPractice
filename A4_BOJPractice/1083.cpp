//https://www.acmicpc.net/problem/1083

/*소트 (Gold 5)

Solution : 그리디 알고리즘

남은 소트 횟수에서 가능한 가장 큰 원소를 제일 앞으로 끌어온다.
앞 원소가 이미 가장 큰 원소라면 다음 위치에 대해서 위 작업을 반복한다.
*/

#include <iostream>
using namespace std;

int arr[51];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrLen;
    cin >> arrLen;

    for (int i = 0; i < arrLen; i++)
        cin >> arr[i];

    int swapCount;
    cin >> swapCount;

    for (int cmpStart = 0; swapCount && cmpStart < arrLen - 1; cmpStart++)
    {   
        int maxIndex = cmpStart;
        for (int swapNext = cmpStart + 1; swapNext < min(arrLen, cmpStart + swapCount + 1); swapNext++)
        {
            if (arr[swapNext] > arr[maxIndex])
                maxIndex = swapNext;
        }

        if (maxIndex == cmpStart)
            continue;

        swapCount -= maxIndex - cmpStart;

        for (int i = maxIndex; i > cmpStart; i--)
            swap(arr[i-1], arr[i]);
    }

    for (int i = 0; i < arrLen; i++)
        cout << arr[i] << ' ';

	return 0;
}
