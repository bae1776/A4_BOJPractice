//https://www.acmicpc.net/problem/3653

/*영화 수집 (Platinum 4)
Solution : 세그먼트 트리
영화가 9개일때 영화의 탑 배열 A를
[9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0 ....] 이라 하자.
그리고 영화가 있나 없나 (0, 1)만 저장하는 세그먼트 트리의 리프노드를 다음과 같이 구성하자
[1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 ....]

여기서 7번 영화를 시청하면, 위에 있었던 DVD 개수는 rangeSum(3, 8) 이고
탑 배열 A는
[9, 8, 0, 6, 5, 4, 3, 2, 1, 7, 0, 0, 0 ....] (7을 오른쪽으로 쌓았다)
세그먼트 트리 리프는
[1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 ....]이 될 것이다.

다음 시청한 영화의 배열 원소 인덱스를 찾으려면, 
실제 구현할 때는 위에 이해를 위해 썼던 A배열의 역으로 구현해야 할 것이다.
(arr[7] = 10 이 되도록)

영화의 개수가 최대 10만개 이기 때문에 rangeSum을 O(logN)에 계산하는 세그먼트 트리를 사용하자.
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int start, end;
	int value;
};

int cdLocation[200001];
Node segTree[1 << 19];

void makeSegmentTree(const int& index, const int& addEnd, const int& start, const int& end);
int rangeSum(const int& start, const int& end);
void eraseCD(const int& loc);
void addCD(const int& loc);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		int cdCount, queryCount;
		cin >> cdCount >> queryCount;

		makeSegmentTree(1, cdCount, 1, cdCount + queryCount);
		for (int i = 1; i <= cdCount; i++)
			cdLocation[i] = cdCount - i + 1;

		int top = cdCount;
		while (queryCount--)
		{
			//입력 받은 CD 번호에 대해
			int cdNumber;
			cin >> cdNumber;
	
			int cdLoc = cdLocation[cdNumber];
			//그 CD 위에 있는 CD 개수를 구한다. (세그먼트 트리)
			cout << rangeSum(cdLoc + 1, top) << ' ';

			//사용한 CD는 그 위치(cdLoc)에서는 제외되고 ++top 위치에 추가된다.
			eraseCD(cdLoc);
			addCD(++top);
			cdLocation[cdNumber] = top;		
		}
		cout << '\n';
	}

	return 0;
}



void makeSegmentTree(const int& index, const int& addEnd, const int& start, const int& end)
{
	Node& now = segTree[index];
	now.start = start;
	now.end = end;
	//세그먼트 트리의 리프는 1 ~ addEnd(cdCount)까지는 모두 1, 그 뒤로는 모두 0이어야 함.
	if (addEnd < now.start)
		now.value = 0;
	else {
		now.value = min(addEnd, now.end) - now.start + 1;
	}

	if (start != end)
	{
		int mid = (start + end) / 2;
		makeSegmentTree(index * 2, addEnd, start, mid);
		makeSegmentTree(index * 2 + 1, addEnd, mid + 1, end);
	}
}


int rangeSum(const int& start, const int& end)
{
	if (start > end) return 0;
	
	queue<int> bfsQueue;
	bfsQueue.push(1); //root

	int total = 0;
	while (bfsQueue.empty() == false)
	{
		int index = bfsQueue.front();
		bfsQueue.pop();
		const Node& now = segTree[index];

		if (start <= now.start && now.end <= end)
			total += now.value;
		else {
			int mid = (now.start + now.end) / 2;
			
			if (start <= mid)
				bfsQueue.push(index * 2);
			if (mid + 1 <= end)
				bfsQueue.push(index * 2 + 1);
		}
	}

	return total;
}


void eraseCD(const int& loc)
{
	int index = 1; //root

	while (true)
	{
		Node& now = segTree[index];
		now.value--;

		if (now.start == now.end)
			break;

		int mid = (now.start + now.end) / 2;
		if (loc <= mid)
			index = index * 2;
		else
			index = index * 2 + 1;
	} 
}

void addCD(const int& loc)
{
	int index = 1; //root

	while (true)
	{
		Node& now = segTree[index];
		now.value++;

		if (now.start == now.end)
			break;

		int mid = (now.start + now.end) / 2;
		if (loc <= mid)
			index = index * 2;
		else
			index = index * 2 + 1;
	} 
}