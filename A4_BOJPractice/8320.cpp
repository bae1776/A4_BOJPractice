//https://www.acmicpc.net/problem/8320

//���簢���� ����� ���
//���̰� 1�� ���簢���� n�� ���� ��, ���� �ٸ� ���簢���� �� ���� ���� �� ������?

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int unitSquare;
	cin >> unitSquare;

	int total = 0;

	for (int row = 1; row * row <= unitSquare; row++)
		total += unitSquare / row - (row - 1);
	
	cout << total;


	return 0;
}