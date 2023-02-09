//https://www.acmicpc.net/problem/9093

/*단어 뒤집기 (Bronze 1)

쉬움
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;
    cin.ignore();

    string input;
    while (testcase--)
    {
        stack<char> s;
        getline(cin, input);

        for (const char& ch : input)
        {
            if (ch == ' ')
            {
                while (s.empty() == false)
                {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            } else
                s.push(ch);
        }

        while (s.empty() == false)
        {
            cout << s.top();
            s.pop();
        }

        cout << '\n';
    }
    
	return 0;
}
