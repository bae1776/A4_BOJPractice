//https://www.acmicpc.net/problem/2579

//계단 오르기
//지면으로부터 시작해서 도착 지점까지 계단을 한 칸 또는 두 칸씩 올라간다.
//단, 계단을 3개 연속으로 밟을 수는 없다.
//이 때, 도착 지점까지 최대 점수를 얻었을 때의 점수를 구하여라.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;



int MAX(int& a, int& b)
{
	return a > b ? a : b;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int stairHeight;
	cin >> stairHeight;

	vector<int> stairScore;
	vector<pair<int, int>> totalScore; //<1 step before, 2 steps before>.

	stairScore.reserve(stairHeight + 1);
	totalScore.reserve(stairHeight + 1);

	stairScore.emplace_back(0);
	totalScore.emplace_back(0, 0);

	for (int i = 1; i <= stairHeight; i++)
	{
		int score;
		cin >> score;
		stairScore.emplace_back(score);
	}

	totalScore.emplace_back(stairScore[1], stairScore[1]);



	for (int i = 2; i <= stairHeight; i++)
	{
		pair<int, int> DPScore;
		DPScore.first = totalScore[i - 1].second + stairScore[i];
		DPScore.second = MAX(totalScore[i - 2].first, totalScore[i - 2].second) + stairScore[i];
		totalScore.emplace_back(DPScore);
	}


	cout << MAX(totalScore[stairHeight].first, totalScore[stairHeight].second);



	return 0;
}