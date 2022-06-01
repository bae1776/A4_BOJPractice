//https://www.acmicpc.net/problem/10815

/* 숫자 카드
* 상근이는 정수가 적힌 숫자 카드를 N개 가지고 있다. (최대 50만개)
* 카드끼리 숫자가 같은 경우는 없다.
* 그리고 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야할 M개의 정수가 주어진다. (최대 50만개)
* 상근이가 가지고 있는 카드이면 1 아니면 0을 출력한다.
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
	//기수 별로 해싱
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
