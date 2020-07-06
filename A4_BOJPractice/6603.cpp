//https://www.acmicpc.net/problem/6603

//로또
//수가 6~13개 주어지고,
//그 중에서 로또 숫자 6개를 뽑을 때 가능한 모든 경우를 출력하시오.

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int numCount;
	cin >> numCount;
	int arr[13];

	while (numCount != 0)
	{
		for (int i = 0; i < numCount; i++)
			cin >> arr[i];

		int lottoIdx[6];
		for (lottoIdx[0] = 0; lottoIdx[0] <= numCount - 6; lottoIdx[0]++)
			for (lottoIdx[1] = lottoIdx[0] + 1; lottoIdx[1] <= numCount - 5; lottoIdx[1]++)
				for (lottoIdx[2] = lottoIdx[1] + 1; lottoIdx[2] <= numCount - 4; lottoIdx[2]++)
					for (lottoIdx[3] = lottoIdx[2] + 1; lottoIdx[3] <= numCount - 3; lottoIdx[3]++)
						for (lottoIdx[4] = lottoIdx[3] + 1; lottoIdx[4] <= numCount - 2; lottoIdx[4]++)
							for (lottoIdx[5] = lottoIdx[4] + 1; lottoIdx[5] <= numCount - 1; lottoIdx[5]++)
							{
								for (int i = 0; i < 6; i++)
									cout << arr[lottoIdx[i]] << ' ';
								cout << '\n';
							}
		cout << '\n';

		cin >> numCount;
	}


	return 0;
}