//https://www.acmicpc.net/problem/1395

/*스위치 (Platinum 3)

Solution : 느리게 갱신되는 세그먼트 트리

쿼리 중 범위 갱신이 있기 때문에, 
이 과정이 O(N)이 걸리는 일반 세그먼트 트리는 안되고 Lazy propagation이 필요하다.
10999번(구간 합 구하기 2) 문제에서 이미 해본 바 있음.
10999번에서 연산이 int->bool 로 바뀐 거 빼고는 차이가 없다.

범위 합 구할 때 포함되는 범위 노드의 자식까지의 lazy는 모두 없애야 함에 유의할 것
*/

#include <iostream>
using namespace std;

struct LazySeg {
    int start;
    int end;
    int count;
    bool lazy;
};
LazySeg segTree[1 << 18];

void makeSegTree(int index, int start, int end);
void rangeSwap(int root, const int& start, const int& end);
int getCount(int root, const int& start, const int& end);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int switchCount, queryCount;
    cin >> switchCount >> queryCount;

    makeSegTree(1, 1, switchCount);

    while (queryCount--)
    {
        int queryNumber, start, end;
        cin >> queryNumber >> start >> end;

        switch (queryNumber)
        {
            case 0: //swap Switch in [start, end]
                rangeSwap(1, start, end);
                break;

            case 1: //count Power on switch in [start, end]
                cout << getCount(1, start, end) << '\n';
                break;
        }
    }
	
	return 0;
}



void makeSegTree(int index, int start, int end)
{
    LazySeg& now = segTree[index];
    now.start = start;
    now.end = end;
    now.count = 0;
    now.lazy = false;

    if (start == end) return;
    
    int mid = (start + end) / 2;
    makeSegTree(index * 2, start, mid);
    makeSegTree(index * 2 + 1, mid + 1, end);   
}


void rangeSwap(int root, const int& start, const int& end)
{   
    LazySeg& curNode = segTree[root];

    //1. lazy Update
    if (curNode.lazy)
    {
        curNode.count = curNode.end - curNode.start + 1 - curNode.count;
        if (curNode.start != curNode.end)
        {
            segTree[root * 2].lazy = !segTree[root * 2].lazy;
            segTree[root * 2 + 1].lazy = !segTree[root * 2 + 1].lazy;
        }
        curNode.lazy = false;
    }  

    //2. 구간에 따른 노드 처리
    if (curNode.end < start || end < curNode.start)
        return;
    else if (start <= curNode.start && curNode.end <= end)
    {
        curNode.count = curNode.end - curNode.start + 1 - curNode.count;
        if (curNode.start != curNode.end)
        {
            segTree[root * 2].lazy = !segTree[root * 2].lazy;
            segTree[root * 2 + 1].lazy = !segTree[root * 2 + 1].lazy;
        }
    } else {
        rangeSwap(root * 2, start, end);
        rangeSwap(root * 2 + 1, start, end);
        curNode.count = segTree[root * 2].count + segTree[root * 2 + 1].count;
    }
}


int getCount(int root, const int& start, const int& end)
{
    LazySeg& curNode = segTree[root];
    
    //1. lazy Update
    if (curNode.lazy)
    {
        curNode.count = curNode.end - curNode.start + 1 - curNode.count;
        if (curNode.start != curNode.end)
        {
            segTree[root * 2].lazy = !segTree[root * 2].lazy;
            segTree[root * 2 + 1].lazy = !segTree[root * 2 + 1].lazy;
        }
        curNode.lazy = false;
    }  

    //2. 구간에 따른 노드 처리
    if (curNode.end < start || end < curNode.start)
        return 0;
    else if (start <= curNode.start && curNode.end <= end)
        return curNode.count;
    else {
        return getCount(root * 2, start, end) + getCount(root * 2 + 1, start, end);
    }
}
