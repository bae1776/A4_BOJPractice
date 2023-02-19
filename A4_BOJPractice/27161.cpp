//https://www.acmicpc.net/problem/999 (문제 번호)

/*크레이지 타임

모래 시계가 있으면 역행
동기화가 되면 책상치기
동시에 만족하면 아무일도 일어나지않음
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cardCount;
    cin >> cardCount;

    char clock[10];
    int nowTime = 1, cardTime;
    bool timeReverse = false;
    while (cardCount--)
    {
        cin >> clock >> cardTime;

        bool timeSync = (cardTime == nowTime);
        bool reversing = (clock[0] == 'H');

        if (timeSync ^ reversing)
        {
            if (timeSync)
                cout << nowTime << " YES\n";
            else
            {
                cout << nowTime << " NO\n";
                timeReverse = !timeReverse;
            }
        } else {
            cout << nowTime << " NO\n";
        }

        if (timeReverse)
            nowTime--;
        else
            nowTime++;

        if (nowTime == 13)
            nowTime = 1;
        
        if (nowTime == 0)
            nowTime = 12;
    }

	
	return 0;
}
