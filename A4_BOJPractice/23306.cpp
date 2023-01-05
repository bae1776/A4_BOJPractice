//https://www.acmicpc.net/problem/23306

/* binary는 호남선 (Silver 2) - 인터렉티브

binary는 호남선은 총 N(8 ~ 2048)개의 0, 1로 표현된다.
'구간'은 연속된 두 개의 철로를 뜻하며, 01은 오르막, 10은 내리막, 00, 11은 평탄한 구간이다.
floor(logN)번의 질문 안에 호남선에서 오르막 구간의 수가 내리막 구간의 수보다 많은지 출력하시오.

Solution : 호남선의 양 끝 철로의 상태만 알면 바로 답을 알 수 있다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int railLength;
    cin >> railLength;

    int first, last;
    cout << "? " << 1 << endl;
    cin >> first;
    cout << "? " << railLength << endl;
    cin >> last;

    if (first == last)
        cout << "! " << 0 << endl;
    else if (first > last)
        cout << "! " << -1 << endl;
    else
        cout << "! " << 1 << endl;
	
	return 0;
}

