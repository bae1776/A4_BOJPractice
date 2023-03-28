//https://www.acmicpc.net/problem/1797

/*균형잡힌 줄서기 (Gold 2)
Solution : 
뭔가 남여 차가 +1, 0, -1 ... 인 걸 그룹을 지어서 더하기 빼기를 한다.
이때, 그룹에는 인덱스만 집어넣고
인덱스-팬의 위치를 대응하는 정렬된 배열을 따로 만든다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int groupArr[2000003][3];
pair<int, bool> fanList[1000000]; //[인덱스] = 그 팬의 위치, 성별


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int fanCount;
	cin >> fanCount;

	for (int i = 0; i < fanCount; i++)
		cin >> fanList[i].second >> fanList[i].first;

	sort(fanList, fanList + fanCount);
	int (*diffGroup)[3] = groupArr + 1000000;
	//다음 2라인은, 남녀 차가 0명인 아무도 없는 그룹을 만들어 놓음
	diffGroup[0][0] = 1;
	diffGroup[0][1] = -1;

	int diff = 0;
	for (int i = 0; i < fanCount; i++)
	{
		if (fanList[i].second)
			diff++;
		else
			diff--;

		if (diffGroup[diff][0] == 0)
		{
			diffGroup[diff][0]++;
			diffGroup[diff][1] = i;
		} else if (diffGroup[diff][0] == 1) {
			diffGroup[diff][0]++;
			diffGroup[diff][2] = i;
		} else if (diffGroup[diff][0] == 2) {
			diffGroup[diff][2] = i;
		}
	}
	
	int answer = 0;
	for (int i = -1000000; i <= 1000000; i++)
	{
		if (diffGroup[i][0] == 2)
			answer = max(answer, fanList[diffGroup[i][2]].first - fanList[diffGroup[i][1] + 1].first);
	}

	cout << answer;


	return 0;
}
