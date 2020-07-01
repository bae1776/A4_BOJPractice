//https://www.acmicpc.net/problem/1526

//���� ū �ݹμ�
//N (<=1000000)�� �־��� ��, N���� �۰ų� ���� �ݹμ� ��
//���� ū ���� ����Ͻÿ�.
//�ݹμ��� 4�� 7�θ� �̷���� �ڿ����� ���Ѵ�.

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	while (true)
	{
		int target = num;
		bool flag = false;
		while (true)
		{
			if (target == 0)
			{
				flag = true;
				break;
			}
			int digit = target % 10;
			if (digit == 4 || digit == 7)
				target /= 10;
			else
				break;
		}
		
		if (flag == true)
			break;
		
		num--;
	}

	cout << num;
	
	return 0;
}