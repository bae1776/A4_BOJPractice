//https://www.acmicpc.net/problem/10996

//별 찍기 - 21
//Bronze 2
//규칙을 유추하여 별을 찍어보자. (N <= 100)

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lineCount;
    cin >> lineCount;
    
    if (lineCount == 1)
        cout << '*';
    else {
        for (int row = 0; row < lineCount * 2; row++)
        {
            for (int col = 0; col < lineCount; col++)
                if ((row + col) % 2 == 0)
                    cout << '*';
                else
                    cout << ' ';
            cout << '\n';
        }
    }

    return 0;
}

