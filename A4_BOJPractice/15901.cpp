//https://www.acmicpc.net/problem/15901

/* 소각로 (Platinum 1)

Solution : 
대기열에는 덱, 소각로에는 세그먼트 트리.

단순 구현으로 쓰레기를 하나하나 모두 다루게 되면 최악의 경우 Q(50만) * 50만으로 시간 초과가 난다.
모든 쿼리를 logN 이내로 처리할 수 있게 짜야한다.

1번 쿼리 : 소각 작업
>> 소각로(세그먼트 트리)에 대기열 번호를 갱신한다.
범위 내에 들어가는 노드들(부분 소각로)의 대기열 시작 인덱스, 끝 인덱스를 저장해 놓는다.
이때, DFS 탐색해야 편하다.

2번 쿼리 : 소각로 칸 출력
>> 소각로(세그먼트 트리)의 리프 노드를 찾아가 출력한다. (+ 대기열 이분탐색)
(가장 최근의 소각 기록만을 이용한다)

3번 쿼리 : 대기열 추가
>> 대기열(맵)에 <대기열 번호(끝부분), 쓰레기 번호> 쌍을 하나 추가한다.

4번 쿼리 : 대기열 삭제
>> 가장 앞 대기열 번호 값을 더한다.

그리고 마지막에는 전체 세그먼트 트리를 DFS(왼쪽 노드 우선) 탐색하면 된다.
(각 리프노드마다 마지막 소각 기록만을 출력함)
*/


#include <iostream>
#include <deque>
#include <stack>
using namespace std;

struct SegNode {
    int start, end;
    long long wasteStart, wasteEnd;
    int fireOrder;
};

SegNode segTree[(1 << 20) + 20];
deque<pair<long long, int>> waitList; //<orderEnd, wasteNumber>
long long waitFront, waitBack;
int fireLength, trashSort, queryCount, fireCount;

void makeSegmentTree(const int& num, const int& start, const int& end);
void fire(const int& start, const int& end);
void printTrash(const int& index);
void appendTrash(const int& trashNumber, const int& trashCount);
void popFrontTrash(const long long& popCount);
void printList(int lastestFireIndex, const int& num);



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int waitListLengthBegin;
    cin >> waitListLengthBegin >> fireLength >> trashSort >> queryCount;
    
    //시작 대기열 입력
    for (long long num = 1; num <= waitListLengthBegin; num++)
    {
        int trashNumber;
        cin >> trashNumber;
        waitList.emplace_back(num, trashNumber);
    }
    waitFront = 1;
    waitBack = waitListLengthBegin;

    //소각로 세그먼트 트리 생성
    makeSegmentTree(1, 1, fireLength);

    //빈 소각로에 쓰레기 채우기 (1번 쿼리를 소각로 전범위에 실행한다.)
    fire(1, fireLength);
	
    while (queryCount--)
    {
        int queryNumber, p1, p2;
        long long p3;
        cin >> queryNumber;

        switch (queryNumber)
        {
            case 1: //[L, R] 구간 소각 : fire 함수
                cin >> p1 >> p2;
                ++fireCount;
                fire(p1, p2);
                break;
            
            case 2: //i번 소각로 쓰레기 검색 : findTrash 함수
                cin >> p1;
                printTrash(p1);
                break;

            case 3: //대기열에 p1 쓰레기 p2개 추가 : appendTrash 함수
                cin >> p1 >> p2;
                appendTrash(p1, p2);
                break;

            case 4: //맨 앞의 쓰레기 t개 제거 : popFrontTrash 함수
                cin >> p3;
                popFrontTrash(p3);
        }
    }

    cout << '\n';
    printList(1, 1);

	return 0;
}


void makeSegmentTree(const int& num, const int& start, const int& end)
{
    auto& now = segTree[num];
    now.start = start;
    now.end = end;

    if (start == end)
        return;

    int mid = (start + end) / 2;

    makeSegmentTree(num * 2, start, mid);
    makeSegmentTree(num * 2 + 1, mid + 1, end);
}


void fire(const int& start, const int& end)
{
    stack<int> treeDFS;
    treeDFS.push(1); //Starting at Root node

    while (treeDFS.empty() == false)
    {
        int parent = treeDFS.top();
        treeDFS.pop();
        SegNode& now = segTree[parent];

        if (start <= now.start && now.end <= end)
        {
            now.fireOrder = fireCount;
            if (waitFront <= waitBack)
            {
                now.wasteStart = waitFront;
                now.wasteEnd = min(waitBack, now.wasteStart + now.end - now.start);
                waitFront = now.wasteEnd + 1;
            } else {
                now.wasteStart = 0xFFFFFFFFFFFF;
                now.wasteEnd = 0; //해당 구간 소각로는 모두 빈 칸임을 의미
            }
        } else {
            int mid = (now.start + now.end) / 2;

            if (mid + 1 <= end)
                treeDFS.push(parent * 2 + 1);
            if (start <= mid)
                treeDFS.push(parent * 2);
            
        }
    }
}


void printTrash(const int& index)
{
    int latestFireIndex = 1;
    int treeIndex = 1;

    //세그먼트 트리의 리프노드 찾아가기 + 그 리프노드에 대한 최근 소각기록 탐색
    while (segTree[treeIndex].start != segTree[treeIndex].end)
    {
        if (segTree[treeIndex].fireOrder > segTree[latestFireIndex].fireOrder)
            latestFireIndex = treeIndex;

        int mid = (segTree[treeIndex].start + segTree[treeIndex].end) / 2;
        if (index <= mid)
            treeIndex = treeIndex * 2;
        else
            treeIndex = treeIndex * 2 + 1;
    }

    if (segTree[treeIndex].fireOrder > segTree[latestFireIndex].fireOrder)
        latestFireIndex = treeIndex;

    SegNode& recentFire = segTree[latestFireIndex];
    long long waitListIndex = recentFire.wasteStart + index - recentFire.start;

    if (waitListIndex <= recentFire.wasteEnd)
        cout << lower_bound(waitList.begin(), waitList.end(), make_pair(waitListIndex, 0))->second << ' ';
    else    
        cout << 0 << ' ';
    
    return;
}

void appendTrash(const int& trashNumber, const int& trashCount)
{
    waitBack += trashCount;
    waitList.emplace_back(waitBack, trashNumber);
}

void popFrontTrash(const long long& popCount)
{
    waitFront = min(waitFront + popCount, waitBack + 1);
}

void printList(int lastestFireIndex, const int& num)
{
    SegNode& now = segTree[num];
    if (now.fireOrder > segTree[lastestFireIndex].fireOrder)
        lastestFireIndex = num;

    if (now.start == now.end)
    {
        SegNode& recentFire = segTree[lastestFireIndex];
        long long waitListIndex = recentFire.wasteStart + now.start - recentFire.start;

        if (waitListIndex <= recentFire.wasteEnd)
            cout << lower_bound(waitList.begin(), waitList.end(), make_pair(waitListIndex, 0))->second << ' ';
        else    
            cout << 0 << ' ';
    } else {
        printList(lastestFireIndex, num * 2);
        printList(lastestFireIndex, num * 2 + 1);
    }
}