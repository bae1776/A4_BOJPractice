//https://www.acmicpc.net/problem/1517

/*버블 소트 (Platinum 5)
Solution : 좌표 압축 후 세그먼트 트리
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int left, right, value;
};

constexpr int maxSize = (1 << 20);
int treeSize;
pair<int, int> arr[maxSize];
Node segmentTree[maxSize]; //left right value

void setSegmentTree(int size);
void addOneAll();
int rangeSum(int left, int right);
void subOne(int index);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long answer = 0;
    int arrLen;
    cin >> arrLen;

    setSegmentTree(arrLen);

    for (int i = 0; i < arrLen; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    addOneAll();

    sort(arr, arr + arrLen);

    for (int i = 0; i < arrLen; i++)
    {
        int& val = arr[i].second;
        answer += rangeSum(0, val - 1);
        subOne(val);
    }

    cout << answer;

	return 0;
}


void setSegmentTree(int size)
{
    segmentTree[1].left = 0;
    segmentTree[1].right = size - 1;

    int move = 19;
    while (size <= (1 << move))
        move--;

    treeSize = 1 << (move + 2);
    const int loopEnd = treeSize / 2;
    for (int idx = 1; idx < loopEnd; idx++)
    {
        Node& n = segmentTree[idx];
        if (n.left != n.right)
        {
            int mid = (n.left + n.right) / 2;
            segmentTree[idx * 2].left = n.left;
            segmentTree[idx * 2].right = mid;
            segmentTree[idx * 2 + 1].left = mid + 1;
            segmentTree[idx * 2 + 1].right = n.right;
        }
    }
}


void addOneAll()
{
    for (int i = 1; i < treeSize; i++)
        segmentTree[i].value = segmentTree[i].right - segmentTree[i].left + 1;
}


int rangeSum(int left, int right)
{
    if (left > right) return 0;

    int total = 0;
    queue<int> treeIndexQueue;
    treeIndexQueue.push(1);

    while (treeIndexQueue.empty() == false)
    {
        int idx = treeIndexQueue.front();
        Node& now = segmentTree[idx];
        treeIndexQueue.pop();

        if (left <= now.left && now.right <= right)
        {
            total += now.value;
        } else {
            if (left <= segmentTree[idx * 2].right)
                treeIndexQueue.push(idx * 2);

            if (segmentTree[idx * 2 + 1].left <= right)
                treeIndexQueue.push(idx * 2 + 1); 
        }
    }

    return total;
}



void subOne(int index)
{
    int treeIndex = 1;

    while (true)
    {
        segmentTree[treeIndex].value--;

        if (segmentTree[treeIndex].left == segmentTree[treeIndex].right)
            break;
        else {
            if (index <= segmentTree[treeIndex * 2].right)
                treeIndex = treeIndex * 2;
            else
                treeIndex = treeIndex * 2 + 1;
        }
    }
}