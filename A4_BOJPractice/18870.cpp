//https://www.acmicpc.net/problem/18870

/*좌표 압축
수직선 상 좌표 X1, X2... Xn에 대하여
Y1, Y2, ... Yn을 구하시오.
Ya = (Ya > Yb를 만족시키는 서로 다른 Yb의 개수)

n <= 1000000 임에 유의
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size;
	cin >> size;

	pair<int, int>* arr = new pair<int, int>[size];
	int* answer = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr, arr + size);

	int lBoundCount = 0;
	answer[arr[0].second] = 0;

	for (int i = 1; i < size; i++)
	{
		if (arr[i-1].first != arr[i].first)
			lBoundCount++;

		answer[arr[i].second] = lBoundCount;
	}

	for (int i = 0; i < size; i++)
		cout << answer[i] << ' ';

	delete[] arr;
	delete[] answer;

	return 0;
}
