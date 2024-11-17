//https://www.acmicpc.net/problem/9506

/*약수들의 합 (Bronze 1)
Solution : 수학, 구현
*/

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        int input;
        cin >> input;
        if (input == -1) break;

        int list[1000] = { 1, 0 };
        int cnt = 1, sum = 1;
        for (int i = 2; i <= input / 2; i++)
        {
            if (input % i == 0)
            {
                list[cnt++] = i;
                sum += i;
            }
        }
           
        if (sum == input)
        {
            cout << input << " = ";
            for (int i = 0; i < cnt; i++)
            {  
                cout << list[i];
                if (i != cnt - 1)
                    cout << " + ";
            }
            cout << '\n';
        }
        else {
            cout << input << " is NOT perfect.\n";
        }
    }

    return 0;
}