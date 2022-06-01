//https://www.acmicpc.net/problem/10815

/* ���� ī��
* ����̴� ������ ���� ���� ī�带 N�� ������ �ִ�. (�ִ� 50����)
* ī�峢�� ���ڰ� ���� ���� ����.
* �׸��� ����̰� ������ �ִ� ���� ī������ �ƴ����� ���ؾ��� M���� ������ �־�����. (�ִ� 50����)
* ����̰� ������ �ִ� ī���̸� 1 �ƴϸ� 0�� ����Ѵ�.
*/


#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	bool isMine;
	vector<Node*> leafList;

	Node() : isMine(false), leafList(10, nullptr) {};
};

Node tree;

int main(void)
{
	//��� ���� �ؽ�
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int myCard, suggestedCount;
	cin >> myCard;

	while (myCard--)
	{
		int input;
		cin >> input;

		if (input < 0)
			input += 20000001;

		Node* inputLocation = &tree;
		while (input)
		{
			int nextIndex = input % 10;

			if (inputLocation->leafList[nextIndex] == nullptr)
				inputLocation->leafList[nextIndex] = new Node();

			inputLocation = inputLocation->leafList[nextIndex];

			input /= 10;
		}

		inputLocation->isMine = true;
	}

	cin >> suggestedCount;

	while (suggestedCount--)
	{
		int input;
		cin >> input;

		if (input < 0)
			input += 20000001;

		Node* inputLocation = &tree;
		while (input)
		{
			int nextIndex = input % 10;
			

			if (inputLocation->leafList[nextIndex] == nullptr)
				break;

			inputLocation = inputLocation->leafList[nextIndex];
			input /= 10;
		}

		if (input == 0 && inputLocation->isMine == true)
			cout << "1 ";
		else
			cout << "0 ";
	}


	return 0;
}
