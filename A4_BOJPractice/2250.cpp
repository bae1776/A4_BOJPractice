//https://www.acmicpc.net/problem/2250

/* 트리의 높이와 너비 (Gold 2)

이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다. 이때 다음의 규칙에 따라 그리려고 한다.
1. 이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
2. 한 열에는 한 노드만 존재한다.
3. 임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 
               오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
4. 노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.

이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 
그 레벨에 할당된 노드 중 가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의한다. 
트리의 레벨은 가장 위쪽에 있는 루트 노드가 1이고 아래로 1씩 증가한다.

우리는 주어진 이진트리를 위의 규칙에 따라 그릴 때에 너비가 가장 넓은 레벨과 그 레벨의 너비를 계산하세요.
(노드는 최대 1만개)

Solution : 
적절한 트리 탐색을 통한 빡구현
*/

#include <iostream>
using namespace std;

struct Node {
	int parent;
	char ofParent;
	int value;
	int left, right;
	int leftCount, rightCount;
};

int nodeCount;
Node tree[10001];
int maxValue[10002], minValue[10002];


int countLR(Node& node);
void levelOrder(Node& node, int level);
int findLeftest(Node& node, const int& level);
int findRightest(Node& node, const int& level);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeCount;

	for (int i = 0; i < nodeCount; i++)
	{
		int nodeNumber, left, right;
		cin >> nodeNumber >> left >> right;

		tree[nodeNumber].left = left;
		tree[nodeNumber].right = right;

		if (left != -1)
		{
			tree[left].parent = nodeNumber;
			tree[left].ofParent = 'L';
		}

		if (right != -1)
		{
			tree[right].parent = nodeNumber;
			tree[right].ofParent = 'R';
		}
	}

	int parent = 0;
	for (int i = 1; i <= nodeCount; i++)
	{
		if (tree[i].parent == 0)
		{
			parent = i;
			break;
		}
	}

	countLR(tree[parent]);
	levelOrder(tree[parent], 1);

	int maxWidthLevel = 0, maxWidth = 0;
	for (int level = 1; minValue[level] != 0; level++)
	{	
		int width = maxValue[level] - minValue[level] + 1;

		if (width > maxWidth)
		{
			maxWidthLevel = level;
			maxWidth = width;
		}
	}

	cout << maxWidthLevel << ' ' << maxWidth;

	

	
	return 0;
}



int countLR(Node& node)
{
	if (node.left != -1)
		node.leftCount = countLR(tree[node.left]);
	
	if (node.right != -1)
		node.rightCount = countLR(tree[node.right]);

	return node.leftCount + node.rightCount + 1;
}


void levelOrder(Node& node, int level)
{
	if (node.parent == 0)
	{//root Node Case;
		node.value = node.leftCount + 1;
	} else {
		int& parentValue = tree[node.parent].value;

		if (node.ofParent == 'L')
			node.value = parentValue - node.rightCount - 1;
		if (node.ofParent == 'R')
			node.value = parentValue + node.leftCount + 1;
	}

	if (minValue[level] == 0)
		minValue[level] = maxValue[level] = node.value;
	else
	{
		minValue[level] = min(minValue[level], node.value);
		maxValue[level] = max(maxValue[level], node.value);
	}


	if (node.left != -1)
		levelOrder(tree[node.left], level + 1);
	
	if (node.right != -1)
		levelOrder(tree[node.right], level + 1);
}

