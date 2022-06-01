//https://www.acmicpc.net/problem/19585
//전설 (Platinum 3)
//트라이 알고리즘 기법을 사용하여 해결할 수 있다.
//트라이 알고리즘 설명 : https://twpower.github.io/187-trie-concept-and-basic-problem


#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define NOTFOUND -1

typedef char mSize;

struct Trie {
    bool self;
    map<char, Trie*> children;

    Trie() : self(false), children() {};

};

vector<char> chk;

void Trie_insert(Trie* trie, const string& str);
void Trie_search(Trie* trie, const string& str, bool reversed);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int colorCount, nicknameCount;
    cin >> colorCount >> nicknameCount;

    string input;

    Trie* colorTrie = new Trie;
    Trie* nicknameTrie = new Trie;

    for (int i = 0; i < colorCount; i++)
    {
        cin >> input;
        Trie_insert(colorTrie, input);
    }

    for (int i = 0; i < nicknameCount; i++)
    {
        cin >> input;
        reverse(input.begin(), input.end());
        Trie_insert(nicknameTrie, input);
    }

    int teamCount;
    cin >> teamCount;

    chk = vector<char>(2003, 0);
    for (int i = 0; i < teamCount; i++)
    {
        cin >> input;

        for (int j = 0; j <= input.length(); j++)
            chk[j] = 0;
        Trie_search(colorTrie, input, false);
        reverse(input.begin(), input.end());
        Trie_search(nicknameTrie, input, true);

        bool isLegend = false;
        for (int j = 0; j <= input.length(); j++)
        {
            if (chk[j] == 2)
            {
                isLegend = true;
                break;
            }
        }
        if (isLegend)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}


void Trie_insert(Trie* trie, const string& str)
{
    for (const char& ch : str)
    {
        if (trie->children.find(ch) == trie->children.end())
            trie->children[ch] = new Trie;

        trie = trie->children[ch];
    }

    trie->self = true;
    return;
}


void Trie_search(Trie* trie, const string& str, bool reversed)
{
    int index = 1;

    for (const char& ch : str)
    {
        if (trie->children.find(ch) == trie->children.end())
            return;

        trie = trie->children[ch];

        if (trie->self == true)
            if (reversed)
                chk[str.size() - index]++;
            else
                chk[index]++;

        index++;
    }
}
