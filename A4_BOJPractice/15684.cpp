//https://www.acmicpc.net/problem/15684

//사다리 조작
//사다리 타기 게임에서, i번째 줄에서 시작했을 때 i번째 줄에서 끝나도록
//가로선을 추가하려고 할 때, 최소한 추가해야 할 가로선 개수를 구하시오.
//단, 가로선을 추가하여도 불가능 하거나, 3개 넘게 가로선을 그어야 하는 경우 그냥 -1 출력하시오.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int vertLine, horiLine_count, horiLine_max;


int get_vertLine_count(vector<vector<bool>>& horiLine_list);
int get_ladderGame_result(int startLine, const vector<vector<bool>>& horiLine_list);
bool next_perm(int max_perm, int perm_length, vector<int>& now_permList);


int main(void)
{
	cin >> vertLine >> horiLine_count >> horiLine_max;

	vector<vector<bool>> horiLine_list
		(horiLine_max + 1, vector<bool>(vertLine + 1, false));


	for (int i = 0; i < horiLine_count; i++)
	{
		int y, x;
		cin >> y >> x;

		horiLine_list[y][x] = true;
	}


	int result = get_vertLine_count(horiLine_list);
	cout << result;

	
	return 0;
}



int get_vertLine_count(vector<vector<bool>>& horiLine_list)
{
	//1. get Available horiLine List
	vector<pair<int, int>> horiLine_candidates;
	
	for (int i = 1; i <= horiLine_max; i++)
		for (int j = 1; j < vertLine; j++)
		{
			if (horiLine_list[i][j - 1]== true)
				continue;
			if (horiLine_list[i][j] == true)
				continue;
			horiLine_candidates.emplace_back(i, j);
		}

	//2. trying can be promised
	int add_horiCount;
	for (add_horiCount = 0; add_horiCount <= 3; add_horiCount++)
	{
		if (add_horiCount > horiLine_candidates.size())
			return -1;
		
		vector<int> attempting_horiLine_index;
		for (int i = 0; i < add_horiCount; i++)
			attempting_horiLine_index.push_back(i);

		do {
			//- add candidates temperary
			for (int pairIndex : attempting_horiLine_index)
			{
				const pair<int, int>& candidate_coord = horiLine_candidates[pairIndex];
				horiLine_list[candidate_coord.first][candidate_coord.second] = true;
			}

			int success;
			for (success = 1; success <= vertLine; success++)
			{
				if (success != get_ladderGame_result(success, horiLine_list))
					break;
			}
			if (success > vertLine)
				return add_horiCount; //succeed


			//- Fail -> delete candidates
			for (int pairIndex : attempting_horiLine_index)
			{
				const pair<int, int>& candidate_coord = horiLine_candidates[pairIndex];
				horiLine_list[candidate_coord.first][candidate_coord.second] = false;
			}
		} while (next_perm(horiLine_candidates.size(), add_horiCount, attempting_horiLine_index));
	}

	
	return -1;
	//All candidates Failed
}




int get_ladderGame_result(int startLine, const vector<vector<bool>>& horiLine_list)
{
	for (int i = 1; i <= horiLine_max; i++)
	{
		if (horiLine_list[i][startLine - 1] == true)
		{
			startLine--;  //leftMove
			continue;
		}
		if (horiLine_list[i][startLine] == true)
			startLine++;  //rightMove
	}

	return startLine;
}



bool next_perm(int max_perm/*less than, not equal*/, int perm_length, vector<int>& now_permList)
{
	if (perm_length == 0)
		return false;

	const int lastIndex = perm_length - 1;
	now_permList[lastIndex] += 1;

	int depth = 0;
	while (now_permList[lastIndex - depth] >= max_perm - depth)
	{
		if (lastIndex - depth == 0)
			return false; //already reached last permutation.
		else
		{
			now_permList[lastIndex - depth - 1] += 1;
			for (int i = 0; i <= depth; i++)
				now_permList[lastIndex - depth + i] = now_permList[lastIndex - depth + i - 1] + 1;
			depth++;
		}
	}

	return true;
}
