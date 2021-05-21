//https://www.acmicpc.net/problem/20120

/*호반우와 리듬게임
* 대회 링크 : https://www.acmicpc.net/category/detail/2335
*/

#include <iostream>
#include <vector>
using namespace std;

long long scoreFunc(vector<int>& noteScore, int index, int combo, int missCont);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int noteCount;
	cin >> noteCount;

	vector<int> noteScore(noteCount);
	for (int i = 0; i < noteCount; i++)
		cin >> noteScore[i];


	long long maxScore = scoreFunc(noteScore, 0, 0, 0);

	return 0;
}



long long scoreFunc(vector<int>& noteScore, int index, int combo, int missCont)
{
	long long totalScore = 0;

	while (true)
	{
		if (index + 1 == noteScore.size())
			return totalScore;

		if (noteScore[index] >= 0)
		{
			combo += 1;
			totalScore += combo * noteScore[index];
		}
		else {
			long long maxScore_miss = scoreFunc(noteScore, index + 1, 0, missCont + 1);
			long long maxScore_get = scoreFunc(noteScore, index + 1, combo + 1, 0) + (combo + 1) * noteScore[index];

			totalScore += maxScore_miss > maxScore_get ? maxScore_miss : maxScore_get;
		}
	}
}
