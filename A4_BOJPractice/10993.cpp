//https://www.acmicpc.net/problem/10993

//별 찍기 - 18
//Gold 4
//규칙을 유추하여 별을 찍어보자. (N <= 10)
//N = 3 예시
//      *
//     * *
//    *   *
//   *******
//  *  ***  *
// *    *    *
//*************

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
    if (line == 0)
    {
        for (int lin = 1; lin <= (1 << depth) - 1; lin++)
        {
            function(depth, lin);
            cout << '\n';
        }
    } else {
        int perBlock = 1 << (depth - 1);

        if (depth % 2 == 0) //reversed triangle
        {
            if (line == 1)
            {//series Star = 1, 5, 13, 29
                int seriesStarCount = (2 << depth) - 3;
                for (int i = 0; i < seriesStarCount; i++)
                    cout << '*';
                
            } 
            else if (line <= perBlock)
            {
                for (int i = 0; i < line - 1; i++)
                    cout << ' ';
                cout << '*';
                for (int i = 0; i < perBlock - line; i++)
                    cout << ' ';
                
                
                function(depth - 1, line - 1);

                for (int i = 0; i < perBlock - line; i++)
                    cout << ' ';
                cout << '*';
                if (depth != lineCount)
                    for (int i = 0; i < line - 1; i++)
                        cout << ' ';
            } else {

                for (int i = 0; i < line - 1; i++)
                    cout << ' ';
                cout << '*'; 
                for (int i = 0; i < (2 << depth) - 3 - 2 * line; i++)
                    cout << ' ';
                if (line != (1 << depth) - 1)
                    cout << '*';
                if (depth != lineCount)
                    for (int i = 0; i < line - 1; i++)
                        cout << ' ';

            }
        } else {
            if (line == (1 << depth) - 1)
            {
                int seriesStarCount = (2 << depth) - 3;
                for (int i = 0; i < seriesStarCount; i++)
                    cout << '*';
            } 
            else if (line >= perBlock)
            {
                for (int i = 0; i < (1 << depth) - line - 1; i++)
                    cout << ' ';
                cout << '*';
                for (int i = 0; i < line - perBlock; i++)
                    cout << ' ';

                 function(depth - 1, line - perBlock + 1);

                for (int i = 0; i < line - perBlock; i++)
                    cout << ' ';
                cout << '*';
                if (depth != lineCount)
                    for (int i = 0; i < (1 << depth) - line - 1; i++)
                        cout << ' ';

                
            } else {
                for (int i = 0; i < (1 << depth) - line - 1; i++)
                    cout << ' ';
                cout << '*'; 
                for (int i = 0; i < 2 * line - 3; i++)
                    cout << ' ';
                if (line != 1)
                    cout << '*';
                if (depth != lineCount)
                    for (int i = 0; i < (1 << depth) - line - 1; i++)
                        cout << ' ';

            }
        }
    }
}