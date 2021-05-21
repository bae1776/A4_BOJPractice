//https://www.acmicpc.net/problem/999 (문제 번호)

//후위 표기식
//중위 표기식이 주어질 때 후위 표기식으로 전환하시오.
//중위 표기식은 피연산자 A~Z와 +-*/()으로만 구성되며 최대 길이는 100이다.

//우선 순위 ( --> +- --> */ --> )    
//넣으려는 연산자가 top에 있는 연산자의 우선 순위가 높거나 같으면 먼저 top을 꺼내야 한다.
//닫는 괄호의 경우 여는 괄호까지 싹 빼낸다.

#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    char infix[102], postfix[102];
    cin >> infix;

    int strLength = 0;
    while (infix[++strLength] != '\0');

    int index_postFix = 0;
    stack<char> opStack;

    for (int i = 0; i < strLength; )
    {
        if (infix[i] >= 'A' && infix[i] <= 'Z')
            postfix[index_postFix++] = infix[i++];
        else {
            switch (infix[i])
            {
                //우선 순위 높은 순 
                case '(':
                    opStack.push(infix[i++]);
                    break;

                case '+': case '-':
                    if (opStack.empty() == false && opStack.top() != '(')
                    {
                        postfix[index_postFix++] = opStack.top();
                        opStack.pop();
                    }
                    else
                        opStack.push(infix[i++]);
                    break;

                case '*': case '/':
                    if (opStack.empty() == false)
                        if (opStack.top() == '*' || opStack.top() == '/')
                        {
                            postfix[index_postFix++] = opStack.top();
                            opStack.pop();
                        }
                        else
                            opStack.push(infix[i++]);
                    else opStack.push(infix[i++]);
                   
                    break;
                
                case ')':
                    while (opStack.top() != '(')
                    {
                        postfix[index_postFix++] = opStack.top();
                        opStack.pop();
                    }
                    opStack.pop();
                    i++;
                    break;
            }
        }
    }

    while (opStack.empty() == false)
    {
        postfix[index_postFix++] = opStack.top();
        opStack.pop();
    }

    postfix[index_postFix++] = '\0';

    cout << postfix;

    

	return 0;
}
