//https://www.acmicpc.net/problem/1406

/*에디터 (Silver 2)

삽입, 한 칸 이동 명령이 50만개이고 제한 시간은 0.3초이다.
연결 리스트를 이용해야만 풀 수 있음.
*/

#include <iostream>
#include <list>
using namespace std;
char input[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    list<char> str;
    cin >> input;

    int index = -1;
    while (input[++index] != '\0')
        str.push_back(input[index]);
    
    auto cursor = str.end();

    int command;
    cin >> command;

    char in, ch;
    while (command--)
    {
        cin >> in;
        switch (in)
        {
            case 'L':
                if (cursor != str.begin())
                    --cursor;
                break;
            
            case 'D':
                if (cursor != str.end())
                    ++cursor;
                break;
            
            case 'B':
                if (cursor != str.begin())
                    cursor = str.erase(--cursor);
                break;
            
            case 'P':
                cin >> ch;
                str.insert(cursor, ch);
        }
    }

    for (const char& c : str)
        cout << c;




	return 0;
}
