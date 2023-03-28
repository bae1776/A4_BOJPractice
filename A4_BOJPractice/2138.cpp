//https://www.acmicpc.net/problem/2138

/*전구와 스위치 (Gold 3)

Solution : 그리디한 완전 탐색

0000000000 에서 1010101010 을 만든다고 하자.
같은 스위치를 2번 누르는 것은 다시 원 상태로 돌아가는 것이므로 절대 최적이 될 수 없고,
각 스위치를 오름차순으로 누를건가? 누르지 않을 건가? 로만 판단한다.
1번 전구는 1, 2번 스위치에 의해 결정된다. 
여기서 1, 2번 스위치는 1번 전구의 현재와 목표가 다르면 둘 중 1번, 같으면 0번 혹은 2번 누른다
2번 전구는 1, 2, 3번 스위치에 의해 결정된다.
여기서 3번 스위치는 앞에서 1, 2번 스위치의 결정 결과에 의존한다. 
(2번 전구가 현재 목표와 다르다면 무조건 눌러야 되고, 같다면 절대 누를 수 없다.) 
3번 전구는 2, 3, 4번 스위치에 의해 결정된다.
이렇게 마지막 스위치의 누름 여부까지 앞의 결과에 의존적으로 결정된다.
모든 스위치를 조작했을 때, 마지막 전구가 결과와 일치하면 유효, 다르면 모순이 된다.
그러므로 이 문제의 경우의 수는 (1, 2번 스위치의 누름 여부) 2가지 밖에 없다.
*/

#include <iostream>
#include <cstring>
using namespace std;

char start[100004], target[2][100004];
int push[2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int len;
    cin >> len;
    cin >> start;
    cin >> target[0];
    strncpy(target[1], target[0], len);

    if (start[0] == target[0][0])
	{
        //target[0] : <stay, stay ... >
        //target[1] : <push, push ... > : 3번째 전구만 바뀜 
        target[1][2] = '1' - target[1][2] + '0';
        push[1] = 2;
    } else {
        //target[0] : <stay, push ... >
        target[0][0] = '1' - target[0][0] + '0';
        target[0][1] = '1' - target[0][1] + '0';
        target[0][2] = '1' - target[0][2] + '0';

        //target[1] : <push, stay ... >
        target[1][0] = '1' - target[1][0] + '0';
        target[1][1] = '1' - target[1][1] + '0';

        push[0] = push[1] = 1;
    }

    for (int switchNumber = 2; switchNumber < len; switchNumber++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (start[switchNumber - 1] != target[i][switchNumber - 1])
            {
                target[i][switchNumber - 1] = '1' - target[i][switchNumber - 1] + '0';
                target[i][switchNumber] = '1' - target[i][switchNumber] + '0';
                target[i][switchNumber + 1] = '1' - target[i][switchNumber + 1] + '0';
                push[i]++;
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        if (start[len - 1] != target[i][len - 1])
            push[i] = 0x7FFFFF;
    }

    int answer = min(push[0], push[1]);

    if (answer == 0x7FFFFF)
        cout << -1;
    else
        cout << answer;


	return 0;
}
