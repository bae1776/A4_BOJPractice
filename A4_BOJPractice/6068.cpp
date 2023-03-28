//https://www.acmicpc.net/problem/6068

/*시간 관리하기 (Gold 5)

Solution : 그리디 알고리즘
어차피 해야될 일인데 마감일까지 최대한 미뤄서 한다.
가장 늦게 마감해야 될 일(A)이 1000에 끝내야하고, 그 다음 늦는 일(B)은 990 이라면
그 사이 시간 동안 할 수 있는 일은 A 밖에 없다. 그때 A를 하고 있는 게 최적일 것이다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> taskList[1000]; //deadline, duration

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int task;
    cin >> task;

    for (int i = 0; i < task; i++)
        cin >> taskList[i].second >> taskList[i].first;
    
	sort(taskList, taskList + task, greater<pair<int, int>>());

    int lateTime = taskList[0].first;
	for (int i = 0; i < task; i++)
		lateTime = min(lateTime - taskList[i].second, taskList[i].first - taskList[i].second);
	
	if (lateTime >= 0)
		cout << lateTime;
	else
		cout << -1;

	return 0;
}
