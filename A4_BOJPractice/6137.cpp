//https://www.acmicpc.net/problem/6137

/*문자열 생성 (Gold 5)

Solution :
그리디 알고리즘으로 풀 수 있으나 (왼쪽 끝, 오른쪽 끝 중에서 가장 사전 순으로 빠른 알파벳 선택)
양쪽 알파벳이 같은 경우, 그 안쪽 알파벳들끼리 비교하여야 정확히 나온다. (투 포인터 필요)
예를 들어, CADC의 경우 반드시 왼쪽 C를 먼저 선택해야한다.
*/

#include <deque>
#include <iostream>
using namespace std;

enum {SAME, LEFT, RIGHT};

int findPriority(const deque<char>& str); //Dir

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    deque<char> str;
    int len;
    cin >> len;

    char input;
    for (int i = 0; i < len; i++)
    {
        cin >> input;
        str.push_back(input);
    }

    deque<char> result;
    while (str.empty() == false)
    {
        int ret = findPriority(str);

        if (ret == SAME)
        {
            while (str.empty() == false)
            {
                result.push_back(str.front());
                str.pop_front();
            }
        } else if (ret == LEFT) {
            result.push_back(str.front());
            str.pop_front();
        } else if (ret == RIGHT) {
            result.push_back(str.back());
            str.pop_back();
        }
    }

    for (int i = 1; i <= len; i++)
    {
        cout << result.front();
        result.pop_front();
        
        if (i % 80 == 0)
            cout << '\n';
    }

	return 0;
}


int findPriority(const deque<char>& str)
{ //Dir
    int count = 1;
    auto leftIterator = str.begin();
    auto rightIterator = str.rbegin();
    do {
        if (*leftIterator < *rightIterator)
            return LEFT;
        else if (*leftIterator > *rightIterator)
            return RIGHT;

        ++leftIterator;
        ++rightIterator;
        ++count;
    } while (count <= str.size() / 2);

    return SAME;
}
