//https://www.acmicpc.net/problem/13317

/*한 번 남았다 (Gold 3)

Solution :
이 문제는 벨만-포드에 대하여 다루는 데, 코드를 작성하는 것이 아니라
벨만-포드가 음수 사이클을 가졌는지 여부를 판정할 때, 거리 갱신 N(노드 개수)번째에 그 여부를 판정한다.
이 때, 실수로 N-1번째에 그 여부를 판정하게 된 코드를 짰을 때, 
이에 대한 반례를 출력하면 된다.

내가 낸 답은
8 8
4 5 1
3 4 1
2 3 1
1 2 1
8 1 -1
7 8 -1
6 7 -1
5 6 -1
이다. 음수 가중치의 갱신을 최대한 늦추는 Input이다. 그러나 음수 사이클은 없으므로
결국 N-1번째에선 갱신되고 N번째 순회에선 갱신되지 않는다.

다만 문제에선 정점이 50개 이상이어야 되는데, 저런 간선 구성으로 그냥 50개로 확장하면 된다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cout << "50 50\n";

    for (int i = 25; i >= 1; i--)
        cout << i << ' ' << i + 1 << ' ' << 1 << '\n';
    
    cout << "50 1 -1\n";

    for (int i = 49; i >= 26; i--)
        cout << i << ' ' << i + 1 << ' ' << -1 << '\n';
	
	return 0;
}