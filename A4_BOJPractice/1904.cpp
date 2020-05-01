//https://www.acmicpc.net/problem/1904

//������ ���̰� �־��� ��, 00 Ÿ�ϰ� 1 Ÿ�Ϸ� ���� �� �ִ� ���� �ٸ� ������ ���� % 15746�� ���Ͻÿ�.
//Ÿ���� ����� ���� ������ ��������.
//���� ��� ���� ���̰� 4��, 0011, 0000, 1001, 1100, 1111 �� 5���� ���� �� �ִ�.

#include <iostream>
using namespace std;

int DP[1000001];


int number_of_tiles(int len)
{
	if (DP[len] != 0) return DP[len];

	if (len <= 2) return DP[len] = len;
	return DP[len] = (number_of_tiles(len - 1) + number_of_tiles(len - 2)) % 15746;
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int length;
	cin >> length;


	cout << number_of_tiles(length) << '\n';


	return 0;
}