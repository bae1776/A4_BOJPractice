//https://www.acmicpc.net/problem/14725

/*개미굴 (Gold 3)

Solution : 자식이 여러개인 문자열 트리 (트라이)
*/

#include <iostream>
#include <map>
using namespace std;

struct Cave {
    string name;
    map<string, Cave> childMap;
};

Cave start;
void printDFS(const Cave& now, int depth);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int infoCount;
    cin >> infoCount;

    while (infoCount--)
    {
        int depth;
        cin >> depth;
        Cave* nowCave = &start;
        string input;

        while (depth--)
        {
            cin >> input;
            if (nowCave->childMap.find(input) == nowCave->childMap.end())
            {
                nowCave->childMap[input] = Cave();
                nowCave = &(nowCave->childMap[input]);
                nowCave->name = input;
            } else {
                nowCave = &(nowCave->childMap[input]);
            }
            
            
        }
    }

    printDFS(start, -1);

	return 0;
}


void printDFS(const Cave& now, int depth)
{
    for (int i = 0; i < depth; i++)
        cout << "--";
    if (depth >= 0)
        cout << now.name << '\n';

    for (auto it = now.childMap.begin(); it != now.childMap.end(); ++it)
        printDFS(it->second, depth + 1);
}