//https://www.acmicpc.net/problem/1904

//수열의 길이가 주어질 때, 00 타일과 1 타일로 만들 수 있는 서로 다른 수열의 갯수 % 15746을 구하시오.
//타일은 충분히 많은 것으로 간주하자.
//예를 들어 수열 길이가 4면, 0011, 0000, 1001, 1100, 1111 총 5개를 만들 수 있다.

#include <iostream>
using namespace std;

int DP[1000001];


int number_of_tiles(int len)
{
	if (DP[len] != 0) return DP[len];

	if (len <= 2) return DP[len] = len;
	return DP[len] = (number_of_tiles(len - 1) + number_of_tiles(len - 2)) % 15746;
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int length;
	cin >> length;


	cout << number_of_tiles(length) << '\n';


	return 0;
}