//https://www.acmicpc.net/problem/27085

/*최대 점수 (Gold 2)
문제 설명
*/

#include <iostream>
#include <list>
using namespace std;

int roomList[200002];
list<pair<long long, long long>> leftList, rightList; //reqScore, netGain

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int roomCount, startPoint;
    cin >> roomCount >> startPoint;

    for (int i = 1; i <= roomCount; i++)
        cin >> roomList[i];

    long long reqScore = 0, netGain = 0;
    for (int l = startPoint - 1; l >= 1; l--)
    {
        netGain += roomList[l];
        
        if (netGain >= 0)
        {
            leftList.emplace_back(reqScore, netGain);
            reqScore = netGain = 0;
        } else {
            reqScore = max(reqScore, -netGain);
        }
    }
	
    reqScore = netGain = 0;
    for (int r = startPoint + 1; r <= roomCount; r++)
    {
        netGain += roomList[r];
        
        if (netGain >= 0)
        {
            rightList.emplace_back(reqScore, netGain);
            reqScore = netGain = 0;
        } else {
            reqScore = max(reqScore, -netGain);
        }
    }

    long long score = 0;
    while (true)
    {
        if (leftList.empty() == false && leftList.front().first <= score)
        {
            score += leftList.front().second;
            leftList.pop_front();
            continue;
        }

        if (rightList.empty() == false && rightList.front().first <= score)
        {
            score += rightList.front().second;
            rightList.pop_front();
            continue;
        }

        break;
    }

    cout << score;

	return 0;
}