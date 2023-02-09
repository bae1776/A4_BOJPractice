//https://www.acmicpc.net/problem/16172

/* 나는 친구가 적다 (Large) (Bronze 2 ??)

문자열 A, B가 주어진다.
A에는 영문 대소문자, 숫자가 들어있다. A에서 숫자는 제외한 문자열에서
영문 대소문자로만 이루어진 B를 찾으시오.
A와 B의 길이는 최대 20만이다.

Solution : KMP (아니면 시간 초과일 거 같은데 왜 난도가 고작...)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> suffix(const string& word);
bool kmpFind(const string& doc, const string& word);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int aAlphabetCount = 0;
    for (int i = 0; i < a.size(); i++)
        if (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z'))
            a[aAlphabetCount++] = a[i];
    
    a.resize(aAlphabetCount);

    cout << kmpFind(a, b);
	
	return 0;
}


vector<int> suffix(const string& word)
{
    vector<int> result(word.size() + 1);
    int left = 0, right = 1;

    while (right != word.size())
    {
        if (word[left] == word[right])
        {
            result[++right] = ++left;
        } else {
            if (left == 0)
                result[++right] = 0; 
            else
                left = result[left];
        }
    }    

    return result;
}

bool kmpFind(const string& doc, const string& word)
{
    auto wordPattern = suffix(word);

    int docPointer = 0, wordPointer = 0;

    while (docPointer != doc.size())
    {
        if (doc[docPointer] == word[wordPointer])
        {
            docPointer++;
            wordPointer++;
            if (wordPointer == word.size())
                return true;
        } else {

            if (wordPointer == 0)
                docPointer++;
            else
                wordPointer = wordPattern[wordPointer];
        }
    }

    return false;
}
