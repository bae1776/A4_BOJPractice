//https://www.acmicpc.net/problem/1377

/*버블 소트
버블 소트 시 움직여야할 최소 횟수를 구하시오.
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

    int arrLength;
    cin >> arrLength;

    vector<pair<int, int>> arr(arrLength);

    for (int i = 0; i < arrLength; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int result = 0;
    for (int i = 0; i < arrLength; i++)
    {
        result = max(result, arr[i].second - i);
    }

    cout << result + 1;

    
	return 0;
}