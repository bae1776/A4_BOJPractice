//https://www.acmicpc.net/problem/9372

/*상근이의 여행

상근이는 방학을 맞아 N개국을 여행하면서 자아를 찾기로 마음 먹었다.
그러나 상근이는 새로운 비행기를 무서워하기 때문에 최대한 적은 종류의 비행기를 타고 국가들을 이동하려 한다.

비행기 종류를 최대한 적게 할 때의 비행기 종류 수를 구하여라.
주어지는 비행 스케줄은 항상 연결 그래프를 이룬다.
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
        int nations, airplanes;
        cin >> nations >> airplanes;

        int a, b;
        for (int i = 0; i < airplanes; i++)
            cin >> a >> b;

        cout << nations - 1 << '\n';

    }

    
	return 0;
}
