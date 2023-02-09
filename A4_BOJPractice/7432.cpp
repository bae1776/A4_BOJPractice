//https://www.acmicpc.net/problem/7432

/*디스크 트리 (Gold 2)

Solution : 딕셔너리 안의 딕셔너리 (자기 참조 구조체)
*/

#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

struct Directory {
    int depth;
    string name;
    map<string, Directory> sub;

    Directory() {};
    Directory(int d, string s) : depth(d), name(s) {};
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int dirCount;
    cin >> dirCount;

    string input;
    Directory root;
    root.depth = -1;

    while (dirCount--)
    {
        cin >> input;
        Directory* dirPointer = &root;

        //서브 디렉토리 추출 및 트리 추가
        int startIndex = 0, endIndex;
        do {
            endIndex = min(input.find('\\', startIndex), input.size());

            string subDir = input.substr(startIndex, endIndex - startIndex);
            if (dirPointer->sub.find(subDir) == dirPointer->sub.end())
                dirPointer->sub[subDir] = Directory(dirPointer->depth + 1, subDir);
            dirPointer = &(dirPointer->sub.find(subDir)->second);

            startIndex = endIndex + 1;
        } while (endIndex != input.size());
    }

    //DFS로 출력하기.
    stack<Directory*> dfsStack;
    dfsStack.push(&root);

    while (dfsStack.empty() == false)
    {
        Directory* now = dfsStack.top();
        dfsStack.pop();

        for (int i = 0; i < now->depth; i++)
            cout << ' ';
        if (now != &root)
            cout << now->name << '\n';

        for (auto it = now->sub.rbegin(); it != now->sub.rend(); ++it)
            dfsStack.push(&(it->second));
        
    }
    
	return 0;
}