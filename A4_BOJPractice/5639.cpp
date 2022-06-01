//https://www.acmicpc.net/problem/5639

/*이진 검색 트리

이진 검색 트리의 전위 순회가 주어질 때,
후위 순회를 구하시오.

같은 키를 가지는 노드는 없다고 가정하고 노드는 최대 1만개이다.

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> preOrder;
void postOrder(int startPos, int endPos);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    int input;
    while (cin >> input)
        preOrder.emplace_back(input); 
    

    postOrder(0, (int)(preOrder.size() - 1));
    return 0;
}


void postOrder(int startPos, int endPos)
{
    if (startPos == endPos)
    {
        cout << preOrder[startPos] << '\n';
        return;
    }

    int root = preOrder[startPos];

    int rightStart = startPos;
    while (preOrder[rightStart] <= root)
    {
        if (++rightStart > endPos)
            break;
    }
    
    if (startPos + 1 <= rightStart - 1)
        postOrder(startPos + 1, rightStart - 1);
    
    if (rightStart <= endPos)
        postOrder(rightStart, endPos);

    cout << preOrder[startPos] << '\n'; 
    
}