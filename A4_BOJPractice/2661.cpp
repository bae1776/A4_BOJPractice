//https://www.acmicpc.net/problem/2661

//���� ����

//���� 1, 2, 3���θ� �̷������ ������ �ִ�.
//������ ������ ������ �� ���� �κ� ������ ������ ���� ������, 
//�� ������ ���� �����̶�� �θ���. �׷��� ���� ������ ���� �����̴�.

//������ ���� ������ ���̴�   -  33, 32121323, 123123213
//������ ���� ������ ���̴�.  -  2, 32, 32123, 1232123

//�ڸ� ���� �־����� ��, �ش� �ڸ� ������ ���� ���� ���� ���� ���� ����Ͻÿ�.

#include <iostream>
#include <cstring>
using namespace std;




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int digit;
	cin >> digit;
	char goodSequence[100];
	memset(goodSequence, '0', sizeof(goodSequence));

	goodSequence[0] = '1';
	int depth = 1;
	while (depth < digit)
	{
		if (goodSequence[depth] == '3')
		{
			goodSequence[depth] = '0';
			depth--;
			continue;
		}
		goodSequence[depth] += 1;
		const int half = (depth + 1) / 2;
		char* lastSeq = goodSequence + depth;
		int i;
		for (i = 0; i <= half; i++)
		{
			if (strncmp(lastSeq - i * 2 - 1, lastSeq - i, i + 1) == 0)
				break;
			
		}
		if (i > half)
			depth++;
	}

	goodSequence[digit] = '\0';
	cout << goodSequence;



	return 0;
}
