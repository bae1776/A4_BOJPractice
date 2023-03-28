//https://www.acmicpc.net/problem/12844

/*XOR (Platinum 3)
Solution : 느리게 갱신되는 세그먼트 트리

XOR 연산은 결합 법칙이 성립하므로, 
XOR 연산의 lazy가 결합되어 연산 순서가 바뀌게 되더라도 아무런 문제가 없다.
그리고 분배 법칙은 성립하지 않음에 유의한다.
K를 XOR할 때 범위 연산을 한다면,
범위에 속하는 원소 개수가 짝수 개면 그대로이고 홀수 개면 XOR K한다.

1395번 코드를 적당히 바꿨다.
*/


#include <iostream>
using namespace std;

struct LazySeg {
    int start;
    int end;
    int value;
    int lazy;
};
LazySeg segTree[(1 << 20) + 20];
int arr[500000];

void makeSegTree(int index, int start, int end);
void rangeXOR(int root, const int& start, const int& end, const int& num);
int getXOR(int root, const int& start, const int& end);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrLen;
    cin >> arrLen;
    for (int i = 0; i < arrLen; i++)
        cin >> arr[i];
    makeSegTree(1, 0, arrLen - 1);

    int queryCount;
    cin >> queryCount;
    while (queryCount--)
    {
        int queryNumber, start, end, num;
        cin >> queryNumber;

        switch (queryNumber)
        {
            case 1: //each value in [start, end] XOR num
                cin >> start >> end >> num;
                rangeXOR(1, start, end, num);
                break;

            case 2: //print arr[start] XOR ... XOR arr[end]
                cin >> start >> end;
                cout << getXOR(1, start, end) << '\n';
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
    now.value = now.lazy = 0;

    if (start == end) 
    {
        now.value = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    makeSegTree(index * 2, start, mid);
    makeSegTree(index * 2 + 1, mid + 1, end);
    now.value = segTree[index * 2].value ^ segTree[index * 2 + 1].value;   
}


void rangeXOR(int root, const int& start, const int& end, const int& num)
{   
    LazySeg& curNode = segTree[root];

    //1. lazy Update
    if (curNode.lazy)
    {
        if ((curNode.end - curNode.start) % 2 == 0)
            curNode.value ^= curNode.lazy;
        if (curNode.start != curNode.end)
        {
            segTree[root * 2].lazy ^= curNode.lazy;
            segTree[root * 2 + 1].lazy ^= curNode.lazy;
        }
        curNode.lazy = 0;
    }  

    //2. 구간에 따른 노드 처리
    if (curNode.end < start || end < curNode.start)
        return;
    else if (start <= curNode.start && curNode.end <= end)
    {
        if ((curNode.end - curNode.start) % 2 == 0)
            curNode.value ^= num;
        if (curNode.start != curNode.end)
        {
            segTree[root * 2].lazy ^= num;
            segTree[root * 2 + 1].lazy ^= num;
        }
    } else {
        rangeXOR(root * 2, start, end, num);
        rangeXOR(root * 2 + 1, start, end, num);
        curNode.value = segTree[root * 2].value ^ segTree[root * 2 + 1].value;
    }
}


int getXOR(int root, const int& start, const int& end)
{
    LazySeg& curNode = segTree[root];

    //1. lazy Update
    if (curNode.lazy)
    {
        if ((curNode.end - curNode.start) % 2 == 0)
            curNode.value ^= curNode.lazy;
        if (curNode.start != curNode.end)
        {
            segTree[root * 2].lazy ^= curNode.lazy;
            segTree[root * 2 + 1].lazy ^= curNode.lazy;
        }
        curNode.lazy = 0;
    }     

    //2. 구간에 따른 노드 처리
    if (curNode.end < start || end < curNode.start)
        return 0; //0 XOR A == A 
    else if (start <= curNode.start && curNode.end <= end)
        return curNode.value;
    else {
        return getXOR(root * 2, start, end) ^ getXOR(root * 2 + 1, start, end);
    }
}
