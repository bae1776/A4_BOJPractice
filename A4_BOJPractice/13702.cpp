//https://www.acmicpc.net/problem/13702

//�̻��� ����
//N�� �����ڿ� ��� ���� ���� �־��� ��, K���� �����ϰ� ������ �ַ��� �Ѵ�.
//���� �ٸ� �������� ���� ���̴� �� ��ġ �ʱ� ������, ������ �ְ� �����ڿ� ���� ���� �ٸ� �����ڿ� ��ġ�� �ʰ� ������.
//�ִ� �� ml���� �� �� ������?

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