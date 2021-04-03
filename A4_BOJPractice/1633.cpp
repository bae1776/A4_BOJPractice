//https://www.acmicpc.net/problem/1633

//최고의 팀 만들기
//세계체스대회에 나갈 팀을 꾸리고 있다. 팀은 흑 15명과 백 15명, 총 30명으로 이루어진다. 팀원마다, 흑일 때의 능력치와 백일 때의 능력치가 다른데,
//팀원들의 능력치의 합이 최대인 팀을 만들려고 할 때, 그때의 능력치 값을 구하시오.
//팀원 수는 30 ~ 1000명임


#include <iostream>
#include <utility>
#include <cstring>
#define UNKNOWN -1
using namespace std;

pair<int, int> playerStat[1001];
int DP[1001][16][16];


int bestTeam(int white, int black, int counted_player);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP, UNKNOWN, sizeof(DP));

	int playerCount = 0;

	while (!cin.eof())
	{
		playerCount++;
		cin >> playerStat[playerCount].first >> playerStat[playerCount].second;
	}

	cout << bestTeam(15, 15, playerCount);

	return 0;
}


int bestTeam(int white, int black, int counted_player)
{
	int& memorized = DP[counted_player][white][black];

	if (memorized != UNKNOWN)
		return memorized;

	if (counted_player == 0)
		return memorized = 0;

	int temp; 
	if (white > 0 &&
		(temp = bestTeam(white - 1, black, counted_player - 1) + playerStat[counted_player].first) > memorized) //white Add
		memorized = temp;

	if (black > 0 &&
		(temp = bestTeam(white, black - 1, counted_player - 1) + playerStat[counted_player].second) > memorized) //black Add
		memorized = temp;

	if ((temp = bestTeam(white, black, counted_player - 1)) > memorized) // non Add
		memorized = temp;

	return memorized;
}