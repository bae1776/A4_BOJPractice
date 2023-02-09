//https://www.acmicpc.net/problem/1354

/*무한 수열 2 (Gold 5)

Solution : 배열에 대한 <index, value> 맵을 활용한 풀이
(단순 배열은 인덱스가 최대 10^13이나 되므로 불가능)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> hashArray;
long long N, P, Q, X, Y;

long long getValue(long long index);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    
    cin >> N >> P >> Q >> X >> Y;

    cout << getValue(N);

	return 0;
}


long long getValue(long long index)
{
    if (index <= 0)
        return 1;
        
    auto self = hashArray.find(index);
    if (self != hashArray.end())
        return self->second;

    return hashArray[index] = getValue(index / P - X) + getValue(index / Q - Y);
}
