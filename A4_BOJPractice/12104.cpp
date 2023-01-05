//https://www.acmicpc.net/problem/12104

/*순환 순열 (Platinum 5)

*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> getPi(const string& str);
int kmpCount(const string& doc, const string& word);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string a, b;
    a.reserve(1000001);
    cin >> a;
    cin >> b;
    a += a;
    a.pop_back();
    cout << kmpCount(a, b);
	return 0;
}


vector<int> getPi(const string& str)
{
    int len = str.length();
    vector<int> result(len);

    int matchingPointer = 0;
    for (int p = 1; p < len;)
    {
        if (str[p] == str[matchingPointer])
        {
            result[p] = matchingPointer + 1;
            matchingPointer++;
            p++;
        }
        else {
            if (matchingPointer == 0)
            {
                result[p++] = 0;
                continue;
            }
            matchingPointer = result[matchingPointer - 1];
        }
    }

    return result;
}

int kmpCount(const string& doc, const string& word)
{
    auto wordMatch = getPi(word);

    int docLen = doc.length(), wordLen = word.length();
    int matchPointer = 0, result = 0;
    for (int docPointer = 0; docPointer < docLen;)
    {
        if (doc[docPointer] == word[matchPointer])
        {
            if (matchPointer == wordLen - 1)
            {
                result++;
                matchPointer = wordMatch[matchPointer];
            } else {
                matchPointer++;
            }
            docPointer++;
        } else {
            if (matchPointer == 0)
                docPointer++;
                
            matchPointer = wordMatch[matchPointer - 1];
            
        }
    }

    return result;
}