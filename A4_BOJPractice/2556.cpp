//https://www.acmicpc.net/problem/2556

//별 찍기 - 14
//Not ratable
//'적절히' 별을 찍읍시다.

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lineCount;
    cin >> lineCount;

    for (int star = 1; star <= lineCount; star++)
    {
        for (int i = 0; i < lineCount; i++)
            cout << '*';
        cout << '\n';
    }
    
    return 0;
}
