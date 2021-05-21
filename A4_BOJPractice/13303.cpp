//https://www.acmicpc.net/problem/13303

//장애물
//직교 좌표 상에서 선수는 (0, A) 지점에서 오른쪽(+x) 방향으로 달려 결승선(x = B인 수직선)으로 가려한다.
//선수 출발선과 결승선 사이에는 N개의 수직 장애물이 있는데, (N은 최대 10만)
//오른쪽 방향으로 달리다가 장애물을 만나면, 장애물을 피해 무조건 위 또는 아래로 달렸다가
//다시 오른쪽 방향으로만 뛰어야한다.
//A, B, N과 각 장애물의 x좌표, 아랫쪽 끝, 윗 끝 y좌표가 주어질 때,
//장애물을 피하면서 목적지에 도달할 수 있는 최단경로의 길이 및 갯수를 출력하고
//그리고 각 최단경로를 거쳐서 결승선에 도착했을 때의 y좌표를 오름차순으로 출력하시오.
//x좌표는 0~1000000, y좌표는 0~2000000 이며
//모든 장애물의 x좌표는 0 보다 크고 B보다 작으며 장애물이 한 점에서 만나거나 겹치는 경우는 없다.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define LMAX 0x7FFFFFFFFFFFFFFF
using namespace std;
using RouteState = pair<int, long long>; //y, distance

struct Block
{
    int x, startY, endY;

    Block(int x, int sY, int eY) : x(x), startY(sY), endY(eY) {};

    bool operator<(const Block& bl) const
    {
        return this->x < bl.x;
    }
};

vector<Block> blockList;

int main(void)
{	
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    //1. input data
    int blockCount, startY, endX;
    cin >> blockCount;
    cin >> startY >> endX;

    blockList.reserve(blockCount);
    
    for (int i = 0; i < blockCount; i++)
    {
        int blockX, blockStartY, blockEndY;
        cin >> blockX >> blockStartY >> blockEndY;

        blockList.emplace_back(blockX, blockStartY, blockEndY);
    }

    //2. sort blockList by X ascend order
    sort(blockList.begin(), blockList.end());

    //3. make stateset and input initial state
    set<RouteState> stateSet;
    stateSet.emplace(startY, 0);

    set<RouteState>::iterator blockEncounter_start, blockEncounter_end;

    for (const auto& nowBlock : blockList)
    {
        //4. renew states that encounter block.
        long long upMin = LMAX, downMin = LMAX;
        blockEncounter_start = stateSet.upper_bound(make_pair(nowBlock.startY, LMAX));
        blockEncounter_end = stateSet.lower_bound(make_pair(nowBlock.endY, -1));

        bool caseEncounts = false;
        for (auto it = blockEncounter_start; it != blockEncounter_end; ++it)
        {   
            caseEncounts = true;
            upMin = min(upMin, nowBlock.endY - it->first + it->second);
            downMin = min(downMin, it->first - nowBlock.startY + it->second);
        }

        if (caseEncounts == true)
        {
            stateSet.erase(blockEncounter_start, blockEncounter_end);
            stateSet.emplace(nowBlock.startY, downMin);
            stateSet.emplace(nowBlock.endY, upMin);
        }
    }


    
    //5. print result
    long long minDist = LMAX;
    for (auto setIter = stateSet.begin(); setIter != stateSet.end(); ++setIter)
    {
        if (setIter->second < minDist)
            minDist = setIter->second;
    }
    cout << minDist + endX << '\n';

    vector<int> equalYList;
    for (auto setIter = stateSet.begin(); setIter != stateSet.end(); ++setIter)
    {
        if (minDist == setIter->second)
            equalYList.emplace_back(setIter->first);
    }

    cout << equalYList.size() << ' ';
    for (auto itr = equalYList.begin(); itr != equalYList.end(); ++itr)
        cout << *itr << ' ';

    return 0;
}
