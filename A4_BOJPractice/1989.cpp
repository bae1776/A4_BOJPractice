//https://www.acmicpc.net/problem/1989

/*부분배열 고르기 2 (Platinum 5)

Solution : 누적합과 분할 정복

수가 10만개이고 부분배열에 대한 계산이 필요하기 때문에
완전 탐색은 10만^2 연산이 필요하므로 불가능하다.

일단 부분배열 상에서, 부분 합 파트는 누적합을 이용해서 구하고, 
(배열값이 변하지 않으므로 세그먼트 트리를 쓰면 오히려 느려진다.)
총 문제는 분할 정복을 이용한다.
1. 왼쪽 파트의 최댓값
2. 오른쪽 파트의 최댓값
3. 왼쪽 오른쪽 겹쳐지는 부분의 최댓값

3. 부분이 중요한데, 그냥 Greedy하게 왼쪽, 오른쪽 방향 중 더 큰 값을 골라
갱신해주는 것으로 충분하다.

위와 같이 프로그램을 짜면 분할로 인한 함수 호출 횟수 nlogn + 누적합 n + 그리디 연산 nlogn
도합 O(nlogn) 이 걸린다.
구간을 저장해야 함에 유의.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Ans = pair<long long, pair<int, int>>;

long long arr[100001], accuSum[100001];

Ans solveFunc(int left, int right);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrLen;
    cin >> arrLen;

    for (int i = 1; i <= arrLen; i++)
    {
        cin >> arr[i];
        accuSum[i] = accuSum[i - 1] + arr[i];
    }

    Ans result = solveFunc(1, arrLen);
    
    cout << result.first << '\n';
    cout << result.second.first << ' ' << result.second.second;

	return 0;
}

enum {LEFT, MIDDLE, RIGHT};
Ans solveFunc(int left, int right)
{
    Ans result[3];

    if (right - left == 0)
    {
        return make_pair(arr[left] * arr[left], 
                make_pair(left, right));
    } 
    else if (right - left == 1)
    {
        result[LEFT] = solveFunc(left, left);
        result[RIGHT] = solveFunc(right, right);
        result[MIDDLE].first = min(arr[left], arr[right]) * (arr[left] + arr[right]);
        result[MIDDLE].second = {left, right};
    } else {

        int mid = (left + right) / 2;
        result[LEFT] = solveFunc(left, mid);
        result[RIGHT] = solveFunc(mid + 1, right);

        pair<int, int> arrRange = {mid + 1, mid};
        long long mul = 10000000;
        result[MIDDLE].first = -1;

        while (arrRange.first != left && arrRange.second != right)
        {
            if (arr[arrRange.first - 1] < arr[arrRange.second + 1])
            {
                arrRange.second += 1;
                mul = min(mul, arr[arrRange.second]);
            } else {
                arrRange.first -= 1;
                mul = min(mul, arr[arrRange.first]);
            }

            long long val = (accuSum[arrRange.second] - accuSum[arrRange.first - 1]) * mul;
            if (result[MIDDLE].first < val)
            {
                result[MIDDLE].first = val;
                result[MIDDLE].second = arrRange;
            }
        }

        while (arrRange.first != left)
        {
            arrRange.first -= 1;
            mul = min(mul, arr[arrRange.first]);
            long long val = (accuSum[arrRange.second] - accuSum[arrRange.first - 1]) * mul;
            if (result[MIDDLE].first < val)
            {
                result[MIDDLE].first = val;
                result[MIDDLE].second = arrRange;
            }
        }

        while (arrRange.second != right)
        {
            arrRange.second += 1;
            mul = min(mul, arr[arrRange.second]);
            long long val = (accuSum[arrRange.second] - accuSum[arrRange.first - 1]) * mul;
            if (result[MIDDLE].first < val)
            {
                result[MIDDLE].first = val;
                result[MIDDLE].second = arrRange;
            }
        }

    }

    return *max_element(result, result + 3);
}