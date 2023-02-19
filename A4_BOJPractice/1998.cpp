//https://www.acmicpc.net/problem/1998

/*이미지 압축 (Gold 1)

Solution : 완전 탐색
*/


#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, pair<int, int>> stringTree;
string picture;
int pictureLen = 1;
pair<string, pair<int, int>> nodeCountOfQuadTree(int length, int startIndex);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int y, x;
    cin >> y >> x;

    while (max(y, x) > pictureLen)
    {
        pictureLen <<= 1;
    }

    string input;
    picture.reserve(pictureLen * pictureLen);
    input.reserve(pictureLen);
    for (int i = 0; i < y; i++)
    {
        cin >> input;
        input.append(pictureLen - x, '0');
        picture.append(input);
    }

    input.clear();
    input.append(pictureLen, '0');
    for (int i = y; i < pictureLen; i++)
        picture.append(input);

    pair<int, int> result = nodeCountOfQuadTree(pictureLen, 0).second;
    cout << result.first << ' ' << result.second;

	return 0;
}


pair<string, pair<int, int>> nodeCountOfQuadTree(int length, int startIndex)
{
    if (length == 1)
    {   
        string singleStr;
        singleStr.push_back(picture[startIndex]);
        return {singleStr, {1, 1}};
    }
    else if (length == 2)
    {
        char segList[4] = { picture[startIndex],
            picture[startIndex + length / 2],
            picture[startIndex + (pictureLen * length / 2)],
            picture[startIndex + (pictureLen * length / 2) + length / 2]
        };

        string str;
        str.reserve(8);
        for (int i = 0; i < 4; i++)
        {
            str.push_back('A' + i);
            str.push_back(segList[i]);
        }

        if (str[1] == str[3] && str[3] == str[5] && str[5] == str[7])
        {
            str.clear();
            str.push_back(str[1]);
            return {str, {1, 1}};
        } else {
            return {str, {5, 5}};
        }

    } else {
        pair<string, pair<int, int>> segList[4] = {
            nodeCountOfQuadTree(length / 2, startIndex),
            nodeCountOfQuadTree(length / 2, startIndex + length / 2),
            nodeCountOfQuadTree(length / 2, startIndex + (pictureLen * length / 2)),
            nodeCountOfQuadTree(length / 2, startIndex + (pictureLen * length / 2) + length / 2)
        };

        string str;
        pair<int, int> quadNode = {1, 1};
        str.reserve(length * length + 4);
        for (int i = 0; i < 4; i++)
        {
            str.push_back('A' + i);
            str.append(segList[i].first);

            auto subQuadTree = stringTree.find(segList[i].first);
            if (subQuadTree == stringTree.end())
            {
                stringTree[segList[i].first] = segList[i].second;
                quadNode.first += segList[i].second.first;
                quadNode.second += segList[i].second.second;
            } else {
                if (subQuadTree->second.first == 1)
                {
                    quadNode.first += 1;
                    quadNode.second += 1;
                } else {
                    quadNode.first += segList[i].second.first;
                }
            }
        }

        if (str[1] == str[3] && str[3] == str[5] && str[5] == str[7])
        {
            str.clear();
            str.push_back(str[1]);
            return {str, {1, 1}};
        } else {
            return {str, quadNode};
        }
    }
}

