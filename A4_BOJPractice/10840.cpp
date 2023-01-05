//https://www.acmicpc.net/problem/10840

/* 구간 성분 (Gold 1)

매 초마다 신호를 발생시키는 두 장치 A, B가 있다. 이 신호는 알파벳 소문자의 서열로 표현된다. 
A, B로부터 발생한 신호를 서열로 표시한 SA, SB의 예는 다음과 같다.

SA = [a, f, c, d, r, d, e, s, d, c, f, w, s, z, r]
SB = [g, e, d, s, r, d, d, e, m, z, r]

신호 서열의 어떤 구간에 포함된 문자의 종류와 개수가 순서에 상관없이 동일하면 이 두 ‘구간의 성분’은 같다고 한다. 
SA[3]~SA[9] == SB[1]~SA[7] 이고, 이 성분이 제일 길다.

두 문자열이 주어졌을 때, 가장 긴 구간 성분 길이를 구하여라.

Solution : 해싱
*/

#include <iostream>
#include <map>
#include <set>
#include <array>
#include <string>
#include <vector>
using namespace std;
using Element = array<short, 26>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string s1, s2;
    cin >> s1;
    cin >> s2;

    int minLength = min(s1.size(), s2.size());
    int result = 0;

    map<Element, set<short>> s1ElementMap;
    vector<Element> s2ElementList;
    for (int compareSize = 1; compareSize <= minLength; compareSize++)
    {
        //1. s1ElementMap Phase
        if (compareSize == 1)
        {
            for (int s1Index = 0; s1Index < s1.size(); s1Index++)
            {
                Element arr = {0, };
                arr[s1[s1Index] - 'a']++;
                s1ElementMap[arr].insert(s1Index); 
            }
        } else {
            vector<map<Element, set<short>>::iterator> itVector;
            for (auto arrKeyElement = s1ElementMap.begin(); arrKeyElement != s1ElementMap.end(); ++arrKeyElement)
                itVector.emplace_back(arrKeyElement);

            for (auto& it : itVector)
            {
                for (const auto& startIndex : it->second)
                {
                    auto keyVector = it->first;
                    if (startIndex + compareSize <= s1.size())
                        keyVector[s1[startIndex + compareSize - 1] - 'a']++;
                    s1ElementMap[keyVector].insert(startIndex);
                }
                s1ElementMap.erase(it);
            }
            
        }

        //2. s2ElementList + matching Phase
        if (compareSize == 1)
        {
            for (int s2Index = 0; s2Index < s2.size(); s2Index++)
            {
                Element arr = {0, };
                arr[s2[s2Index] - 'a']++;
                s2ElementList.emplace_back(arr);

                if (s1ElementMap.find(arr) != s1ElementMap.end())
                    result = max(result, compareSize);
            }
        } else {
            for (int s2Index = 0; s2Index + compareSize <= s2.size(); s2Index++)
            {
                s2ElementList[s2Index][s2[s2Index + compareSize - 1] - 'a']++;
                if (s1ElementMap.find(s2ElementList[s2Index]) != s1ElementMap.end())
                    result = max(result, compareSize);
            }
        }

    }
    
    cout << result;
}