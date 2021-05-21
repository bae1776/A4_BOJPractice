//https://www.acmicpc.net/problem/14453

//Hoof, Paper, Scissors (Sliver)
//소들은 가위바위보와 비슷한 가위발굽보 게임을 즐긴다.
//규칙은 바위가 발굽으로 바뀌었을 뿐 그 외에는 동일하다.
//존 목장주는 베씨 소와 N번(1~100000) 가위말굽보 하고 싶다. 베씨는 이 게임을 아주 잘해서,
//존 목장주가 어떤 걸 낼지 예측할 수 있다. 그러나 베씨는 아주 게을러서 같은 걸 계속 내려고 한다.
//그래서 베씨는 모든 게임 동안 최대 한 번만 자세를 바꾼다. 예를 들어 말굽을 처음 K번 연속 내면 이후 N-K번은 가위만 낸다.
//존 목장주가 매 게임마다 무엇을 낼지 H, P, S로 모두 주어 질때, 베씨가 이길 수 있는 최대 게임 수를 구하시오.


#include <iostream>
using namespace std;
enum { START, END };
enum { HOOF, PAPER, SCISSORS };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int games;
    cin >> games;

    int (*winCount)[2][3] = new int[games][2][3];
    int winStats[3] = {0, 0, 0};

    for (int i = 0; i < games; i++)
    {
        char gesture;
        cin >> gesture;

        switch (gesture)
        {
            case 'H':
                winStats[PAPER]++; break;
            case 'P':
                winStats[SCISSORS]++; break;
            case 'S':
                winStats[HOOF]++; break;
        }

        winCount[i][END][PAPER] = winStats[PAPER];
        winCount[i][END][SCISSORS] = winStats[SCISSORS];
        winCount[i][END][HOOF] = winStats[HOOF];
    }

    winCount[0][START][PAPER] = winCount[games-1][END][PAPER];
    winCount[0][START][SCISSORS] = winCount[games-1][END][SCISSORS];
    winCount[0][START][HOOF] = winCount[games-1][END][HOOF];

    for (int i = 1; i < games; i++)
    {
        winCount[i][START][PAPER] = winStats[PAPER] - winCount[i-1][END][PAPER];
        winCount[i][START][SCISSORS] = winStats[SCISSORS] - winCount[i-1][END][SCISSORS];
        winCount[i][START][HOOF] = winStats[HOOF] - winCount[i-1][END][HOOF];
    }

    int maxWin = 0;

    for (int firstGesture = HOOF; firstGesture <= SCISSORS; firstGesture++)
        for (int secondGesture = HOOF; secondGesture <= SCISSORS; secondGesture++)
        {
            if (firstGesture == secondGesture)
            {
                maxWin = max(maxWin, winCount[0][START][firstGesture]);
                continue;
            }

            for (int changeIndex = 1; changeIndex < games; changeIndex++)
                maxWin = max(maxWin, 
                    winCount[changeIndex - 1][END][firstGesture] + 
                    winCount[changeIndex][START][secondGesture]);
        
        }

    cout << maxWin;

    delete[] winCount;

	return 0;
}
