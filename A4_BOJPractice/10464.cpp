//https://www.acmicpc.net/problem/10464

/* XOR (Gold 4)

자연수 A, B가 주어진다.
A, A + 1 ... ,B 까지 모두 XOR한 값을 구하시오.
테스트케이스는 1천개이다.

Solution :
1부터 N까지 XOR을 할 때의 규칙성이 있다.
첫번째 자리 : 1100\1100\1100\1100  (4)
두번째 자리 : 0100\0100\0100\0100  (4)
세번째 자리 : 00010100\00010100    (8)
네번째 자리 : 0000000101010100\    (16)
다섯번 자리 : 00000000000000010101010101010100\ (32 = 2^5)
1 XOR 2 XOR 3 XOR ... XOR A XOR 1 XOR 2 ... XOR B를 하면 된다.

*/


#include <iostream>
using namespace std;

int XOR1to(int a)
{
    int result = 0;

    //첫번째와 두번째 자리의 결정
    int temp = a % 4;
    if (temp == 1)
        result += 1;
    else if (temp == 2)
        result += 3;

    //이후 자릿수의 결정
    int div = 4;
    do {
        div *= 2;
        temp = (a + 1) % div;
        if (temp > div / 2 && temp % 2)
            result += div / 2;
            
    } while (a >= div);

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int a, b;
        cin >> a >> b;
        cout << (XOR1to(a - 1) ^ XOR1to(b)) << endl; 
    }
    

    return 0;
}
