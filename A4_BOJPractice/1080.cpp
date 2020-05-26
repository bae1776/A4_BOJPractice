//https://www.acmicpc.net/problem/1080

//���
//0�� 1�θ����� �̷���� ��� A�� ��� B�� �ִ�. �̶� ��� A�� ��� B�� �ٲٴµ� �ʿ��� ������ Ƚ���� �ּڰ���?
//����� ��ȯ�ϴ� ������ � 3*3 ũ���� �κ���Ŀ� �ִ� ��� ���Ҹ� ������ ���̴�.
//(3*3���� ���� ����� ������ �� ����.)

char** beforeMat;
char** afterMat;


#include <iostream>
using namespace std;


void flip3x3(int row, int col);


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int row, col;
	cin >> row >> col;

	beforeMat = new char* [row];
	afterMat = new char* [row];

	for (int i = 0; i < row; i++)
	{
		beforeMat[i] = new char[col + 1];
		afterMat[i] = new char[col + 1];
		cin >> beforeMat[i];
	}

	for (int i = 0; i < row; i++)
		cin >> afterMat[i];



	int flipCount = 0;

	for (int i = 0; i <= row - 3; i++)
	{
		for (int j = 0; j <= col - 3; j++)
		{
			if (beforeMat[i][j] != afterMat[i][j])
			{
				flip3x3(i, j);
				flipCount++;
			}
		}
	}
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (beforeMat[i][j] != afterMat[i][j])
			{
				flipCount = -1;
				break;
			}
		}
		if (flipCount == -1) break;
	}
	

	cout << flipCount;


	for (int i = 0; i < row; i++)
	{
		delete[] beforeMat[i];
		delete[] afterMat[i];
	}
	delete[] beforeMat;
	delete[] afterMat;

	return 0;
}



void flip3x3(int row, int col)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			char& target = beforeMat[row + i][col + j];
			switch (target)
			{
			case '0':
				target = '1';
				break;
			case '1':
				target = '0';
			}
		}
}