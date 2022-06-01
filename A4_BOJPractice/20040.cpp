//https://www.acmicpc.net/problem/20040

/*사이클 게임

사이클은 두 명의 플레이어가 차례대로 돌아가는 턴제 게임이다.
게임 시작 시 0부터 n-1까지 고유한 번호가 부여된 평면 상의 점 n개가 주어지며, 이 중 어느 세 점도 일직선 상에 놓이지 않는다.
매 차례마다 플레이어는 두 점을 선택해서 이를 연결하는 선분을 긋는다. 
(이전에 그린 선분를 다시 그을 순 없지만 선분이 교차할 수는 있다.)
게임을 진행하다가, 사이클이 하나 생성되면 게임이 끝난다.

문제는 선분을 여러 개 긋다보면 사이클이 완성 되었는 지 판단하기가 어렵다.
게임 진행 상황이 주어질 때, 사이클이 완성된 턴을 구하시오.
*/

#include <iostream>
#include <vector>
using namespace std;


struct Node {
	int parent;
	int level;
};

vector<Node> nodeList;

bool merge(int node1, int node2);
int find(int node);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int nodeCount, turnCount;
    cin >> nodeCount >> turnCount;

    nodeList = vector<Node>(nodeCount);
    for (int i = 0; i < nodeCount; i++)
    {
        nodeList[i].parent = i;
        nodeList[i].level = 1;
    }
    
    int result = 0;
    for (int turn = 1; turn <= turnCount; turn++)
    {
        int input1, input2;
        cin >> input1 >> input2;

        if (result == 0)
        {
            if (merge(input1, input2) == false)
                result = turn;
        }
            
    }

    cout << result;

    return 0;
}





bool merge(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);

    if (node1 == node2) 
        return false;

    if (nodeList[node1].level < nodeList[node2].level)
    {
        int temp = node1;
        node1 = node2;
        node2 = temp;
    }

    nodeList[node2].parent = node1;

    if (nodeList[node1].level == nodeList[node2].level)
        ++nodeList[node1].level;

    return true;
}


int find(int node)
{
    if (node == nodeList[node].parent)
        return node;
    else
        return nodeList[node].parent = find(nodeList[node].parent);
}
