//https://www.acmicpc.net/problem/17162

//������ ���� ����
//(������ ���� ���� ó�� ����, ���� ����� logN ���Ͽ� �ذ��ؾ� ��)
//1. ���� ���� ���� �߰�
//2. ���� �� ����
//3. �� �ڿ������� mod�� ���������� 0...(mod-1) �������� ��� �������� �� ���� ���� �����ؾ� �ϴ°�?


#include <iostream>
#include <vector>
#include <stack>
using namespace std;




int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int queryCount, mod;
	cin >> queryCount >> mod;

	vector<stack<int>> modHashTable(mod);
	stack<int> elementIndex;
	int listIndex = 0;

	for (int query = 0; query < queryCount; query++)
	{
		int queryNum, i;
		cin >> queryNum;

		switch (queryNum)
		{
		case 1:
			cin >> i;
			i = i % mod;
			modHashTable[i].push(listIndex++);
			elementIndex.push(i);

			break;

		case 2:
			if (elementIndex.empty())
				break;
			i = elementIndex.top();
			elementIndex.pop();
			modHashTable[i].pop();
			listIndex--;

			break;

		case 3:
			i = listIndex;
			for (stack<int>& recentIdx : modHashTable)
			{
				if (recentIdx.empty() == true)
				{
					i = -1;
					break;
				}
				if (recentIdx.top() < i)
					i = recentIdx.top();
			}

			if (i == -1)
				cout << -1 << '\n';
			else
				cout << listIndex - i << '\n';
		}

	}


	return 0;
}