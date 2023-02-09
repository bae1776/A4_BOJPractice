//https://www.acmicpc.net/problem/1036

/*36진수 (Gold 1)

Solution :

Z로 변환하는 모든 경우의 수를 따지면 최악의 경우 36C18 = 90억이기 때문에
완전 탐색으로는 풀 수 없다.
그래서 다음과 같은 방식으로 푼다:
1. 주어진 모든 수를 0 ~ Z 성분으로 분해하여 각자 저장한다.
2. 그리고 각 성분을 Z로 바꿨을 때 증가하는 수 크기를 계산한다.
3. 2.의 결과를 내림차순 정렬해서 K개 선택한다.
4. 원래 숫자의 합계에서, 3.에서 선택된 수를 더하면 정답이 된다.


*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Num36 {
private:
    unsigned char digit[52];

public:
    Num36();
    Num36(const Num36& copier);
    Num36(int digitIndex, int digitValue);
    Num36(const string& input);
    Num36 operator+(const Num36& operand);
    Num36& operator=(const Num36& operand);
    void addDigit(int digitIndex, int digitValue);
    void print();
    friend bool operator<(const Num36& a, const Num36& b);
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int numCount;
    cin >> numCount;

    Num36 increaseAmount[36];
    Num36 numberSum;

    string input;
    while (numCount--)
    {
        cin >> input;
        Num36 nowNumber(input);

        numberSum = numberSum + nowNumber;

        int digitIndex = 0;
        for (auto it = input.rbegin(); it != input.rend(); ++it)
        {
            int inc;
            if ('0' <= *it && *it <= '9')
                inc = *it - '0';
            else
                inc = *it - 'A' + 10;

            increaseAmount[inc].addDigit(digitIndex, 35 - inc);
            digitIndex++;
        }
    }

    int convertCount;
    cin >> convertCount;
    sort(increaseAmount, increaseAmount + 36);

    for (int i = 35; i > 35 - convertCount; i--)
        numberSum = numberSum + increaseAmount[i];
    
    numberSum.print();

    return 0;
}


Num36::Num36()
{
    for (int i = 0; i < 52; i++)
        digit[i] = 0;
}

Num36::Num36(const Num36& copier)
{
    for (int i = 0; i < 52; i++)
        digit[i] = copier.digit[i];
}


Num36::Num36(int digitIndex, int digitValue)
{
    for (int i = 0; i < 52; i++)
        digit[i] = 0;
    digit[digitIndex] = digitValue;
}

Num36::Num36(const string& input)
{
    int index = 0;
    for (auto it = input.rbegin(); it != input.rend(); ++it)
    {
        if ('0' <= *it && *it <= '9')
            digit[index++] = *it - '0';
        else if ('A' <= *it && *it <= 'Z')
            digit[index++] = *it - 'A' + 10;
    }

    for (; index < 52; index++)
        digit[index] = 0;   
}

Num36 Num36::operator+(const Num36& operand)
{
    Num36 result(*this);
    for (int i = 0; i < 52; i++)
    {
        result.digit[i] += operand.digit[i];
        if (result.digit[i] >= 36)
        {
            result.digit[i] -= 36;
            result.digit[i + 1]++;
        }
    }

    return result;
}

Num36& Num36::operator=(const Num36& operand)
{
    for (int i = 0; i < 52; i++)
        this->digit[i] = operand.digit[i];
    
    return (*this);
}

void Num36::addDigit(int digitIndex, int digitValue)
{
    this->digit[digitIndex] += digitValue;
    while (this->digit[digitIndex] >= 36)
    {
        this->digit[digitIndex] -= 36;
        this->digit[digitIndex + 1] += 1;
        digitIndex++;
    }

}

void Num36::print()
{
    int lastNonZeroIndex = 0;
    for (int i = 0; i < 52; i++)
        if (this->digit[i] != 0)
            lastNonZeroIndex = i;
    
    constexpr static char convTable[36] = { 
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    for (int i = lastNonZeroIndex; i >= 0; i--)
    {
        cout << convTable[this->digit[i]];
    }
}


bool operator<(const Num36& a, const Num36& b)
{
    int start = 51;
    while (start >= 0 && a.digit[start] == b.digit[start])
        start--;
    
    if (start == -1)
        return a.digit[0] < b.digit[0];
    else
        return a.digit[start] < b.digit[start];
}