//https://www.acmicpc.net/problem/1049

//��Ÿ��
//��Ÿ���� N���� ���� �������� ���ο� ���� �缭 ��ü�ؾ� �Ѵ�.
//M���� ��Ÿ�� �귣�忡�� 6�� ��Ű�� Ȥ�� ���� �ٷ� ��Ÿ���� �Ǹ��Ѵ�.

//�� ��Ÿ�� �귣���� 6�� ��Ű���� ���� ������ �־�����,
//�ǵ����̸� ���� ���� ������ �Ҷ�, �ݾ� �ּҸ� ���Ͻÿ�.


#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int required, brand;
	cin >> required >> brand;

	int minPackage = 0x7FFFFFFF;
	int minUnit = 0x7FFFFFFF;


	for (int i = 0; i < brand; i++)
	{
		int packagePrice, unitPrice;
		cin >> packagePrice >> unitPrice;

		if (packagePrice < minPackage) minPackage = packagePrice;
		if (unitPrice < minUnit) minUnit = unitPrice;
	}


	int result = (required / 6) * min(minPackage, minUnit * 6)
			   + min(minPackage, minUnit * (required % 6));


	cout << result;



	return 0;
}