//https://www.acmicpc.net/problem/11003

/*최솟값 찾기 (Platinum 5)
수열 (A1, A2, A3 ... An)과 L이 주어진다.
Di = min(A(i-L+1) ~ Ai) 로 정의할 때, (i <= 0인 Ai는 무시함)
D1~Dn을 구하시오.

N, L은 최대 500만, Ai는 -10억~10억이다.

Soultion : 리스트를 이용한 슬라이딩 윈도우 (O(n))
우선 순위 큐 등으로도 풀 수 있으나 아슬아슬하다. (O(nlogn))
*/

#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, L;
    cin >> N >> L;

    list<pair<int, int>> numList; //value, index
    int input;
    for (int idx = 1, left = 2 - L; idx <= N; idx++, left++)
    {
        cin >> input;

        //Delete Phase
        while (numList.empty() == false && numList.back().first >= input)
            numList.pop_back();

        while (numList.empty() == false && numList.front().second < left)
            numList.pop_front();
        
        //Add Phase
        numList.emplace_back(input, idx);

        //Print Phase
        cout << numList.front().first << ' ';
        
    }

	
	return 0;
}
