//https://www.acmicpc.net/problem/10942

/*펠린드롬?

자연수 배열(최대 2000개)가 주어지고 최대 100만개의 질의에 답하여라.
질의 : 부분 배열[S,E]는 펠린드롬인가?

펠린드롬이란 앞으로 읽어도 뒤로 읽어도 똑같은 것을 말한다.
Ex) 1 15 4 15 1

*/

#include <iostream>
#include <vector>
using namespace std;
#define YES '1'
#define NO '0'
#define UNKNOWN '?'

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrayLength;
    cin >> arrayLength;

    vector<vector<char>> pellinDP(arrayLength);
    vector<int> arr(arrayLength);
    for (int i = 0; i < arrayLength; i++)
    {
        cin >> arr[i];
        pellinDP[i] = vector<char>(i + 1, UNKNOWN);
        pellinDP[i][i] = YES;
    }
        
    int question;
    cin >> question;

    while (question--)
    {
        int start, end;
        cin >> start >> end;
        start--; end--;

        if (pellinDP[end][start] == UNKNOWN)
        {
            char flag = YES;

            for (int half = (end + start) / 2; half >= start; half--)
            {
                auto& nowPellin = pellinDP[end - (half - start)][half];
                if (flag == YES)
                {
                    if (nowPellin == UNKNOWN)
                        nowPellin = arr[half] == arr[end - (half - start)] ? YES : NO;
                    
                    if (nowPellin == NO)
                        flag = NO;
                } else
                    nowPellin = NO;
            }

            cout << flag << '\n';
        }
        else
            cout << pellinDP[end][start] << '\n';
    }


    return 0;
}
