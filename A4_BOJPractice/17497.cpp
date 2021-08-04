//https://www.acmicpc.net/problem/17497

/*계산기

승우는 과제로 계산기를 만들고 있는데 아직은 미완성이라 기능이 4개밖에 없습니다.
[+] : X에 2를 더합니다.
[-] : X에서 2를 뺍니다.
[*] : X에 2를 곱합니다.
[/] : X를 2로 나눕니다. (나머지는 버립니다.)

버튼을 눌렀을 때 X가 음수가 되거나 2^63-1이 초과하면 계산기가 폭발합니다.
승우는 계산기가 잘 작동하는지 테스트하고 싶습니다.
초기값이 0일때, 정수 N이 주어질 때 N이 되도록 해주세요.
누른 횟수는 99번 이하이며 N을 만들 수 없다면 -1을 출력하세요.
*/

#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    long long num;
    int clickCount = 0;
    char operatorClick[99] = {0};

    cin >> num;

    num *= 2;
    
    //input Reversed operating order and after fliping array
    for (long long bitMask = 2; bitMask <= num; bitMask *= 2)
    {
        if (num & bitMask) {
            operatorClick[clickCount] = '*';
            operatorClick[clickCount + 1] = '+';
            clickCount += 2;
        } else {
            operatorClick[clickCount++] = '*';
        }
    }
    operatorClick[0] = '/';

    for (int i = 0; i < clickCount / 2; i++)
    {
        char temp = operatorClick[i];
        operatorClick[i] = operatorClick[clickCount - 1 - i];
        operatorClick[clickCount - 1 - i] = temp;
    }

    cout << clickCount << '\n';

    for (int i = 0; i < clickCount; i++)
        cout << '[' << operatorClick[i] << "] ";
    
    
    return 0;

}