//https://www.acmicpc.net/problem/17298

/*오큰수

크기 N 수열 : A1, A2... An에 대하여
오큰수 NGE(i) = (Ai의 오른쪽에 있으면서 Ai 보다 큰 수 중에서 가장 왼쪽에 있는 수)
로 정의할 때,
최대 100만 길이의 수열에 대하여 오큰수 배열을 구하세요.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int size;
	cin >> size;

	vector<int> arr(size), NGEarr(size);

	for (int& val : arr)
		cin >> val;

	stack<int> Stack;

	for (int i = size - 1; i >= 0; i--)
	{
		while (Stack.empty() == false)
		{
			if (arr[i] >= Stack.top())
				Stack.pop();
			else
				break;
		}

		if (Stack.empty() == true)
			NGEarr[i] = -1;
		else
			NGEarr[i] = Stack.top();

		Stack.push(arr[i]);
	}


	for (int& val : NGEarr)
		cout << val << ' ';
	

	return 0;
}
