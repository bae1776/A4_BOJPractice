//https://www.acmicpc.net/problem/5597

/*과제 안 내신 분..? (Bronze 3)
Solution : 배열 체크하기

*/

#include <iostream>
using namespace std;

int arr[31];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int input;
    for (int i = 0; i < 28; i++)
    {
        cin >> input;
        arr[input]++;
    }

    for (int i = 1; i <= 30; i++)
        if (arr[i] == 0)
            cout << i << '\n';

    return 0;
}
