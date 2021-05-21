//https://www.acmicpc.net/problem/10994

//별 찍기 - 19
//Silver 4
//규칙을 유추하여 별을 찍어보자. (N <= 100)
//N = 2 예시
//*****
//*   *
//* * *
//*   *
//*****

#include <iostream>
using namespace std;

void function(int depth, int line);
int lineCount;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    
    cin >> lineCount;
    function(lineCount, 0);
    
    
    return 0;
}

void function(int depth, int line)
{
    int size = 4 * depth - 3;
    if (line >= depth * 2)
    {
        function(depth, size - line + 1);
        return;
    }

    if (line == 0)
    {
        for (int i = 1; i <= size; i++)
        {
            function(depth, i);
            cout << '\n';
        }
    } else {
        if (line == 1)
            for (int i = 0; i < size; i++)
                cout << '*';
        else if (line == 2)
        {
            cout << '*';
            for (int i = 0; i < size - 2; i++)
                cout << ' ';
            cout << '*';
        } else {
            cout << "* ";
            function(depth - 1, line - 2);
            cout << " *";
        }

    }
}
