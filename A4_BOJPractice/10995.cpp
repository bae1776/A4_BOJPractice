//https://www.acmicpc.net/problem/10995

//별 찍기 - 20
//Bronze 2
//규칙을 유추하여 별을 찍어보자. (N <= 100)
//
//N = 1     N = 2       N = 3
//*         * *         * * *
//           * *         * * *
//                      * * *

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lineCount;
    cin >> lineCount;
    
    for (int i = 0; i < lineCount; i++)
    {
        if (i % 2 == 1)
            cout << ' ';
        
        for (int i = 0; i < lineCount; i++)
            cout << "* ";
        
        cout << '\n';
    }
    return 0;
}

