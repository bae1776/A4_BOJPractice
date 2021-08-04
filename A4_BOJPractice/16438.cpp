//https://www.acmicpc.net/problem/16438

/*원숭이 스포츠

N(<=99)마리의 원숭이들이 두 팀으로 갈라서 7번 경기를 하려고 합니다.
모든 두 원숭이에 대해서 적어도 한 번은 상대팀으로 만나도록 하는 대진표를 작성해 주세요.

*/

#include <iostream>
#include <queue>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int monkey;
    cin >> monkey;

    char* teamlist = new char[monkey];
    for (int i = 0; i < monkey / 2; i++)
        teamlist[i] = 'A';
    for (int i = monkey / 2; i < monkey; i++)
        teamlist[i] = 'B';

    queue<pair<int, int>> splitQueue;
    queue<int> depthQueue;

    splitQueue.emplace(0, monkey/2);
    depthQueue.emplace(1);
    splitQueue.emplace(monkey/2, monkey);
    depthQueue.emplace(1);

    int nowdepth = 0;
    int playCount = 7;

    while (playCount)
    {
        if (nowdepth != depthQueue.front())
        {
            bool isA = false;
            for (int i = 0; i < monkey - 1; i++)
            {
                cout << teamlist[i];
                if (teamlist[i] == 'A')
                    isA = true;
            }

            if (isA)
                cout << teamlist[monkey-1];
            else
                cout << 'A';

            cout << '\n';

            nowdepth = depthQueue.front();
            playCount--;
        }
        depthQueue.pop();

        auto nowSplit = splitQueue.front();
        splitQueue.pop();

        const int mid = (nowSplit.first + nowSplit.second) / 2;

        for (int i = nowSplit.first; i < mid; i++)
            teamlist[i] = 'A';

        for (int i = mid; i < nowSplit.second; i++)
            teamlist[i] = 'B';

        if (nowSplit.first == nowSplit.second)
        {
            splitQueue.emplace(nowSplit.first, nowSplit.second);
            depthQueue.emplace(nowdepth + 1);
        } else {
            splitQueue.emplace(nowSplit.first, mid);
            depthQueue.emplace(nowdepth + 1);
            splitQueue.emplace(mid, nowSplit.second);
            depthQueue.emplace(nowdepth + 1);    
        }
        
        

    }

    

	return 0;
}
