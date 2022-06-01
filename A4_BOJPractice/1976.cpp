//https://www.acmicpc.net/problem/1976

/*여행 가자

여행 도시의 수와 도시 연결 경로가 주어진다.
그리고 여행 계획(여행 할 도시)가 주어질때, 여행 계획에 속한 도시들이 여행 가능한(모두 연결 되었는)지 구하여라.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int parent;
	int level;
};

vector<Node> nodeList;

void merge(int node1, int node2);
int find(int node);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cities, planCount;
    cin >> cities >> planCount;

    nodeList = vector<Node>(cities + 1, {.level = 0});
    for (int i = 1; i <= cities; i++)
    {
        nodeList[i].parent = i;
        nodeList[i].level = 0;
    }

    int input;
    for (int i = 1; i <= cities; i++)
    {
        for (int j = 1; j <= cities; j++)
        {
            cin >> input;
            if (i >= j)
                continue;
            else {
                if (input == 1)
                    merge(i, j);
            }
        }
        
    }

    bool travelAvailable = true;
    int beforeTraval, nowTraval;
    cin >> nowTraval;
    for (int i = 1; i < planCount; i++)
    {
        beforeTraval = nowTraval;
        cin >> nowTraval;

        if (find(beforeTraval) != find(nowTraval))
        {
            travelAvailable = false;
            break;
        }
    }

    if (travelAvailable)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}



void merge(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);

    if (node1 == node2) return;

    if (nodeList[node1].level < nodeList[node2].level)
        nodeList[node1].parent = node2;
    else if (nodeList[node1].level > nodeList[node2].level)
        nodeList[node2].parent = node1;
    else
    {
        nodeList[node2].parent = node1;
        ++nodeList[node1].level;
    }
}


int find(int node)
{
    if (node == nodeList[node].parent)
        return node;
    else
        return nodeList[node].parent = find(nodeList[node].parent);
}

