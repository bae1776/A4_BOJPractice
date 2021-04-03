//https://www.acmicpc.net/problem/15997

//승부 예측
//월드컵 32강은 4팀 리그제로 구성된다.
//4팀 중 2팀이 붙었을 때, 승리, 무승부, 패배확률이 주어질 때, 각 팀이 2위 안에 들 확률을 구하시오. (승점이 동률일 경우 공평한 추첨으로 진행)
//승리 시 승점 3점, 무승부 시 서로 승점 1점 부여된다.

#include <vector>
#include <iostream>
#include <string>
using namespace std;

int getTeamNumber(string teamName[], string& team);
bool getNextCase(int matchResult[]);
vector<double> getWinLeagueRate(int teamPoint[]);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const int TEAM = 4;
	string teamName[TEAM];
	for (int i = 0; i < TEAM; i++)
		cin >> teamName[i];

	double matchRate[4][4][3] = {0.0,};
	
	for (int i = 0; i < 6; i++)
	{
		string team1, team2;
		cin >> team1 >> team2;
		int team1Idx = getTeamNumber(teamName, team1);
		int team2Idx = getTeamNumber(teamName, team2);

		double win, draw, lose;
		cin >> win >> draw >> lose;
		if (team1Idx < team2Idx)
		{
			matchRate[team1Idx][team2Idx][0] = win;
			matchRate[team1Idx][team2Idx][1] = draw;
			matchRate[team1Idx][team2Idx][2] = lose;
		}
		else {
			matchRate[team2Idx][team1Idx][0] = lose;
			matchRate[team2Idx][team1Idx][1] = draw;
			matchRate[team2Idx][team1Idx][2] = win;
		}	
	}

	int matchResult[6] = { 0, };
	double leagueWinRate[4] = { 0.0, };

	do {
		int teamPoint[4] = { 0, };
		double caseProb = 1.0;
		int matchResultIndex = 0;
		for (int matchTeam1 = 0; matchTeam1 < 4; matchTeam1++)
			for (int matchTeam2 = matchTeam1 + 1; matchTeam2 < 4; matchTeam2++)
			{
				switch (matchResult[matchResultIndex])
				{
				case 0:
					caseProb *= matchRate[matchTeam1][matchTeam2][0];
					teamPoint[matchTeam1] += 3;
					break;
				case 1:
					caseProb *= matchRate[matchTeam1][matchTeam2][1];
					teamPoint[matchTeam1]++;
					teamPoint[matchTeam2]++;
					break;
				case 2:
					caseProb *= matchRate[matchTeam1][matchTeam2][2];
					teamPoint[matchTeam2] += 3;
				}
				matchResultIndex++;
			}

		vector<double> winLeagueRate = getWinLeagueRate(teamPoint);

		for (int i = 0; i < 4; i++)
		{
			leagueWinRate[i] += winLeagueRate[i] * caseProb;
		}
		
	} while (getNextCase(matchResult));
	

	for (double winRate : leagueWinRate)
	{
		cout << winRate << '\n';
	}
	
	return 0;
}

int getTeamNumber(string teamName[], string& team)
{
	for (int i = 0; i < 4; i++)
		if (teamName[i].compare(team) == 0)
			return i;
};

bool getNextCase(int matchResult[])
{
	if (matchResult[5] != 2)
	{
		matchResult[5]++;
		return true;
	}
	else {
		for (int i = 4; i >= 0; i--)
		{
			if (matchResult[i] != 2)
			{
				matchResult[i]++;
				for (int j = i + 1; j < 6; j++)
					matchResult[j] = 0;
				return true;
			}
		}
		return false;
	}
	
}


vector<double> getWinLeagueRate(int teamPoint[])
{
	vector<double> winLeagueRate(4);

	int passLeft = 2;
	for (int score = 12; score >= 0; score--)
	{
		if (passLeft <= 0)
			break;
		vector<int> coScoreTeamList;
		for (int i = 0; i < 4; i++)
		{
			if (teamPoint[i] == score)
				coScoreTeamList.push_back(i);
		}

		if (coScoreTeamList.empty())
			continue;
		else if (coScoreTeamList.size() == 1)
		{
			
			winLeagueRate[coScoreTeamList.at(0)] = 1.0;
		}
		else {
			for (int coTeam : coScoreTeamList)
				winLeagueRate[coTeam] = (double)passLeft / (double)coScoreTeamList.size();
		}
		passLeft -= coScoreTeamList.size();

	}

	return winLeagueRate;
}
