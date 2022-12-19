//https://www.acmicpc.net/problem/2162

/*선분 그룹 (Platinum 5)


Solution :
UnionFind + https://rebro.kr/10 (CCW 알고리즘 - 외적 공식 활용)

*/


#include <iostream>
#include <vector>
using namespace std;
using Line = pair<pair<int, int>, pair<int, int>>;
int parent[3002], nRank[3002], rootCount[3002];

int ccw(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c);
int union_find(const int& index);
void union_merge(const int& a, const int& b);



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int lineCount;
	cin >> lineCount;

	vector<Line> lineList;
	lineList.reserve(lineCount);

	for (int i = 0; i < lineCount; i++)
	{
		parent[i] = i;
		nRank[i] = 1;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lineList.emplace_back(make_pair(x1, y1), make_pair(x2, y2));
	}

	for (int firstLine = 0; firstLine < lineCount; ++firstLine)
		for (int secondLine = firstLine + 1; secondLine < lineCount; ++secondLine)
		{
			if (union_find(firstLine) != union_find(secondLine))
			{
				const Line& a = lineList[firstLine];
				const Line& b = lineList[secondLine];

				int aTob1Rotation = ccw(a.first, b.first, a.second);
				int aTob2Rotation = ccw(a.first, b.second, a.second);
				int bToa1Rotation = ccw(b.first, a.first, b.second);
				int bToa2Rotation = ccw(b.first, a.second, b.second);

				if (aTob1Rotation * aTob2Rotation <= 0)
				{
					if (aTob1Rotation == 0 && aTob2Rotation == 0)
					{ //두 선분이 같은 직선 상에 있는 경우
						if (a.first.first != a.second.first) // a 선분이 y축과 평행하지 않은 경우 (b 선분 포함)
						{
							const int& aXMin = min(a.first.first, a.second.first);
							const int& bXMin = min(b.first.first, b.second.first);

							if (aXMin <= bXMin)
							{
								if (bXMin <= max(a.first.first, a.second.first))
									union_merge(firstLine, secondLine);
							}
							else
								if (aXMin <= max(b.first.first, b.second.first))
									union_merge(firstLine, secondLine);
						}
						else { //a, b 선분이 y축과 평행한 경우
							const int& aYMin = min(a.first.second, a.second.second);
							const int& bYMin = min(b.first.second, b.second.second);

							if (aYMin <= bYMin)
							{
								if (bYMin <= max(a.first.second, a.second.second))
									union_merge(firstLine, secondLine);
							}
							else
								if (aYMin <= max(b.first.second, b.second.second))
									union_merge(firstLine, secondLine);
						}
					}
					else {
						if (bToa1Rotation * bToa2Rotation <= 0)
							union_merge(firstLine, secondLine);
					}
				}
				
			}
		}
	
	for (int i = 0; i < lineCount; i++)
		rootCount[union_find(i)]++;
	
	int groupCount = 0, maxGroupSize = 0;
	for (int i = 0; i < lineCount; i++)
	{
		if (rootCount[i])
		{
			groupCount++;
			maxGroupSize = max(maxGroupSize, rootCount[i]);
		}
	}

	cout << groupCount << '\n' << maxGroupSize;


	return 0;
}




int ccw(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c)
{
	int value = a.first * b.second + b.first * c.second + c.first * a.second
		- b.first * a.second - c.first * b.second - a.first * c.second;

	if (value > 0) return 1;
	else if (value < 0) return -1;
	else return 0;
}

int union_find(const int& index)
{
	if (parent[index] == index)
		return index;
	else
		return parent[index] = union_find(parent[index]);
}

void union_merge(const int& a, const int& b)
{
	int pa = union_find(a);
	int pb = union_find(b);

	if (nRank[pa] < nRank[pb])
		parent[pb] = pa;
	else if (nRank[pa] > nRank[pb])
		parent[pa] = pb;
	else
	{
		parent[pa] = pb;
		nRank[pb]++;
	}

}