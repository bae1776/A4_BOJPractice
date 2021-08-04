//https://www.acmicpc.net/problem/17505

/*링고와 순열
링고는 1이상 N이하의 정수가 한 번씩 모두 등장하는 길이가 N인 
순열 [p1, p2, ..., pN]을 좋아합니다.
그 중에서 반전의 개수가 K인 순열을 제일 좋아합니다.
순열에서 반전이란 i < j 이면서 pi > pj 를 만족하는 (i, j) 쌍을 말합니다.

예를 들어 순열 [3, 1, 4, 5, 2] 는 길이가 5 이며 
반전의 개수는 4개 {(1, 2), (1, 5), (3, 5), (4, 5)} 입니다.

링고를 위해 링고가 제일 좋아하는 순열을 하나 찾아주세요.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
/* 풀이 :
    5 4 1 2 3 처럼 V자형으로 값이 내려갔다 올라가는 수열을 생각해보자.
     5   3   1   2   4 의 경우,
    (4) (2)  -   -   - : 첫 자리에 5가 위치한 경우 무조건 반전이 4개 생긴다.
                       : 이후 둘째 자리에 3이 위치한 경우 무조건 반전이 2개 생긴다.
    V자형에서 숫자 1에 도달할 때까지(즉 내려가는 부분에선), 반전은 무조건 발생하고,
    곰곰히 생각해보면
     2   1   3   4   5
    (1)                : 내려가는 부분에서 (반전 개수)=(배열값)-1 이 된다.

    한편, 임의의 반전 K값(<=N(N-1)/2)에 대하여 순열이 존재하지 않는 경우는 없다.
    왜냐하면, 

    배열 길이가 5일때, 반전이 최대인 경우는
     5   4   3   2   1 이며
    (4) (3) (2) (1)  -  10 = 4 + 3 + 2 + 1 로 구성된다.
    여기서 4, 3, 2, 1 을 마음대로 포함시키거나 제외할 수 있다. 예를 들어
    3을 제외하고 싶으면, 배열값 4를 맨 뒤로 보내면 된다. (5 3 2 1 4)
    1, 3을 제외하고 싶으면, 배열값 4, 2를 맨 뒤로 보내면 된다. (5 3 1 2 4)
    1, 2, 3, 4를 마음대로 포함하거나 제외시키면 0 ~ 10를 모두 만들 수 있다.

    K = (4?) + (3?) + (2?) + (1?) 를 구하는 알고리즘을 찾으면 되며,
    배열 길이 N에 대하여 O(N) 시간으로 처리가능하다.

*/
    long long length;
    long long reverse;
    cin >> length >> reverse;

    vector<int> descendList, ascendList;

    long long maxReverse = length * (length - 1) / 2;

    for (long long i = length - 1; i >= 0; i--)
    {
        if (reverse + i <= maxReverse)
        {
            ascendList.emplace_back(i + 1);
            maxReverse -= i;
        }
        else
            descendList.emplace_back(i + 1);
    }

    for (auto i = descendList.begin(); i != descendList.end(); ++i)
        cout << *i << ' ';

    for (auto i = ascendList.rbegin(); i != ascendList.rend(); ++i)
        cout << *i << ' ';



    return 0;
}
