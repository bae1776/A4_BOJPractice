//https://www.acmicpc.net/problem/6597

/*트리 복구 (Gold 4)

Solution : 재귀, 분할정복
프리오더, 인오더로 트리를 복구한 뒤에 포스트 오더로 출력하는 문제
재귀 함수를 잘 구현하면 쉽게 할 수 있을 것이다.
*/


#include <iostream>
#include <string>
using namespace std;

string preOrder, inOrder;
void postOrder(int preStart, int preEnd, int inStart, int inEnd);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    while (cin >> preOrder >> inOrder)
    {
        postOrder(0, preOrder.size() - 1, 0, inOrder.size() - 1);
        cout << '\n';
    }

	return 0;
}


void postOrder(int preStart, int preEnd, int inStart, int inEnd)
{
    char root = preOrder[preStart];
    if (preStart != preEnd)
    {
        int leftSize = inOrder.find(root) - inStart;

        if (leftSize != 0)
            postOrder(preStart + 1, preStart + leftSize, inStart, inStart + leftSize - 1);

        if (preStart + leftSize < preEnd)
            postOrder(preStart + leftSize + 1, preEnd, inStart + leftSize + 1, inEnd);
    }

    cout << root;
}
