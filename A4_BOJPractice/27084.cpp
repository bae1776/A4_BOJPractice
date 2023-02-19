//https://www.acmicpc.net/problem/27084
/*카드 뽑기 (Gold 5)

수학 (정렬 이용)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int numCount;
    cin >> numCount;

    for (int i = 0; i < numCount; i++)
        cin >> arr[i];


    sort(arr, arr + numCount);


    long long answer = 1;
    int dupCount = 1, dupNumber = arr[0];
    for (int i = 1; i < numCount; i++)
    {
        if (arr[i] == dupNumber)
            dupCount++;
        else {
            answer = answer * (dupCount + 1) % 1000000007;
            dupCount = 1;
            dupNumber = arr[i];
        }
    }
    answer = answer * (dupCount + 1) % 1000000007;

    cout << answer - 1;

    
	return 0;
}

