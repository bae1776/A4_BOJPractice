//https://www.acmicpc.net/problem/20041

/* Escaping (Platinum 5)

격자 평면에서 1명의 도둑이 도주 중이다. 그를 쫓는 경찰은 N(~500000)명이다.
먼저 도둑이 한 칸 움직인다. 그 다음 경찰도 한 칸 움직인다.
이때, 도둑은 반드시 움직여야 하지만 경찰은 가만히 있을 수 있다.
경찰과 도둑이 같은 칸에서 만나면 잡히게 된다. 
도둑과 경찰 배치가 주어질 때, 무한히 도망갈 수 있을 지 구하시오. 좌표 범위는 아주 크다.

Solution : 
경찰 수가 아주 많기 때문에 시뮬레이션은 불가하며, 
좌표 위치 차를 이용한 그리디 한 접근이 필요하다.
도둑을 중심으로 공간을 X자, 즉 직각삼각형 모양으로 4분할하는 것이 핵심
*/

#include <iostream>
using namespace std;

pair<long long, long long> police[500001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int policeCount;
    cin >> policeCount;

    for (int i = 0; i < policeCount; i++)
        cin >> police[i].first >> police[i].second;

    int dir[4] = {0,};
    long long tx, ty;
    cin >> tx >> ty;

    for (int i = 0; i < policeCount; i++)
    {
        long long ascVal = tx + police[i].second - police[i].first;
        long long descVal = -tx + police[i].first + police[i].second;

        if (ascVal >= ty && descVal >= ty)
            dir[0] = 1;
        
        if (ascVal <= ty && descVal >= ty)
            dir[1] = 1;
        
        if (ascVal >= ty && descVal <= ty)
            dir[2] = 1;
        
        if (ascVal <= ty && descVal <= ty)
            dir[3] = 1;
    }

    if (dir[0] + dir[1] + dir[2] + dir[3] == 4)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
