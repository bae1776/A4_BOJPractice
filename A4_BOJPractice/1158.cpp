//https://www.acmicpc.net/problem/1158

//요세푸스 문제
//1 ~ 5000의 정수 N, K에 대하여
//N명의 사람이 원형 테이블에 앉아있고, 1번 사람부터 K번째 사람을 제거하고,
//남은 사람들 중에서 다시 K번째 사람을 제거한다. 그리고 이 과정을 반복한다.
//요세푸스 순열은 이 과정을 반복했을 때, 원에서 제거되는 사람의 순서 명단이다.
//이 요세푸스 순열을 출력하여라.


#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int people, order;
    cin >> people >> order;

    queue<int> table, result;

    for (int i = 1; i <= people; i++)
        table.push(i);

    while (table.empty() == false)
    {
        for (int i = 1; i < order; i++)
        {
            int temp = table.front();
            table.pop();
            table.push(temp);
        }

        result.push(table.front());
        table.pop();
    }

    cout << '<';
    while (result.size() > 1)
    {
        cout << result.front() << ", ";
        result.pop();
    }
    cout << result.front() << '>';

	return 0;
}
