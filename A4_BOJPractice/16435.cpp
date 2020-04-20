//https://www.acmicpc.net/problem/16435

//������ũ������ �ֿ� ���̴� �����̸� ���� �ϳ��� ������ ���̰� 1��ŭ �þ�ϴ�.
//���ϵ��� �������κ��� ���� ���̸� �ΰ� ������ ������ i(1 �� i �� N) ��° ������ ���̴� hi�Դϴ�.
//������ũ����� �ڽ��� ���̺��� �۰ų� ���� ���̿� �ִ� ���ϵ��� ���� �� �ֽ��ϴ�.
//������ũ������ ó�� ���̰� L�϶� ���ϵ��� �Ծ� �ø� �� �ִ� �ִ� ���̸� ���ϼ���.


#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int fruitCount, length;
	cin >> fruitCount >> length;

	int* fruit_heightList = new int[fruitCount];
	
	for (int i = 0; i < fruitCount; i++)
	{
		cin >> fruit_heightList[i];
	}

	sort(fruit_heightList, fruit_heightList + fruitCount);


	for (int i = 0; i < fruitCount; i++)
	{
		if (fruit_heightList[i] <= length)
			length++;
		else
			break;
	}

	
	cout << length;


	delete[] fruit_heightList;
	
	return 0;
}