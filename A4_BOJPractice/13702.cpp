//https://www.acmicpc.net/problem/13702

//이상한 술집
//N개 주전자에 담긴 술의 양이 주어질 때, K명에게 공평하게 나누어 주려고 한다.
//서로 다른 주전자의 술이 섞이는 건 원치 않기 때문에, 나누어 주고 주전자에 남은 술은 다른 주전자에 합치지 않고 버린다.
//최대 몇 ml까지 줄 수 있을까?

#include <iostream>
#include <vector>
using namespace std;


long long divide_beberage(const vector<int> Beberages, int per);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int pot, people;
	cin >> pot >> people;

	vector<int> potBeberage(pot);
	
	for (int i = 0; i < pot; i++)
		cin >> potBeberage[i];


	unsigned int left = 0;
	unsigned int right = 0x7FFFFFFF;
	unsigned int middle;

	while (left <= right)
	{
		middle = (left + right) / 2;
		
		long long result = divide_beberage(potBeberage, middle);

		if (result >= people)
			left = middle + 1;
		else
			right = middle - 1;
	}

	cout << right;



	return 0;
}


long long divide_beberage(const vector<int> Beberages, int per)
{
	if (per == 0) return 0x7FFFFFFFFFFFFFFF;

	long long int result = 0;
	for (auto i = Beberages.begin(); i != Beberages.end(); ++i)
	{
		result += (*i) / per;
	}

	return result;
}