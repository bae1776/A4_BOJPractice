//https://www.acmicpc.net/problem/2504

//괄호의 값
//올바른 괄호 스택 응용문제


#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

void merge_stack(stack<pair<int, int>>& num_stack);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string bracket_string;
	cin >> bracket_string;

	int totalValue = 0;
	bool is_valid_str = true;
	stack<int> bracket_stack;
	stack<pair<int, int>> num_stack;
	
	
	for (char ch : bracket_string)
	{
		switch (ch)
		{
		case '(':
			bracket_stack.push('(');
			break;
		case '[':
			bracket_stack.push('[');
			break;
		case ')':
			if (!bracket_stack.empty() && bracket_stack.top() == '(')
			{
				num_stack.emplace((int)bracket_stack.size(), 2);
				bracket_stack.pop();
			}
			else {
				is_valid_str = false;
				break;
			}
			break;
		case ']':
			if (!bracket_stack.empty() && bracket_stack.top() == '[')
			{
				num_stack.emplace((int)bracket_stack.size(), 3);
				bracket_stack.pop();
			}
			else {
				is_valid_str = false;
				break;
			}
			break;
			
		}

		merge_stack(num_stack);
		
		if (is_valid_str == false)
			break;
	}

	if (bracket_stack.empty() && is_valid_str == true)
		cout << num_stack.top().second;
	else
		cout << 0;
	

	return 0;
}


void merge_stack(stack<pair<int, int>>& num_stack)
{
	while (num_stack.size() >= 2)
	{
		auto first_pop = num_stack.top();
		num_stack.pop();
		auto second_pop = num_stack.top();
		num_stack.pop();

		if (first_pop.first + 1 == second_pop.first) //multiple
			num_stack.emplace(first_pop.first, first_pop.second * second_pop.second);
		else if (first_pop.first == second_pop.first) //add
			num_stack.emplace(first_pop.first, first_pop.second + second_pop.second);
		else
		{
			num_stack.push(second_pop);
			num_stack.push(first_pop);
			return;
		}
	}
}