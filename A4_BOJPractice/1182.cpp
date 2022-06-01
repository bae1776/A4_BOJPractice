//https://www.acmicpc.net/problem/1182

/* 부분수열의 합
* 최대 20개 길이의 배열에서 부분을 추출하여 합이 S가 되는 경우의 수를 구하시오.
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
		count--; //원하는 합이 0일 경우 아무것도 선택하지 않은 경우는 수열이 아니므로 제외해야 함

	cout << count;
	

	

	return 0;
}
