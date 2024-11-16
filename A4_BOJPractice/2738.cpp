//https://www.acmicpc.net/problem/2738

/*Çà·Ä µ¡¼À (Bronze 3)
Solution : 2Â÷¿ø ¹è¿­

*/

#include <map>
#include <iostream>
using namespace std;

int mat[100][100];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> mat[i][j];


    for (int i = 0; i < N; i++)
    {
        int input;
        for (int j = 0; j < M; j++)
        {
            cin >> input;
            cout << mat[i][j] + input << ' ';
        }
        cout << '\n';
    
    }


    return 0;
}
