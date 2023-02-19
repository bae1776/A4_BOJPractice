//https://www.acmicpc.net/problem/2104

/* 부분배열 고르기 (Platinum 5)
부분배열 고르기 2 (1989번)의 복습이다.

Solution : 분할 정복 -> O(nlogn)
*/


#include <iostream>
using namespace std;

long long arr[100001];
long long func(int start, int end);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arrSize;
	cin >> arrSize;

	for (int i = 0; i < arrSize; i++)
		cin >> arr[i];

	cout << func(0, arrSize - 1);


	return 0;
}



long long func(int start, int end)
{
	if (start == end)
		return arr[start] * arr[start];

	int mid = (start + end) / 2;
	long long partMax = max(func(start, mid), func(mid + 1, end));
	long long innerMax = 0;

	int toLeft = mid, toRight = mid + 1;
	long long sum = 0;
	long long arrMin = 0x7FFFFFFFll;

	while (toLeft >= start && toRight <= end)
	{
		if (arr[toLeft] > arr[toRight])
		{
			sum += arr[toLeft];
			arrMin = min(arrMin, arr[toLeft--]);
			innerMax = max(innerMax, sum * arrMin);
		} else {
			sum += arr[toRight];
			arrMin = min(arrMin, arr[toRight++]);
			innerMax = max(innerMax, sum * arrMin);
		}
	}

	while (toLeft >= start)
	{
		sum += arr[toLeft];
		arrMin = min(arrMin, arr[toLeft--]);
		innerMax = max(innerMax, sum * arrMin);
	}

	while (toRight <= end)
	{
		sum += arr[toRight];
		arrMin = min(arrMin, arr[toRight++]);
		innerMax = max(innerMax, sum * arrMin);
	}

	return max(partMax, innerMax);
}