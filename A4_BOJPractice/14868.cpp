//https://www.acmicpc.net/problem/14868

/*문명 (Platinum 4)
N x N(최대 2000 x 2000) 2차원 공간 세계에 각각의 문명(최대 10만개)이 있고, 매해 상하좌우로 퍼져나간다.
모든 문명이 하나로 결합되는데 걸리는 최소 햇수를 정수로 출력하시오.
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int mergeCount = 0;
vector<int> civilizationUnionFind;
vector<int> civilizationRank;
list<pair<int, int>> civilizationBFS;

void union_merge(int a, int b);
int union_find(const int& a);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    int mapSize, civilizationCount;
    cin >> mapSize >> civilizationCount;

    vector<vector<int>> worldmap(mapSize, vector<int>(mapSize, 0));
    civilizationUnionFind = vector<int>(civilizationCount + 1);
    civilizationRank = vector<int>(civilizationCount + 1, 1);

    for (int i = 1; i <= civilizationCount; i++)
        civilizationUnionFind[i] = i;
        
    
    for (int civilNumber = 1; civilNumber <= civilizationCount; ++civilNumber)
    {
        int x, y;
        cin >> x >> y;
        worldmap[y - 1][x - 1] = civilNumber;
        civilizationBFS.emplace_back(y - 1, x - 1);
    }

    int year = 0;

    while (true)
    {
        //1. 문명 통합 확인
        for (const auto& borderCoord : civilizationBFS)
        {
            const int& borderCivil = worldmap[borderCoord.first][borderCoord.second];

            if (borderCoord.first != 0 && worldmap[borderCoord.first - 1][borderCoord.second] != 0)
                union_merge(borderCivil, worldmap[borderCoord.first - 1][borderCoord.second]);
            
            if (borderCoord.first != mapSize - 1 && worldmap[borderCoord.first + 1][borderCoord.second] != 0)
                union_merge(borderCivil, worldmap[borderCoord.first + 1][borderCoord.second]);
            
            if (borderCoord.second != 0 && worldmap[borderCoord.first][borderCoord.second - 1] != 0)
                union_merge(borderCivil, worldmap[borderCoord.first][borderCoord.second - 1]);
            
            if (borderCoord.second != mapSize - 1 && worldmap[borderCoord.first][borderCoord.second + 1] != 0)
                union_merge(borderCivil, worldmap[borderCoord.first][borderCoord.second + 1]);
        }

        if (mergeCount == civilizationCount - 1)
            break;

        year++;

        //2. 문명 확장
        int loopCount = civilizationBFS.size();
        while (loopCount--)
        {
            const auto& borderCoord = civilizationBFS.front();
            const int& borderCivil = worldmap[borderCoord.first][borderCoord.second];
            
            if (borderCoord.first != 0 && worldmap[borderCoord.first - 1][borderCoord.second] == 0)
            {
                worldmap[borderCoord.first - 1][borderCoord.second] = borderCivil;
                civilizationBFS.emplace_back(borderCoord.first - 1, borderCoord.second);
            }
            
            if (borderCoord.first != mapSize - 1 && worldmap[borderCoord.first + 1][borderCoord.second] == 0)
            {
                worldmap[borderCoord.first + 1][borderCoord.second] = borderCivil;
                civilizationBFS.emplace_back(borderCoord.first + 1, borderCoord.second);
            }
            
            if (borderCoord.second != 0 && worldmap[borderCoord.first][borderCoord.second - 1] == 0)
            {
                worldmap[borderCoord.first][borderCoord.second - 1] = borderCivil;
                civilizationBFS.emplace_back(borderCoord.first, borderCoord.second - 1);
            }
            
            if (borderCoord.second != mapSize - 1 && worldmap[borderCoord.first][borderCoord.second + 1] == 0)
            {
                worldmap[borderCoord.first][borderCoord.second + 1] = borderCivil;
                civilizationBFS.emplace_back(borderCoord.first, borderCoord.second + 1);
            }

            civilizationBFS.pop_front();
        }

    }
    cout << year;
    
	
	return 0;
}



void union_merge(int a, int b)
{
    int parentA = union_find(a), parentB = union_find(b);
    if (parentA == parentB)
        return;

    mergeCount++;

    if (civilizationRank[parentA] < civilizationRank[parentB])
    {
        civilizationUnionFind[parentA] = parentB;
    } else {
        civilizationUnionFind[parentB] = parentA;
        if (civilizationRank[parentA] == civilizationRank[parentB]);
            civilizationRank[parentA]++;
    }

}

int union_find(const int& a)
{
    if (civilizationUnionFind[a] == a)
        return a;
    else
        return civilizationUnionFind[a] = union_find(civilizationUnionFind[a]);
}