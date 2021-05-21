//https://www.acmicpc.net/problem/10990

//별 찍기 - 15
//Bronze 3
//아주 조금 어려운 별 찍기. (line = 3)
//  *
// * *
//*   *

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lineCount;
    cin >> lineCount;

    for (int firstBlank = 0; firstBlank < lineCount - 1; firstBlank++)
        cout << ' ';
    cout << "*\n";

    for (int line = 2; line <= lineCount; line++)
    {
        for (int leftBlank = 0; leftBlank < lineCount - line; leftBlank++)
            cout << ' ';
        cout << '*';
        for (int midBlank = 0; midBlank < line * 2 - 3; midBlank++)
            cout << ' ';
        cout << "*\n";
    }
    
    return 0;
}
