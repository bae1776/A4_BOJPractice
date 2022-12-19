//https://www.acmicpc.net/problem/1107

/*리모컨 (Gold 5)
100번 채널을 보다가 TV 채널을 돌리려고 하는데, 일부 숫자 버튼이 고장난 것을 알게 되었다.
리모컨에는 0~9버튼과 +, - 버튼이 있다.
고장난 버튼과, 돌리려고 하는 채널이 주어질 때(최대 50만) 버튼을 몇 번 눌러야 그 채널로 갈 수 있을지 구하시오.

채널을 무한정 있다고 가정한다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int channel, errorCount;
    cin >> channel >> errorCount;

    bool buttonError[10] = {false};
    while (errorCount--)
    {
        int errorNumber;
        cin >> errorNumber;
        buttonError[errorNumber] = true;
    }

    int result = abs(channel - 100);

    
    if (errorCount != 10)
    {
        int buttonClicked = 1;
        bool search[6] = {true, false, false, false, false, false};
        int digit[6] = {0, 0, 0, 0, 0, 0};
        for (int number = 0; number <= 999999; number++)
        {
            bool numberPressable = true;
            for (int d = 0; d < 6 && search[d]; d++)
            {
                if (buttonError[digit[d]] == true)
                {
                    numberPressable = false;
                    break;
                }
            }

            if (numberPressable) 
                result = min(result, abs(number - channel) + buttonClicked);

            digit[0]++;

            for (int i = 0; i < 5; i++)
            {
                if (digit[i] == 10)
                {
                    digit[i] = 0;
                    digit[i + 1]++;
                    if (search[i + 1] == false)
                    {
                        buttonClicked++;
                        search[i + 1] = true;
                    }
                } else
                    break;
            }
        }
    }
	

    cout << result;

	return 0;
}
