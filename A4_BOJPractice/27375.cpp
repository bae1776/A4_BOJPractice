//https://www.acmicpc.net/problem/27375

/*금공강사수 (Silver 1)

Solution : 완전 탐색

*/

#include <iostream>
#include <bitset>
#include <queue>
using namespace std;

struct Element {
    int depth;
    int credit;
    bitset<50> classIncluded;

    Element(const int& depth, const int& credit, const bitset<50>& classIncluded)
    : depth(depth), credit(credit), classIncluded(classIncluded) {};
};

int ableCount = 0;
pair<int, int> classDuration[20];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int classCount, credit;
    cin >> classCount >> credit;

    for (int i = 0; i < classCount; i++)
    {
        int day, start, end;
        cin >> day >> start >> end;
        classDuration[i].first = (day - 1) * 10 + start - 1;
        classDuration[i].second = (day - 1) * 10 + end - 1;
    }

    queue<Element> bfsQueue;
    bfsQueue.emplace(0, 0, bitset<50>());

    while (bfsQueue.empty() == false)
    {
        Element now = bfsQueue.front();
        bfsQueue.pop();

        if (now.depth == classCount)
        {
            if (now.credit == credit)
            {
                bool noFriday = true;
                for (int i = 40; i < 50; i++)
                    if (now.classIncluded[i] == true)
                    {
                        noFriday = false;
                        break;
                    }

                if (noFriday)
                    ableCount++;
            }

            continue;
        }

        //Not include
        bfsQueue.emplace(now.depth + 1, now.credit, now.classIncluded);

        //Include
        int nextCredit;
        if ((nextCredit = now.credit + classDuration[now.depth].second - classDuration[now.depth].first + 1) <= credit)
        {
            bool isBound = true;
            for (int i = classDuration[now.depth].first; i <= classDuration[now.depth].second; i++)
            {
                if (now.classIncluded[i] == true)
                {
                    isBound = false;
                    break;
                } else
                    now.classIncluded[i] = true;
            }

            if (isBound)
            {
                bfsQueue.emplace(now.depth + 1, nextCredit, now.classIncluded);
            }
        }
    }

	
    cout << ableCount;

    
	return 0;
}