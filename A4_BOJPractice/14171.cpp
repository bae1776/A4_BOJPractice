//https://www.acmicpc.net/problem/14171

//Cities and States
//미국의 지도를 보면, 미국의 도시의 첫 두 영문자와 주(State) 코드가 교차 대응되는 경우가 있다.
//예를 들어 Miami, FL 과 Fline, MI는 각각 플로리다, 미시간 주에 속한 도시인데, 도시의 첫 두 글자를
//보면 교차되어 일치한다.
//여러 도시(2~10글자), 주 코드 쌍 최대 20만개가 주어질 때 이러한 관계가 몇 개나 있는 지 찾으세요.
//이름이 같은 도시가 나올 수도 있지만, 이 경우 소속된 주는 반드시 다르며
//실제 미국에 있는 주 코드만 주어지는 것은 아닙니다.
//또한 서로 다른 주에 속하는 두 도시만 쌍으로 취급합니다.

#include <iostream>
#define ALPHABET 26
using namespace std;

int DP[ALPHABET][ALPHABET][ALPHABET][ALPHABET];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int cityCount;
    char cityName[11], stateName[3];

    cin >> cityCount;

    while (cityCount--)
    {
        cin >> cityName >> stateName;
        DP[cityName[0] - 'A'][cityName[1] - 'A'][stateName[0] - 'A'][stateName[1] - 'A']++;
    }

    long long result = 0;

    for (int city_1 = 0; city_1 < ALPHABET; city_1++)   
        for (int city_2 = 0; city_2 < ALPHABET; city_2++)   
            for (int state_1 = city_1; state_1 < ALPHABET; state_1++)   
                for (int state_2 = state_1 == city_1 ? city_2 + 1 : 0; state_2 < ALPHABET; state_2++)
                    result += (long long)(DP[city_1][city_2][state_1][state_2]) * 
                                  (long long)(DP[state_1][state_2][city_1][city_2]);   

    cout << result;

	return 0;
}
