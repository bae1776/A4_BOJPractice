//https://www.acmicpc.net/problem/4195

/*친구 네트워크

어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 
두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
친구 관계는 최대 10만이며, 영문자 이름으로 제시된다.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
	int parent;
	int level;
    int count;
    Node(int p, int l, int c) : parent(p), level(l), count(c) {};
};

vector<Node> nodeList;

void merge(int node1, int node2);
int find(int node);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int value[2];
        string name;
        unordered_map<string, int> nameMap;
        nodeList = vector<Node>();
        int index = 0;
        int relationCount; 
        cin >> relationCount;

        while (relationCount--)
        {
            for (int i = 0; i < 2; i++)
            {
                cin >> name;
                const auto& mapResult = nameMap.find(name);
                if (mapResult == nameMap.end())
                {
                    value[i] = nameMap[name] = index;
                    nodeList.emplace_back(index++, 1, 1);
                } else
                    value[i] = mapResult->second;
            }
            
            merge(value[0], value[1]);
            cout << nodeList[find(value[0])].count << '\n';

        }


    }

    return 0;
}



void merge(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);

    if (node1 == node2) return;

    if (nodeList[node1].level < nodeList[node2].level)
    {
        nodeList[node1].parent = node2;
        nodeList[node2].count += nodeList[node1].count;

    }
    else if (nodeList[node1].level > nodeList[node2].level)
    {
        nodeList[node2].parent = node1;
        nodeList[node1].count += nodeList[node2].count;
    }
    else
    {
        nodeList[node2].parent = node1;
        nodeList[node1].count += nodeList[node2].count;
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

