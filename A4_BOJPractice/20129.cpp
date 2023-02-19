//https://www.acmicpc.net/problem/20129

/* 뒤집힌 계산기 (Gold 3)

Solution : 구현
스택으로 구현하면 편하다.
*/


#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<long long> numStack;
stack<char> opStack;
string input;
int opRank[255];
char op[4] = {'+', '-', '*', '/'};



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 4; i++)
        cin >> opRank[op[i]];
    opStack.push('?');
    
    cin >> input;

    int numLen = 0;
    for (auto ch = input.rbegin(); ch != input.rend(); ++ch)
    {
        if ('0' <= *ch && *ch <= '9')
        {
            numStack.push(*ch - '0');
            numLen++;
        } else {
            //앞의 0 폭파
            while (numStack.top() == 0 && numLen--)
                numStack.pop();

            if (numLen == 0)
                numStack.push(0);
            else {
                while (numLen >= 2)
                {
                    long long first = numStack.top();
                    numStack.pop();
                    long long second = numStack.top();
                    numStack.pop();
                    numStack.push(first * 10 + second);
                    numLen--;
                }
            }
            numLen = 0;

            while (opRank[*ch] <= opRank[opStack.top()])
            {
                long long first = numStack.top();
                numStack.pop();
                long long second = numStack.top();
                numStack.pop();

                switch (opStack.top()) {
                    case '+':
                        numStack.push(second + first); break;
                    case '-':
                        numStack.push(second - first); break;
                    case '*':
                        numStack.push(second * first); break;
                    case '/':
                        numStack.push(second / first); break;
                }

                opStack.pop();
            }
            opStack.push(*ch);
        }
    }

   
    while (numLen >= 2)
    {
        long long first = numStack.top();
        numStack.pop();
        long long second = numStack.top();
        numStack.pop();
        numStack.push(first * 10 + second);
        numLen--;
    }
    

    while (opStack.size() > 1)
    {
        long long first = numStack.top();
        numStack.pop();
        long long second = numStack.top();
        numStack.pop();

        switch (opStack.top()) {
            case '+':
                numStack.push(second + first); break;
            case '-':
                numStack.push(second - first); break;
            case '*':
                numStack.push(second * first); break;
            case '/':
                numStack.push(second / first); break;
        }
        opStack.pop();
    }

    cout << numStack.top();

	return 0;
}


