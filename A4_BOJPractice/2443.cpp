//https://www.acmicpc.net/problem/2443

//별 찍기 - 6
//브론즈 3 레벨의 쉬운 별 찍기 문제
//라인 수가 주어질 때, 깔대기 모양으로 별을 찍으세요.
//*****
// ***
//  *

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lineCount;
    cin >> lineCount;

    for (int line = 0; line < lineCount; line++)
    {
        for (int blank = 0; blank < line; blank++)
            cout << ' ';
        for (int star = 0; star < (lineCount - line) * 2 - 1; star++)
            cout << '*';
        cout << '\n';
    }
	return 0;
}
