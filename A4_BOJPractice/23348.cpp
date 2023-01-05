//https://www.acmicpc.net/problem/23348

/*스트릿 코딩 파이터 (Bronze 3)

3인 1조로 구성된 동아리들이 모여 코딩 대회를 하는데,
멋있게 문제를 푸는 사람들이 점수를 많이 받는다.
공식적인 기술은 '한손 코딩', '노룩 코딩', '폰코딩' 3가지가 있다.

점수 산정 방식은 다음 예와 같다.
위 3개 기술의 난이도가 각각 3, 6, 9이고 플레이어 P가 위 기술을 각각 1, 2, 3번 보여준 경우
P의 점수 = 42 = (3 * 1) + (6 * 2) + (9 * 3) 이다.
그리고 동아리 점수는 세 플레이어의 점수 합이다.

가장 높은 점수를 받은 동아리의 점수는 몇 점인지 구하세요.
동아리의 수는 최대 1000개, 난이도는 최대 1000, 각 동아리원이 사용한 각 기술의 횟수는 100회 이하이다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int maxScore = 0, teamCount;
	int score[3];

	for (int i = 0; i < 3; i++)
		cin >> score[i];

	cin >> teamCount;

	for (int i = 0; i < teamCount; i++)
	{
		int teamScore = 0;
		for (int j = 0; j < 3; j++)
		{
			int count[3];
			cin >> count[0] >> count[1] >> count[2];
			teamScore += count[0] * score[0] + count[1] * score[1] + count[2] * score[2];
		}
		maxScore = max(maxScore, teamScore);
	}

	cout << maxScore;
	
	return 0;
}