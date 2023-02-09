//https://www.acmicpc.net/problem/1417

/* 국회의원 선거 (Silver 5)

다솜이는 사람의 마음을 읽을 수 있는 기계가 있어, 선거를 조작하려 한다.
현재 형택구에 나온 국회의원 후보는 N명, 유권자 수는 M명으로, 
이 기계를 이용해 자신을 찍지 않을 사람을 매수하여 당선되는 것이 목표이다.
다솜이는 기호 1번이다.

예를 들어, 1, 2, 3번 후보를 찍으려는 사람이 5, 7, 7명이면,
2번 후보, 3번 후보 유권자 1명씩을 매수하면 된다.

다솜이가 매수해야 하는 사람의 최솟값을 구하시오.
(N <= 50, 각 후보의 득표 수 100 이하)

Solution : 브루트포스
*/

#include <iostream>
#include <algorithm>
using namespace std;

int voteList[51];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int people;
    cin >> people;

    for (int i = 0; i < people; i++)
        cin >> voteList[i];

    sort(voteList + 1, voteList + people);

    if (people == 1)
    {
        cout << 0;
        return 0;
    }

    int bribe = 0;

    while (voteList[0] <= voteList[people - 1])
    {
        int* nextBuy = lower_bound(voteList + 1, voteList + people, voteList[people - 1]);
        *nextBuy -= 1;
        voteList[0]++;
        bribe++;
    }

    cout << bribe;

    return 0;
}

