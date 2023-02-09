//https://www.acmicpc.net/problem/1082

/*방 번호 (Gold 3)

자릿수를 최대한 늘리는 것이 최적이므로,
가장 싼 번호를 골라 그것만 계속 사서 나열한다.
그리고 남는 돈으로 가장 높은 자리부터 조금 더 비싸고 큰 수로 바꿀 수 있다면 바꾼다.
그러나 만약 가장 싼 번호가 0이라면, 두번째로 싼 번호를 맨 처음에 고른 뒤, 0을 나열해야한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> shop;
char output[52];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int numKind;
    cin >> numKind;

    shop = vector<pair<int, int>>(numKind);
    for (int i = 0; i < numKind; i++)
    {
        cin >> shop[i].first;
        shop[i].second = i;
    }

    sort(shop.begin(), shop.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
        {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    });

    int money;
    cin >> money;

    if (numKind == 1)
    {
        cout << 0;
        return 0;
    }

    //필요없는 번호 지우기
    int max = shop[0].second;
    for (auto it = shop.begin() + 1; it != shop.end();)
    {
        if (it->second < max)
            it = shop.erase(it);
        else {
            max = it->second;
            ++it;
        }
    }


    //첫번째 번호 선정
    if (shop[0].second == 0)
    {
        if (money >= shop[1].first)
        {
            money -= shop[1].first;
            output[0] = '0' + shop[1].second;
        } else {
            money = 0;
            output[0] = '0';
        }
    } else {
        money -= shop[0].first;
        output[0] = '0' + shop[0].second;
    }

    int repeat = money / shop[0].first;
    for (int i = 1; i <= repeat; i++)
        output[i] = '0' + shop[0].second;
    money = money % shop[0].first;

    
    if (shop[0].second == 0 && output[0] != '0')
        money += shop[1].first - shop[0].first;

    //남는 돈으로 숫자 업그레이드
    int upgradeIndex = 0;
    while (true)
    {
        auto it = shop.end() - 1;
        for (; it != shop.begin(); --it)
        {
            if (it->first <= money + shop[0].first)
            {
                money = money + shop[0].first - it->first;
                output[upgradeIndex++] = '0' + it->second;
                break;
            }
        }

        if (it == shop.begin())
            break;
    }

    cout << output;

	return 0;
}
