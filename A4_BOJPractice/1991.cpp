//https://www.acmicpc.net/problem/1991

/*트리 순회

최대 26개의 노드를 가진 이진 트리에 대하여
전위 순회, 중위 순회, 후위 순회 결과를 출력하세요.

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int left;
    int right;
};

Node tree[26];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int vertex;
    cin >> vertex;
    cin.ignore();

    char input[10];
    for (int i = 0; i < vertex; i++)
    {
        cin.getline(input, 9);

        int index = input[0] - 'A';

        tree[index].left = (input[2] == '.') ? -1 : input[2] - 'A';
        tree[index].right = (input[4] == '.') ? -1 : input[4] - 'A';
    }


    //preorder
    stack<int> preOrder;
    preOrder.emplace(0);

    while (preOrder.empty() == false)
    {
        int nodeNumber = preOrder.top();
        cout << (char)('A' + nodeNumber);
        preOrder.pop();

        if (tree[nodeNumber].right != -1)
            preOrder.emplace(tree[nodeNumber].right);
        
        if (tree[nodeNumber].left != -1)
            preOrder.emplace(tree[nodeNumber].left);

        
    }
    cout << '\n';

    //inOrder
    stack<int> inOrder;
    int nodeNumber = 0;

    while (true)
    {
        while (nodeNumber != -1)
        {
            inOrder.emplace(nodeNumber);
            nodeNumber = tree[nodeNumber].left;
        }

        if (inOrder.empty())
            break;
        
        nodeNumber = inOrder.top();
        cout << (char)('A' + nodeNumber);
        inOrder.pop();
        
        nodeNumber = tree[nodeNumber].right;
    }
    cout << '\n';


    //postOrder
    stack<int> postOrder, resultStack;
    postOrder.emplace(0);

    while (postOrder.empty() == false)
    {
        nodeNumber = postOrder.top();
        postOrder.pop();

        if (tree[nodeNumber].left != -1)
            postOrder.emplace(tree[nodeNumber].left);

        if (tree[nodeNumber].right != -1)
            postOrder.emplace(tree[nodeNumber].right);
        
        resultStack.emplace(nodeNumber);
    }

    while (resultStack.empty() == false)
    {
        cout << (char)('A'+ resultStack.top());
        resultStack.pop();
    }
    cout << '\n';


    return 0;
}