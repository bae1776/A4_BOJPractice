//https://www.acmicpc.net/problem/1493

/*박스채우기 (Gold 3)

Solution : 그리디 알고리즘
큰 큐브를 놓을 수 있다면, 그 자리에 작은 큐브를 대신 배치하면 큐브의 수만 늘뿐,
불가능한 배치가 가능해지지는 않는다.
즉, 무조건 큰 큐브부터 가능한만큼 집어넣는 식으로 그리디한 접근으로 풀 수 있다.
*/


#include <iostream>
using namespace std;

long long maxCube[20];
long long havingCube[20];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long length, width, height;
    cin >> length >> width >> height;
    for (int i = 0; i < 20; i++)
        maxCube[i] = (length / (1ll << i)) * (width / (1ll << i)) * (height / (1ll << i));
    
    int cubeSort;
    cin >> cubeSort;
    while (cubeSort--)
    {
        int cubeSize;
        cin >> cubeSize;
        cin >> havingCube[cubeSize];
    }

    long long answer = 0;
    for (int i = 19; i >= 0; i--)
    {
        long long insertAvailable = min(maxCube[i], havingCube[i]);

        if (insertAvailable == 0)
            continue;

        answer += insertAvailable;
        for (int j = 0; j <= i; j++)
            maxCube[j] -= (1ll << (3 * (i - j))) * insertAvailable;
    }

    if (maxCube[0] == 0)
        cout << answer;
    else
        cout << -1;

	return 0;
}
