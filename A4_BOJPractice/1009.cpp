//https://www.acmicpc.net/problem/1009

/*분산처리

재용이는 최신 컴퓨터를 10대 가지고 있다. 어느 날 재용이는 많은 데이터를 처리해야 될 일이 생겨서 각 컴퓨터에 1~10번 번호를 부여하고
각 데이터를 컴퓨터 번호 순서대로 순회하며 처리하기로 했다.
10번 데이터는 10번 컴퓨터, 11번 데이터는 1번 컴퓨터, 12번 데이터는 2번 컴퓨터, ...

총 데이터는 항상 a^b로 주어진다. a,b가 주어질때, 마지막 데이터가 처리될 컴퓨터 번호를 구하시오.
(a는 최대 99, b는 최대 999999)

*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int a, b;
        cin >> a >> b;
        int result = a % 10;

        for (int EXP = 2; EXP <= b; EXP++)
            result = result * a % 10;

        if (result == 0)
            cout << 10 << '\n';
        else
            cout << result << '\n';
    }
	
	return 0;
}
