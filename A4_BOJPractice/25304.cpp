//https://www.acmicpc.net/problem/25314

/*�ڵ��� ü������ �Դϴ� (Bronze 5)
Solution : �ݺ���


*/

#include <iostream>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int byte;
    cin >> byte;
    byte /= 4;

    for (int i = 0; i < byte; i++)
        cout << "long ";
    cout << "int";

    return 0;
}

