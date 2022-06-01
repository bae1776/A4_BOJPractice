//https://www.acmicpc.net/problem/1057

/* ��ʸ�Ʈ (Silver 3)

�������� N���� �����ϴ� ��ʸ�Ʈ�� �����ߴ�.
��ʸ�Ʈ�� ������ ���� 1~N���� �Űܼ� 1 vs 2 / 3 vs 4 ... �� ����� �Ͽ� �̱� ����
���� ���忡 �����ϰ� ��ȣ�� ó�� ��ȣ�� ������ �����ϸ� �ٽ� 1������ �ű��.
�׸��� ���� ���忡 Ȧ�� �ο��� �����ִٸ�, ������ ��ȣ�� �������Ѵ�.

��ħ �� ��ȸ�� ���Ѽ��� �����ϴµ�, ������, ���Ѽ��� ��� ��⿡�� �̱�ٰ� �����ϰ�
�� ���� ���� ������ ��ȣ�� �־��� �� �̵��� �� ���忡�� ���� �� ������ ���Ͻÿ�.

 
*/


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int participant, num1, num2;

	cin >> participant >> num1 >> num2;

	int round = 0;

	while (num1 != num2)
	{
		num1 = (num1 + 1) / 2;
		num2 = (num2 + 1) / 2;
		round++;
	}

	cout << round;

	return 0;
}
