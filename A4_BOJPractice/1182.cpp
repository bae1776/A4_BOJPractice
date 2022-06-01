//https://www.acmicpc.net/problem/1182

/* �κм����� ��
* �ִ� 20�� ������ �迭���� �κ��� �����Ͽ� ���� S�� �Ǵ� ����� ���� ���Ͻÿ�.
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

	int arrLength, sum;
	cin >> arrLength >> sum;

	vector<int> arr(arrLength);

	for (auto& val : arr)
		cin >> val;

	int count = 0;
	stack<pair<int, int>> dfsStack;
	dfsStack.emplace(0, 0);


	while (!dfsStack.empty())
	{
		auto [depth, value] = dfsStack.top();
		dfsStack.pop();

		if (depth == arrLength)
		{
			if (value == sum)
				count++;
			continue;
		}
		else {
			dfsStack.emplace(depth + 1, value + arr[depth]);
			dfsStack.emplace(depth + 1, value);
		}
	}

	if (sum == 0)
		count--; //���ϴ� ���� 0�� ��� �ƹ��͵� �������� ���� ���� ������ �ƴϹǷ� �����ؾ� ��

	cout << count;
	

	

	return 0;
}
