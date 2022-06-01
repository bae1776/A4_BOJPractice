//https://www.acmicpc.net/problem/1476

/*날짜 계산
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int earth, sun, moon;
    cin >> earth >> sun >> moon;

    for (int candidateDay = sun; ;candidateDay += 28)
    {
        if ((candidateDay - 1) % 15 + 1 == earth
         && (candidateDay - 1) % 19 + 1 == moon )
        {
            cout << candidateDay;
            break;
        }
    }

    
	return 0;
}