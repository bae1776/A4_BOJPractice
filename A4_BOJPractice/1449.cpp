//https://www.acmicpc.net/problem/1449

//������

//����ö ���� �������� ���� ����, �������� �⵿�ߴ�.
//���������� ���� ���� ���� �ű��ϰԵ� ���� ���ʿ��� ������ŭ ������ �Ÿ��� ���� ���ٰ� �Ѵ�.

//�������� ���̰� L�� �������� ���Ѱ� ���ϰ� �ְ�, �� �������� ���� �������Ѵ�.
//�������� ���۳� ��ġ���� �¿� 0.5 ������ ��� �ٽô� ���� ���� ���̶�� �����Ѵ�.

//���� ���� �� ��ġ, L�� �־����� �� �������� �ּ� ������?

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int holeCount, typeLength;
	cin >> holeCount >> typeLength;

	vector<int> holeLocation;
	holeLocation.reserve(holeCount);

	int input;
	for (int i = 0; i < holeCount; i++)
	{
		cin >> input;
		holeLocation.emplace_back(input);
	}

	sort(holeLocation.begin(), holeLocation.end());

	int typingIndex = 0;
	int typeCount = 0;

	do {
		int layered = typingIndex;

		while (layered < holeCount - 1 && holeLocation[layered + 1] - holeLocation[typingIndex] < typeLength)
			layered++;

		typeCount++;
		typingIndex = layered + 1;
	} while (typingIndex < holeCount);


	cout << typeCount;
	
	return 0;
}


