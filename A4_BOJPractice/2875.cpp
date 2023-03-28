//https://www.acmicpc.net/problem/2875

/*대회 or 인턴 (Bronze 3)
Solution : 수학
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int woman, man, intern;
	cin >> woman >> man >> intern;

	//최대 팀 개수
	int maxTeamCount = min(woman / 2, man);

	//팀을 이루지 못하고 남은 인원
	int rest = woman - maxTeamCount * 2 + man - maxTeamCount;
	
	//남은 인원을 인턴에 데려갈 때, 더 인턴으로 데려가야할 인원 수
	int lack = intern - rest;

	if (lack <= 0)
		cout << maxTeamCount;
	else
		cout << (maxTeamCount * 3 - lack) / 3;
		
	return 0;
}
