//https://www.acmicpc.net/problem/1005

/*ACM Craft (Gold 3)

Solution : 위상 정렬 + DP
평범한 위상 정렬 문제이지만 건설 시간이 포함되어있다.
어떤 건물의 최소 건설 시간은 
(자기 자신 건설 시간) + (선행 건물 중 가장 늦게 완료된 시간) 이다
*/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
#define NODE 1001
int in[NODE], buildTime[NODE], minTime[NODE];
list<int> out[NODE];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int buildCount, buildRule;
        cin >> buildCount >> buildRule;

        fill(in, in + buildCount + 1, 0);
        fill(out, out + buildCount + 1, list<int>());
        fill(minTime, minTime + buildCount + 1, 0);

        for (int i = 1; i <= buildCount; i++)
            cin >> buildTime[i];

        while (buildRule--)
        {
            int front, back;
            cin >> front >> back;
            out[front].push_back(back);
            in[back]++;
        }

        list<int> buildList;
        for (int i = 1; i <= buildCount; i++)
            if (in[i] == 0)
                buildList.push_back(i);
        
        int now, goal;
        cin >> goal;
        while ((now = buildList.front()) != goal)
        {
            buildList.pop_front();

            for (const int& next : out[now])
            {
                minTime[next] = max(minTime[next], minTime[now] + buildTime[now]);
                in[next]--;
                if (in[next] == 0)
                    buildList.push_back(next);
            }
        }

        cout << minTime[goal] + buildTime[goal] << '\n';
    }

	return 0;
}
