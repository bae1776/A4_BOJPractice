//https://www.acmicpc.net/problem/27377

/*읽씹 멈춰! (Gold 4)

Solution : 그리디

복사 붙여넣기, 추가한다고 생각하지 말고
반대로 원래 여러번 복사되있는 문자에서 삭제 / 타노스한다고 생각하는 것이 더 쉽다.
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
        long long num, subCost, shiftCost;
        cin >> num >> subCost >> shiftCost;

        long long cost = 0;

        while (num)
        {
            if (num % 2)
            {
                cost += subCost;
                num--;
            } else {
                if (num / 2 >= shiftCost)
                    cost += shiftCost;
                else
                    cost += min(num / 2 * subCost, shiftCost);
                //시프팅하는 것과 그 시프트까지 빼기로만 작업하는 것중 더 싼것
                //(오버플로우 주의)
                num /= 2;
            }
        }

        cout << cost << '\n';
    }

	return 0;
}