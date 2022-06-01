//https://www.acmicpc.net/problem/2263

/*트리의 순회

트리의 중위 순회와 후위 순회가 주어질때
전위 순회를 구하시오.  (노드 최대 10만개)

*/

#include <iostream>
#include <vector>
using namespace std;

int inOrder[100001], postOrder[100001];
int inOrderIndex[100001];

void preOrder(int inStart, int inEnd, int postStart, int postEnd);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int vertex;
    cin >> vertex;

    for (int i = 1; i <= vertex; i++)
        cin >> inOrder[i];

    for (int i = 1; i <= vertex; i++)
        cin >> postOrder[i];

    for (int i = 1; i <= vertex; i++)
        inOrderIndex[inOrder[i]] = i;


    preOrder(1, vertex, 1, vertex);

    return 0;
}


void preOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    cout << postOrder[postEnd] << ' ';

    if (inStart == inEnd)
        return;

    const int inOrder_rootIndex = inOrderIndex[postOrder[postEnd]];

    //left
    if (inOrder_rootIndex != inStart)
        preOrder(inStart, inOrder_rootIndex - 1, postStart, postStart + (inOrder_rootIndex - inStart - 1));

    //right
    if (inOrder_rootIndex != inEnd)
        preOrder(inOrder_rootIndex + 1, inEnd, postStart + (inOrder_rootIndex - inStart), postEnd - 1);
}