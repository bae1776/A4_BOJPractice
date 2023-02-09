//https://www.acmicpc.net/problem/11191

/* Xor Maximization (Platinum 3)

건나르는 나이 들고 건망증 많은 연구가이다. 그는 보안에 대해 연구하는데,
보안에 신경을 많이 써서 각 사이트마다 다른 패스워드를 가진다.
모든 비밀번호를 외우긴 어렵기 때문에, 패스워드를 만드는 방법만 기억한다.

가장 중요한 웹사이트들 중 하나는 음수가 아닌 아주 긴 정수 배열 파일로 시작한다.
그는 XOR 연산을 좋아하여 비밀번호는 배열 중에서 몇 개의 정수를 골라 모두 XOR할 때 만들 수 있는 가장 큰 수이다.

정수 배열이 주어질 때, 비밀번호를 구하시오.
(정수 최대 10만개, 각 정수는 100경 이하의 양수이다)

Solution : 선형대수의 Reduces Row Echelon Form
https://velog.io/@dnr6054/Subset-XOR-Maximization
각 정수를 이진수로 표현한 것을 하나의 벡터로 간주하고 11 -> [1 0 1 1]
모든 정수(벡터)들을 행 방향으로 만든 행렬에 대하여 RREF를 구한다.

100경 < 2^60 이니까 대략 60차원 벡터라고 생각하고, 
이 벡터들을 XOR 하여 Basis을 뽑아내 Span한 결과의 최댓값이 답이 된다.
-> Axiom : Basis만을 가지고 입력된 모든 벡터를 나타낼 수 있다. 
이때, 벡터 A, B를 XOR 한것도 Basis가 될 수 있는데,
그 결과에 XOR A를 하면 B, XOR B를 하면 A를 다시 얻을 수 있기 때문이다. (XOR의 성질)

4차원 공간 상 벡터 4개를 정의한다.
1001 (9)
0111 (7)
0100 (4)
0010 (2)

먼저 9를 1번 좌표 성분 상의 기저로 삼는다. basis[3] = 9;
그다음 7을 2번 좌표 성분 상의 기저로 삼는다. basis[2] = 7;
4를 보는데, basis[2]는 이미 존재하므로 7 XOR 4 = 3  -> 사다리꼴 행렬을 만들기 위함임
3을 3번 좌표 성분 상의 기저로 삼는다. basis[1] = 3;
그다음 2를 보는데, basis[1]은 이미 존재하므로 2 XOR 3 = 1
1은 4번 좌표 성분 상의 기저로 삼는다. basis[0] = 1;

구한 기저들을 Span 시켜 최대 크기의 벡터를 구할 차례이다.
각 기저들을 선택 혹은 배제하는 식으로 지수 시간에 비례하는 방법으로 Span할 필요는 없고
basis의 값이 큰 순으로 그리디하게 ans = max(ans, ans XOR basis[i]) 하면 된다.
즉 for i in [60, 0, -1]:
    answer = max(answer, answer ^ basis[i])

이렇게 풀때 시간 복잡도는 O(NlogM) 이다. N은 정수의 갯수, M은 정수 최댓값이다.
*/

#include <iostream>
using namespace std;

long long basis[60];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arraySize;
    cin >> arraySize;
    
    while (arraySize--)
    {
        long long input;
        cin >> input;

        for (int shift = 59; shift >= 0; shift--)
            if ((input >> shift) & 1)
            {
                if (basis[shift] == 0)
                {
                    basis[shift] = input;
                    break;
                } else
                    input ^= basis[shift];
            }
    }

    long long ans = 0;
    for (int i = 59; i >= 0; i--)
        ans = max(ans, ans ^ basis[i]);
    
    cout << ans;

    return 0;
}