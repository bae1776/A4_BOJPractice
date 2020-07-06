//https://www.acmicpc.net/problem/14500

//��Ʈ�ι̳�
//N x M ������ ĭ�� ���� ���ڰ� �Ű��� �ִ�.
//��Ʈ���� ���� �� �� �η��� �ϴµ�, �� ���� ä�� ĭ�� ���ڵ� ���� �ִ밡 �ǰ� �� ����
//�� ���� ����Ͻÿ�.

#include <iostream>
using namespace std;


int getMax(int target, int nums[], int count);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int row, col;
	cin >> row >> col;

	int** block = new int* [row];
	for (int i = 0; i < row; i++)
	{
		block[i] = new int[col];
		for (int j = 0; j < col; j++)
			cin >> block[i][j];
	}


	int max = 0;

	//0000
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - 3; j++)
		{
			int sum = block[i][j] + block[i][j + 1] + block[i][j + 2] + block[i][j + 3];
			if (sum > max)
				max = sum;
		}
	}

	//0		000		000		  0		00		 00    000		 0
	//000	  0		0		000		 00		00		0		000
	for (int i = 0; i < row - 1; i++)
		for (int j = 0; j < col - 2; j++)
		{
			int sum[8] = {
				block[i][j] + block[i + 1][j] + block[i + 1][j + 1] + block[i + 1][j + 2],
				block[i][j] + block[i][j + 1] + block[i][j + 2] + block[i + 1][j + 2],
				block[i][j] + block[i][j + 1] + block[i][j + 2] + block[i + 1][j],
				block[i][j+2] + block[i + 1][j] + block[i + 1][j + 1] + block[i + 1][j + 2],
				block[i][j] + block[i][j + 1] + block[i + 1][j + 1] + block[i + 1][j + 2],
				block[i + 1][j] + block[i + 1][j + 1] + block[i][j + 1] + block[i][j + 2],
				block[i][j] + block[i][j + 1] + block[i][j + 2] + block[i + 1][j + 1],
				block[i][j+1] + block[i + 1][j] + block[i + 1][j + 1] + block[i + 1][j + 2],
			};
			max = getMax(max, sum, 8);
		}


	//00
	//00
	for (int i = 0; i < row - 1; i++)
		for (int j = 0; j < col - 1; j++)
		{
			int sum = block[i][j] + block[i][j + 1] + block[i + 1][j] + block[i + 1][j + 1];
			if (sum > max)
				max = sum;
		}

	//00   00	0	 0	0	 0	0	 0
	//0		0	0	 0	00	00	00	00
	//0		0	00	00	0	 0	 0	0

	for (int i = 0; i < row - 2; i++)
		for (int j = 0; j < col - 1; j++)
		{
			int sum[8] = {
				block[i][j] + block[i][j + 1] + block[i + 1][j] + block[i + 2][j],
				block[i][j] + block[i][j + 1] + block[i + 1][j + 1] + block[i + 2][j + 1],
				block[i][j] + block[i + 2][j + 1] + block[i + 1][j] + block[i + 2][j],
				block[i + 2][j] + block[i][j + 1] + block[i + 1][j + 1] + block[i + 2][j + 1],
				block[i][j] + block[i + 1][j + 1] + block[i + 1][j] + block[i + 2][j],
				block[i + 1][j] + block[i][j + 1] + block[i + 1][j + 1] + block[i + 2][j + 1],
				block[i][j] + block[i + 1][j] + block[i + 1][j + 1] + block[i + 2][j + 1],
				block[i][j + 1] + block[i + 1][j] + block[i + 1][j + 1] + block[i + 2][j]
			};

			max = getMax(max, sum, 8);
		}

	//0
	//0
	//0
	//0

	for (int i = 0; i < row - 3; i++)
		for (int j = 0; j < col; j++)
		{
			int sum = block[i][j] + block[i + 1][j] + block[i + 2][j] + block[i + 3][j];
			if (sum > max)
				max = sum;
		}


	cout << max;

	for (int i = 0; i < row; i++)
		delete[] block[i];
	delete[] block;

	return 0;
}





int getMax(int target, int nums[], int count)
{
	for (int i = 0; i < count; i++)
		if (nums[i] > target)
			target = nums[i];
		
	return target;
}
