//https://www.acmicpc.net/problem/17162

//가희의 수열 놀이
//(수열에 대한 쿼리 처리 문제, 다음 명령은 logN 이하에 해결해야 함)
//1. 수열 끝에 원소 추가
//2. 수열 끝 삭제
//3. 맨 뒤에서부터 mod로 나누었을때 0...(mod-1) 나머지가 모두 나오려면 몇 개의 수를 선택해야 하는가?


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