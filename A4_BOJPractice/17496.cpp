//https://www.acmicpc.net/problem/17496

/*스타후르츠
대회 링크 : https://www.acmicpc.net/category/detail/2062
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int totalDay, perDay, size, price;
	cin >> totalDay >> perDay >> size >> price;

	int totalFruits = (totalDay - 1) / perDay * size;

	cout << totalFruits * price;


	return 0;
}