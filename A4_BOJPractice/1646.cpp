//https://www.acmicpc.net/problem/1646

/*피이보나치 트리 (Gold 1)

Solution :
전위 순회한 피이보나치 트리에서
부모 노드의 번호를 N, 부모 노드를 루트로 하는 트리의 순서를 K라 하자.
왼쪽 노드의 번호는 N + 1, 왼쪽 노드의 트리 순서는 K-2이다.
오른쪽 노드의 번호는 N + fiiboCount(K - 2) + 1, 오른쪽 노드의 트리 순서는 K-1이다.
그리고 전위 순회 특성상 왼쪽 서브트리의 모든 노드의 번호는 오른쪽 서브트리의 모든 노드 번호보다 작다.
이를 응용하면 루트->시작점, 루트->도착점 까지의 경로를 쉽게 구할 수 있고,
두 경로에서 공통 조상을 제외하고 연산하면 된다.
*/

#include <iostream>
#include <list>
using namespace std;

long long fiiboCount[50] = {1, 1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int i = 2; i < 50; i++)
        fiiboCount[i] = fiiboCount[i-2] + fiiboCount[i-1] + 1;

    int treeVolume, start, end;
    cin >> treeVolume >> start >> end;

    //1(root)->start List
    list<char> toStart;
    long long nowNode = 1;
    int nowVolume = treeVolume;

    while (nowNode != start)
    {
        if (start > nowNode + fiiboCount[nowVolume - 2])
        {
            nowNode = nowNode + fiiboCount[nowVolume - 2] + 1;
            nowVolume -= 1;
            toStart.push_back('R'); 
        } else {
            nowNode += 1;
            nowVolume -= 2;
            toStart.push_back('L');
        }
    }

    //1(root)->end List
    list<char> toEnd;
    nowNode = 1;
    nowVolume = treeVolume;

    while (nowNode != end)
    {
        if (end > nowNode + fiiboCount[nowVolume - 2])
        {
            nowNode = nowNode + fiiboCount[nowVolume - 2] + 1;
            nowVolume -= 1;
            toEnd.push_back('R'); 
        } else {
            nowNode += 1;
            nowVolume -= 2;
            toEnd.push_back('L');
        }
    }

    auto startIt = toStart.begin(), endIt = toEnd.begin();
    //공통 부분 상쇄
    while (startIt != toStart.end() && endIt != toEnd.end() && *startIt == *endIt)
    {
        ++startIt;
        ++endIt;
    }

    while (startIt != toStart.end())
    {
        cout << 'U';
        ++startIt;
    }

    while (endIt != toEnd.end())
    {
        cout << *endIt;
        ++endIt;
    }

	return 0;
}
