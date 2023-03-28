//https://www.acmicpc.net/problem/2137

/*가장 가까운 분수 (Gold 4)

Solution : 브루트포스
최대 분모가 32767 이므로 분모가 1 ~ 32767일때
각각 입력으로 주어진 수와 가장 가깝게 하는 분자 값을 구하고 그 중 오차가 가장 적은 것이
답이 된다. 단, 오차가 아예 없는 것은 제외한다. (입력으로 주어진 분모의 배수인 경우)


*/

#include <iostream>
#include <cmath>
using namespace std;
pair<int, int> taskList[1000]; //deadline, duration

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a%b) : a;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int up, down;
    cin >> up >> down;

    double target = (double)up / (double)down;
    double numError = 1.0;
    int answerUp, answerDown;


    for (int div = 1; div <= 32767; div++)
    {
        double closeUp = round(target * (double)div);
        if (div % down == 0)
            closeUp--;
        if (gcd(div, closeUp) != 1) continue;

        if (numError > abs(target - closeUp / (double)div))
        {
            numError = abs(target - closeUp / (double)div);
            answerUp = closeUp;
            answerDown = div;
        }
    }

    cout << answerUp << ' ' << answerDown;

	return 0;
}
