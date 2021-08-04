//https://www.acmicpc.net/problem/20120

/*호반우와 리듬게임

다음 규칙을 따르는 리듬 게임에서, 노트의 점수 리스트가 최대 1000개 주어질 때,
얻을 수 있는 최대 점수를 구하세요.

1. 각 노트는 점수가 정수로 매겨져 있는데, 점수가 음수일 수도 있다.
2. 연속으로 처리한 노트의 개수를 콤보라고 할 때, 노트 하나를 칠 때마다 (누적 콤보) * (현재 노트) 만큼 점수가 추가된다.
3. 연속 3개의 노트를 놓치면 얻은 점수가 0점이 되고 더 이상 점수를 얻을 수 없다.
4. 주어진 노트는 모두 순서대로 처리해야 한다.
*/

#include <iostream>
#include <vector>
using namespace std;
using vector2D = vector<vector<long long>>;
#define IMPOSSIBLE -9272036854775808LL

vector2D missDP;  //[NoteOrder][miss]
vector2D comboDP; //[NoteOrder][combo]
long long score[1001];



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int noteCount;
    cin >> noteCount;

    missDP = vector2D(noteCount + 1);
    comboDP = vector2D(noteCount + 1);

    for (int i = 1; i <= noteCount; i++)
    {
        cin >> score[i];

        missDP[i] = vector<long long>(min(3, i + 1), IMPOSSIBLE);
        comboDP[i] = vector<long long>(i + 1, IMPOSSIBLE);
    }

    missDP[1][1] = 0;
    comboDP[1][1] = score[1];

    for (int noteNumber = 2; noteNumber <= noteCount; noteNumber++)
    {
        //1. First missed Case
        long long missFirstMax = IMPOSSIBLE;
        for (size_t combo = 1; combo < comboDP[noteNumber - 1].size(); combo++)
            missFirstMax = max(missFirstMax, comboDP[noteNumber - 1][combo]);

        missDP[noteNumber][1] = missFirstMax;

        //2. Second missed Case
        missDP[noteNumber][2] = missDP[noteNumber - 1][1];

        //3. note Cleared after Miss Case
        comboDP[noteNumber][1] = 
            max(missDP[noteNumber - 1][1], missDP[noteNumber - 1][2]) + score[noteNumber];

        //4. series Combo Case
        for (size_t combo = 2; combo < comboDP[noteNumber].size(); combo++)
            comboDP[noteNumber][combo] = comboDP[noteNumber-1][combo-1] + score[noteNumber] * (long long)combo;
    }

    long long result = max(missDP[noteCount][1], missDP[noteCount][2]);
    for (int combo = 1; combo <= noteCount; combo++)
        result = max(result, comboDP[noteCount][combo]);

    cout << max(result, 0LL);

    return 0;
}