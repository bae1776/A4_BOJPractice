//https://www.acmicpc.net/problem/1633

//�ְ��� �� �����
//����ü����ȸ�� ���� ���� �ٸ��� �ִ�. ���� �� 15��� �� 15��, �� 30������ �̷������. ��������, ���� ���� �ɷ�ġ�� ���� ���� �ɷ�ġ�� �ٸ���,
//�������� �ɷ�ġ�� ���� �ִ��� ���� ������� �� ��, �׶��� �ɷ�ġ ���� ���Ͻÿ�.
//���� ���� 30 ~ 1000����


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