//https://www.acmicpc.net/problem/2879

//코딩은 예쁘게
//각 코드 라인의 인덴트를 목표 상태로 다듬는 작업을 할때 필요한 최소한의 인덴트 작업 횟수를 구하시오.
//인덴트 작업은 연속된 줄을 한번에 인덴트를 한 칸씩 증감하는 것도 1회로 간주하지만, 
//인덴트가 없는 줄을 묶어서 인덴트를 감소 시키는 것은 불가능하다.

#include <iostream>
#include <vector>
using namespace std;
using State = enum { UNDER, EQUAL, ABOVE };

int indentation(vector<int>& indentList, int start, const int& end, const State& state);
void stateUpdate(vector<State>& indentState, const vector<int>& nowIndentList, const vector<int>& targetIndentList, int start, int end);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int line;
	cin >> line;

	vector<int> nowIndentList(line);
	vector<int> targetIndentList(line);
	vector<State> indentState(line);

	for (int& nowIndent_input : nowIndentList)
		cin >> nowIndent_input;
	
	for (int& targetIndent_input : targetIndentList)
		cin >> targetIndent_input;
	
	stateUpdate(indentState, nowIndentList, targetIndentList, 0, line);


	int indent_number = 0;
	auto indented_start = indentState.begin();
	auto indented_end = indentState.begin();
	State series_state = *indented_start;

	while (true)
	{
		if (indented_end == indentState.end())
			if (indented_start == indented_end)
				break;
			else
			{
				int indent_startIndex = indented_start - indentState.begin();
				int indent_endIndex = indented_end - indentState.begin();

				indented_start = indented_end = 
					indentState.begin() + indentation(nowIndentList, indent_startIndex, indent_endIndex, series_state);
				if (series_state != EQUAL)
				{
					indent_number++;
					stateUpdate(indentState, nowIndentList, targetIndentList, indent_startIndex, indent_endIndex);
				}
			}
		else 
		{
			if (indented_start == indented_end)
				if (*indented_start == EQUAL)
				{
					indented_start++;
					indented_end++;
				} else {
					series_state = *indented_start;
					indented_end++;
				}
			else if (series_state == *indented_end)
				indented_end++;
			else {
				int indent_startIndex = indented_start - indentState.begin();
				int indent_endIndex = indented_end - indentState.begin();

				indented_start = indented_end =  
					indentState.begin() + indentation(nowIndentList, indent_startIndex, indent_endIndex, series_state);
				

				indent_number++;
				stateUpdate(indentState, nowIndentList, targetIndentList, indent_startIndex, indent_endIndex);
			}
		}
	}

	cout << indent_number;

	return 0;
}


int indentation(vector<int>& indentList, int start, const int& end, const State& state)
{
	if (state == EQUAL)
		return end;
	else if (state == UNDER)
		for (int i = start; i < end; i++)
			indentList[i]++;
	else
		for (int i =  start; i < end; i++)
			indentList[i]--;

	return start;

}


void stateUpdate(vector<State>& indentState, const vector<int>& nowIndentList, const vector<int>& targetIndentList, int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		if (nowIndentList[i] < targetIndentList[i])
			indentState[i] = UNDER;
		else if (nowIndentList[i] == targetIndentList[i])
			indentState[i] = EQUAL;
		else
			indentState[i] = ABOVE;
	}
}