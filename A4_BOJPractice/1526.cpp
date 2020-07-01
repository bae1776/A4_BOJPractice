//https://www.acmicpc.net/problem/1526

//가장 큰 금민수
//N (<=1000000)이 주어질 때, N보다 작거나 같은 금민수 중
//가장 큰 수를 출력하시오.
//금민수란 4와 7로만 이루어진 자연수를 말한다.

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