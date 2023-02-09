//https://www.acmicpc.net/problem/4307

/*개미 (Silver 1)

Solution :
개미가 10만 마리나 되고, 각각의 개미에 대해 왼쪽, 오른쪽 출발방향을 고르는 문제이므로,
완전 탐색으로는 절대 풀 수 없다. 대신 약간의 아이디어를 이용한다.

개미가 부딪히는 것을 그냥 서로 지나쳐 지나가는 것과 동치로 생각하면 쉬워진다.
위와 같이 생각하면 개미가 아무리 많이 이동들 막대 길이를 넘을 수 없음을 알게 된다.
개미가 양쪽 끝 거의 근처에 부딪힌다면, 훨씬 많이 이동할 수도 있을탠데 말이다.
그러나 예시를 그려보며 깊게 생각해보면, 서로 지나쳐 지나가도 개미의 움직임은 완전히 동일하다.

위 아이디어를 이용하면 아주 쉽게 O(개미 수)로 처리할 수 있다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int stick, ant;
        cin >> stick >> ant;

        int shortest = 0, longest = 0;
        int antLoc;
        
        for (int i = 0; i < ant; i++)
        {
            cin >> antLoc;

            shortest = max(shortest, min(stick - antLoc, antLoc));
            longest = max(longest, max(stick - antLoc, antLoc));
            
        }

        cout << shortest << ' ' << longest << '\n';
    }
	
	return 0;
}
