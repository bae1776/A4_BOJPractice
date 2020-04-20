//https://www.acmicpc.net/problem/11718

//입력 받은 그대로 출력하기

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	while (getline(cin, str)) //string 한 줄 입력
	{
		cout << str << '\n';
	}


	return 0;
}