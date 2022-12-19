//https://www.acmicpc.net/problem/10999

/*구간 합 구하기 2 (Platinum 4)

N(최대 100만)개의 정수 배열은 중간의 수의 변경이 자주 일어난다.

1. arr[a]~arr[b]에 c를 더하는 명령 최대 1만개
2. arr[a]~arr[b]의 합을 구하는 명령 최대 1만개

를 모두 합쳐 2초 안에 처리할 수 있는 프로그램을 구현하십시오.

Solution : 느리게 갱신되는 세그먼트 트리의 기본 문제이다.
https://book.acmicpc.net/ds/segment-tree-lazy-propagation
(이전 단계 문제(세그먼트 트리 기본) : 구간 합 구하기 - 2042번)

펜윅 트리로도 풀 수 있다.

10 5 5
3 6 2 5 3 1 8 9 7 3
*/

#include <iostream>
#include <vector>
using namespace std;

class LazySegmentTree {
private:
	struct Node {
		long long value, lazy;
		int start, end;
	};
	
	vector<Node> tree;
	void makeTree(const int& index, const int& start, const int& end);
	void rangeAdd(const int& start, const int& end, const long long& value, const int& index);
	long long rangeSum(const int& start, const int& end, const int& index);

public:
	LazySegmentTree(int size);
	LazySegmentTree() = delete;

	void rangeAdd(const int& start, const int& end, const long long& value);
	long long rangeSum(const int& start, const int& end);
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int numCount, changeCount, sumCount;
	cin >> numCount >> changeCount >> sumCount;

	LazySegmentTree lSegTree(numCount);
	int queryCount = changeCount + sumCount;

	//(1) 각 배열값 추가
	for (int i = 1; i <= numCount; i++)
	{
		long long arrInput;
		cin >> arrInput;
		lSegTree.rangeAdd(i, i, arrInput);
	}

	//(2) 쿼리 처리
	int queryInput, rangeStart, rangeEnd;
	long long value;
	while (queryCount--)
	{
		cin >> queryInput;

		switch (queryInput)
		{
		case 1: //rangeAdd
			cin >> rangeStart >> rangeEnd >> value;
			lSegTree.rangeAdd(rangeStart, rangeEnd, value);
			break;

		case 2: //rangeSum
			cin >> rangeStart >> rangeEnd;
			cout << lSegTree.rangeSum(rangeStart, rangeEnd) << '\n';
		}
	}

	

	return 0;
}











void LazySegmentTree::makeTree(const int& index, const int& start, const int& end)
{
	Node& now = this->tree[index];

	now.value = now.lazy = 0;
	now.start = start;
	now.end = end;

	if (start == end)
		return;
	else {
		int mid = (start + end) / 2;
		this->makeTree(index * 2, start, mid);
		this->makeTree(index * 2 + 1, mid + 1, end);
	}
}


void LazySegmentTree::rangeAdd(const int& start, const int& end, const long long& value, const int& index)
{
	Node& now = this->tree[index];

	//0. lazy 값이 있는 경우 갱신
	if (now.lazy != 0)
	{
		now.value += now.lazy * (now.end - now.start + 1);

		if (now.start != now.end)
		{
			this->tree[index * 2].lazy += now.lazy;
			this->tree[index * 2 + 1].lazy += now.lazy;
		}

		now.lazy = 0;
	}
	
	if (start <= now.start && now.end <= end)
	{ //1. 덧셈 범위 내부인 경우
		now.value += value * (now.end - now.start + 1);
		
		if (now.start != now.end)
		{
			this->tree[index * 2].lazy += value;
			this->tree[index * 2 + 1].lazy += value;
		}
	}
	else if (now.end < start || end < now.start)
	{ //2. 덧셈 범위에 전혀 포함되지 않는 경우
		return;
	}
	else 
	{ //3. 덧셈 범위를 일부라도 포함하고 있으며, 외부 구간도 있는 경우
		int overlapStart = max(start, now.start);
		int overlapEnd = min(end, now.end);

		now.value += value * (overlapEnd - overlapStart + 1);

		this->rangeAdd(start, end, value, index * 2);
		this->rangeAdd(start, end, value, index * 2 + 1);
	}
}


long long LazySegmentTree::rangeSum(const int& start, const int& end, const int& index)
{
	Node& now = this->tree[index];

	//0. lazy 값이 있는 경우 갱신
	if (now.lazy != 0)
	{
		now.value += now.lazy * (now.end - now.start + 1);

		if (now.start != now.end)
		{
			this->tree[index * 2].lazy += now.lazy;
			this->tree[index * 2 + 1].lazy += now.lazy;
		}

		now.lazy = 0;
	}

	if (start <= now.start && now.end <= end)
	{ //1. 덧셈 범위 내부인 경우
		return now.value;
	}
	else if (now.end < start || end < now.start)
	{ //2. 덧셈 범위에 전혀 포함되지 않는 경우
		return 0;
	}
	else
	{ //3. 덧셈 범위를 일부라도 포함하고 있으며, 외부 구간도 있는 경우
		return this->rangeSum(start, end, index * 2) + this->rangeSum(start, end, index * 2 + 1);
	}
}


LazySegmentTree::LazySegmentTree(int size)
{
	int treeSize = 2;
	while (treeSize < size * 2)
		treeSize <<= 1;

	this->tree = vector<Node>(treeSize);

	//node configuration
	this->makeTree(1, 1, size);
}


void LazySegmentTree::rangeAdd(const int& start, const int& end, const long long& value)
{
	this->rangeAdd(start, end, value, 1);
}

long long LazySegmentTree::rangeSum(const int& start, const int& end)
{
	return this->rangeSum(start, end, 1);
}