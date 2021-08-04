//https://www.acmicpc.net/problem/16439

/*치킨치킨치킨

N(1~30)명의 고리 회원은 M(3~30)가지의 치킨 중에서 서로 다른 3가지를 주문하려고 한다.
각 고리 회원의 M개의 치킨에 대한 선호도가 1~9 사이로 주어질 때
선호도 합의 최대를 출력하세요.

각 회원의 선호도는 3가지의 치킨에 대한 선호도 중 최고 값입니다.

*/

#include <iostream>
#include <vector>
#include <array>
using namespace std;

bool nextPerm(array<int, 3>& permList, const int& max);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int people, chickenCount;
    cin >> people >> chickenCount;

    vector<vector<int>> chickenProper(people, vector<int>(chickenCount));

    for (int pNumber = 0; pNumber < people; pNumber++)
        for (int cNumber = 0; cNumber < chickenCount; cNumber++)
            cin >> chickenProper[pNumber][cNumber];


    array<int, 3> selectedChicken = {0, 1, 2};
    int maxProper = 0;

    do {
        int caseProper = 0;
        for (int pNumber = 0; pNumber < people; pNumber++)
            caseProper += max(
                max(chickenProper[pNumber][selectedChicken[0]], 
                chickenProper[pNumber][selectedChicken[1]]), 
                chickenProper[pNumber][selectedChicken[2]]);

        if (caseProper > maxProper)
            maxProper = caseProper;

    } while (nextPerm(selectedChicken, chickenCount));

    cout << maxProper;

	return 0;
}


bool nextPerm(array<int, 3>& permList, const int& max)
{
    if (++permList[2] == max)
    {
        permList[2] = ++permList[1];
        if (++permList[2] == max)
        {
            permList[1] = ++permList[0];
            permList[2] = ++permList[1];
            if (++permList[2] == max)
                return false;
        }
    }
    return true;
}