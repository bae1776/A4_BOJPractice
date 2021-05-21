//https://www.acmicpc.net/problem/17298

/*��ū��

ũ�� N ���� : A1, A2... An�� ���Ͽ�
��ū�� NGE(i) = (Ai�� �����ʿ� �����鼭 Ai ���� ū �� �߿��� ���� ���ʿ� �ִ� ��)
�� ������ ��,
�ִ� 100�� ������ ������ ���Ͽ� ��ū�� �迭�� ���ϼ���.
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
