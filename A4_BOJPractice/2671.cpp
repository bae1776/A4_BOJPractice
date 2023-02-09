//https://www.acmicpc.net/problem/2671

/* 잠수함 식별 (Gold 5)

잠수함에서 나오는 소리와 잡음을 구별하고 싶다. 소리는 0 또는 1이 나열된 스트링으로 표현한다.
잠수함에서 나오는 소리는 (100~1~|01)~ 패턴을 만족시킨다.
x~, (xy)~ 는 각각 x, xy과 한번 이상 반복되는 모든 소리의 집합을 의미하고
(x|y) 는 x, y중 아무거나 하나를 선택해서 만든 소리의 집합이다.

최대 길이가 150인 소리가 입력될 때, 잠수함의 소리인지 잡음인지 출력하세요.
*/

#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string sound;
    cin >> sound;

    int len = sound.size();
    int index = 0;
    int state = 0;
    bool isMarine = false;

    while (index < len)
    {
        if (state == 0) //시작
        {
            if (index == len - 1)
            {
                isMarine = false;
                break;
            } else {
                if (sound[index] == '0' && sound[index + 1] == '1')
                {
                    index += 2;
                    isMarine = true; 
                } else if (sound[index] == '1' && sound[index + 1] == '0') {
                    state = 1;
                    index += 2;
                    isMarine = false;
                } else {
                    isMarine = false;
                    break;
                }
            }
        } else if (state == 1) { //10 for 100~1~ 
            if (sound[index] == '1') {
                isMarine = false;
                break;
            }

            while (index < len && sound[index] == '0')
                index++;

            state = 2;
        } else if (state == 2) { //100~ for 100~1~
            int oneDup = 0;
            while (index < len && sound[index] == '1')
            {
                isMarine = true;
                index++;
                oneDup++;
            }

            if (oneDup >= 2)
                state = 3;
            else
                state = 0;
        } else if (state == 3) { //Start after 100~11~  (sound[index] == '0')
            if (index == len - 1)
            {
                isMarine = false;
                break;
            } else {
                if (sound[index + 1] == '1')
                {
                    isMarine = true;
                    index += 2;
                    state = 0;
                } else if (sound[index + 1] == '0')
                {
                    isMarine = false;
                    index++;
                    state = 1;
                }
            }
        }
    }

    if (isMarine)
        cout << "SUBMARINE";
    else
        cout << "NOISE";
    
	return 0;
}
