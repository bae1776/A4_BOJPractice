//https://www.acmicpc.net/problem/13015

//별 찍기 - 23
//Silver 5
//규칙을 유추하여 별을 찍어보자. (2 <= N <= 100)

#include <iostream>
#include <vector>
#define MAXSIZE 100
using namespace std;
enum {LEFT, DOWN, RIGHT, UP} DIRECTION;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lineCount;
    cin >> lineCount;
    
    for (int row = 1; row < lineCount * 2; row++)
    {
        int realRow = row > lineCount ? lineCount * 2 - row : row;

        if (realRow == 1)
        {
            for (int i = 0; i < lineCount; i++)
                cout << '*';
            for (int i = 0; i < (lineCount - realRow) * 2 - 1; i++)
                cout << ' ';
            for (int i = 0; i < lineCount; i++)
                cout << '*';
        } 
        else if (realRow == lineCount) 
        {
            for (int i = 1; i < realRow; i++)
                cout << ' ';
            cout << '*';
            for (int i = 0; i < lineCount - 2; i++)
                cout << ' ';
            cout << '*';
            for (int i = 0; i < lineCount - 2; i++)
                cout << ' ';
            cout << '*'; 
        }
        else
        {
            for (int i = 1; i < realRow; i++)
                cout << ' ';
            cout << '*';
            for (int i = 0; i < lineCount - 2; i++)
                cout << ' ';
            cout << '*';
            for (int i = 0; i < (lineCount - realRow) * 2 - 1; i++)
                cout << ' ';
            cout << '*';
            for (int i = 0; i < lineCount - 2; i++)
                cout << ' ';
            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}

