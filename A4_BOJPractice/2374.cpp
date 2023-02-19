//https://www.acmicpc.net/problem/2374

/*같은 수로 만들기 (Gold 4)

Solution : 그리디 알고리즘 O(N)

배열을 높이가 변하는 그릇이라 생각해보자.
먼저, 배열에서 제일 큰 값을 K라 하자. (그릇의 양끝을 최대한 높힌다)
배열을 순서대로 탐색하는 데,
다음 값이 K보다 낮으면, 그 차만큼 결과 값에 더한다. 그리고 K값을 다음값으로 바꾼다.
다음 값이 K보다 높으면, K값을 다음 값으로 바꾼다.

위가 정해지만, (야매해) 나는 구간합과 분할 정복을 이용해 풀었다. (더 느림) O(NlogN)
*/


#include <iostream>
using namespace std;

int arr[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int count;
    cin >> count;

    int start = 0;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
        start = max(start, arr[i]);
    }

    long long result = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < start)
            result += start - arr[i];
        start = arr[i];
    }

    cout << result;

	return 0;
}



//야매해
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int rangeMax[1000][1000];
// long long func(int left, int right);


// int main(void)
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	cout.tie(nullptr);

//     int count;
//     cin >> count;

//     for (int i = 0; i < count; i++)
//     {
//         cin >> rangeMax[i][i];
//         for (int j = 0; j < i; j++)
//             rangeMax[j][i] = max(rangeMax[j][i - 1], rangeMax[i][i]);
//     }
//     cout << func(0, count - 1);

// 	return 0;
// }


// long long func(int left, int right)
// {
//     int& funcMax = rangeMax[left][right];
//     int peakIndex = lower_bound(rangeMax[left] + left, rangeMax[left] + right, rangeMax[left][right]) - (rangeMax[left] + left);

//     long long result = 0;
//     if (peakIndex != 0)
//         result += func(left, left + peakIndex - 1) + (funcMax - rangeMax[left][left + peakIndex - 1]);
    
//     if (peakIndex != right - left)
//         result += func(left + peakIndex + 1, right) + (funcMax - rangeMax[left + peakIndex + 1][right]);

//     return result;
// }