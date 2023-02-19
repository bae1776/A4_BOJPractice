//https://www.acmicpc.net/problem/20930

/*우주 정거장 (Platinum 5)
정렬 + 스위핑 + 분리 집합
*/

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int parent[200002];
int sRank[200002];
array<int, 5> lineList[200002]; //index startX startY endX endY

void union_merge(int a, int b);
int union_find(int a);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int lineCount, queryCount;
    cin >> lineCount >> queryCount;

    for (int i = 1; i <= lineCount; i++)
    {
        cin >> lineList[i][1] >> lineList[i][2] >> lineList[i][3] >> lineList[i][4];
        if (lineList[i][1] > lineList[i][3])
            swap(lineList[i][1], lineList[i][3]);

        if (lineList[i][2] > lineList[i][4])
            swap(lineList[i][2], lineList[i][4]);
        
        lineList[i][0] = parent[i] = i;
        sRank[i] = 1;
    }

    //x축 정렬
    sort(lineList + 1, lineList + lineCount + 1, [](const array<int, 5>& a, const array<int, 5>& b) -> bool {
        return a[1] < b[1];
    });

    int parent = lineList[1][0];
    int maxReachable = lineList[1][3];
    for (int idx = 2; idx <= lineCount; idx++)
    {
        if (lineList[idx][1] <= maxReachable)
        {
            maxReachable = max(maxReachable, lineList[idx][3]);
            union_merge(parent, lineList[idx][0]);
        } else {
            parent = lineList[idx][0];
            maxReachable = lineList[idx][3];
        }
    }

    //y축 정렬
    sort(lineList + 1, lineList + lineCount + 1, [](const array<int, 5>& a, const array<int, 5>& b) -> bool {
        return a[2] < b[2];
    });

    parent = lineList[1][0];
    maxReachable = lineList[1][4];
    for (int idx = 2; idx <= lineCount; idx++)
    {
        if (lineList[idx][2] <= maxReachable)
        {
            maxReachable = max(maxReachable, lineList[idx][4]);
            union_merge(parent, lineList[idx][0]);
        } else {
            parent = lineList[idx][0];
            maxReachable = lineList[idx][4];
        }
    }

    //인덱스 정렬
    sort(lineList + 1, lineList + lineCount + 1);
    
    while (queryCount--)
    {
        int a, b;
        cin >> a >> b;

        cout << (union_find(a) == union_find(b)) << '\n';
    }
	
	return 0;
}



void union_merge(int a, int b)
{
    a = union_find(a);
    b = union_find(b);

    if (a == b) return;

    if (sRank[a] < sRank[b])
    {
        parent[a] = b;
    } else {
        parent[b] = a;
        if (sRank[a] == sRank[b])
            sRank[b]++;
    }

}

int union_find(int a)
{
    if (parent[a] == a)
        return a;
    else
        return parent[a] = union_find(parent[a]);
}