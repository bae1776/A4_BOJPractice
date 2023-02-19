//https://www.acmicpc.net/problem/27162

/*야추 주사위 게임

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    char input[20];
    cin >> input;

    vector<int> dice(5);
    cin >> dice[0] >> dice[1] >> dice[2];

    int score = 0;
    for (dice[3] = 1; dice[3] <= 6; dice[3]++)
        for (dice[4] = 1; dice[4] <= 6; dice[4]++)
        {
            for (int i = 0; i < 6; i++)
                if (input[i] == 'Y')
                {
                    int numberScore = 0;
                    for (const auto& d : dice)
                        if (d == i + 1)
                            numberScore += i + 1;

                    score = max(score, numberScore);
                }

            int diceIndex[7] = {0};
            for (const auto& d : dice)
                diceIndex[d]++;

            //Four of a Kind
            if (input[6] == 'Y')
            {

                for (int i = 1; i <= 6; i++)
                    if (diceIndex[i] == 4)
                        score = max(score, i * 4);
            }

            //Full House
            if (input[7] == 'Y')
            {

                for (int i = 1; i <= 6; i++)
                    for (int j = 1; j <= 6; j++)
                        if (diceIndex[i] == 3 && diceIndex[j] == 2)
                            score = max(score, i * 3 + j * 2);
            }

            auto copyDice = dice;
            sort(copyDice.begin(), copyDice.end());
            //Little Straight
            if (input[8] == 'Y')
            {
                if (copyDice[0] == 1 && copyDice[1] == 2 && copyDice[2] == 3 && copyDice[3] == 4 && copyDice[4] == 5)
                    score = max(score, 30);
            }

            //Big Straight
            if (input[9] == 'Y')
            {
                if (copyDice[0] == 2 && copyDice[1] == 3 && copyDice[2] == 4 && copyDice[3] == 5 && copyDice[4] == 6)
                    score = max(score, 30);
            }

            //Yacht
            if (input[10] == 'Y')
            {
                for (int i = 1; i <= 6; i++)
                    if (diceIndex[i] == 5)
                        score = max(score, 50);
            }

            //Choice
            if (input[11] == 'Y')
            {
                int choiceScore = 0;
                for (const auto& d : dice)
                    choiceScore += d;
                score = max(score, choiceScore);
            }


        }




    cout << score;
	
	return 0;
}
