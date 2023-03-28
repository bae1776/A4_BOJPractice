//https://www.acmicpc.net/problem/2252

/*줄 세우기 (Gold 3)

Solution : 위상 정렬
이 문제는 모든 학생 중 어느 두 학생에 대한 키 비교 결과만 나오고
그 비교만 충족하면 어느 것이든 답이 된다.
그러면, 학생들의 키 비교 결과에 대해 A->B 간선을 생성하는 위상 정렬을 하면 된다.
*/

#include <iostream>
#include <queue>
using namespace std;
int in[32001];
queue<int> out[32001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int studentCount, compareCount;
    cin >> studentCount >> compareCount;

    while (compareCount--)
    {
        int front, back;
        cin >> front >> back;
        in[back]++;
        out[front].push(back);
    }

    queue<int> studentQueue;
    for (int i = 1; i <= studentCount; i++)
        if (in[i] == 0)
            studentQueue.push(i);

    while (studentQueue.empty() == false)
    {
        int now = studentQueue.front();
        studentQueue.pop();

        cout << now << ' ';

        while (out[now].empty() == false)
        {
            if (--in[out[now].front()] == 0)
                studentQueue.push(out[now].front());
            out[now].pop();
        }
    }
    

	return 0;
}
