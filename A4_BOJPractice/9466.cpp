//https://www.acmicpc.net/problem/9466

//텀 프로젝트

//학생들이서 팀을 짜는데, 각 학생은 팀원이 되고 싶은 1명만 지목한다.
//자기자신을 지목해도 되며, 지목 대상이 사이클을 이루면 팀이 된다.
//각 학생이 지목한 학생 번호가 주어졌을 때, 팀을 이루지 못하는 학생 수를 구하시오.

#include <iostream>
#include <set>
#include <vector>
using namespace std;




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		int studentCount;
		cin >> studentCount;

		vector<int> wants(studentCount + 1);
		for (int i = 1; i <= studentCount; i++)
			cin >> wants[i];

		vector<char> status(studentCount + 1, -1);

		for (int targetIndex = 1; targetIndex <= studentCount; targetIndex++)
		{
			if (status[targetIndex] != -1)
				continue;

			int now_pos = targetIndex;
			set<int> circuitFinder;

			while (circuitFinder.find(now_pos) == circuitFinder.end() && status[now_pos] == -1)
			{
				circuitFinder.insert(now_pos);
				now_pos = wants[now_pos];
			}

			if (status[now_pos] == -1)
			{
				//circulating and make True;
				while (status[now_pos] == -1)
				{
					status[now_pos] = true;
					now_pos = wants[now_pos];
				}

				//Isolated be False;
				int isolated = targetIndex;
				while (status[isolated] == -1)
				{
					status[isolated] = false;
					isolated = wants[isolated];
				}
			}
			else {
				//Isolated be False;
				int isolated = targetIndex;
				while (status[isolated] == -1)
				{
					status[isolated] = false;
					isolated = wants[isolated];
				}
			}
		}

		int isolatedCount = 0;

		for (int i = 1; i <= studentCount; i++)
		{
			if (status[i] == 0)
				isolatedCount++;
		}

		cout << isolatedCount << '\n';

	}

	return 0;
}