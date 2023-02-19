//https://www.acmicpc.net/problem/20921

/*그렇고 그런 사이 (Silver 2)
문제 설명
*/

#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    set<int> havingSet;
    int people, ans;
    cin >> people >> ans;

    for (int i = 1; i <= people; i++)
        havingSet.insert(i);

    int precedure = 0;
    int nowMaximum = people - 1;

    while (precedure != ans)
    {
        if (precedure + nowMaximum <= ans)
        {
            havingSet.erase(nowMaximum + 1);
            cout << nowMaximum + 1 << ' ';
            precedure += nowMaximum;
        } else {
            havingSet.erase(ans - precedure + 1);
            cout << ans - precedure + 1 << ' ';
            precedure = ans;
        }

        nowMaximum--;
    }

    for (auto it = havingSet.begin(); it != havingSet.end(); ++it)
        cout << *it << ' ';

	
	return 0;
}
