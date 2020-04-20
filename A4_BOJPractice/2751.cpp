//https://www.acmicpc.net/problem/2751

//�鸸�� ���� ����

#include <iostream>
#include <algorithm>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int arrsize;
	cin >> arrsize;

	int* arr = new int[arrsize];

	for (int i = 0; i < arrsize; ++i)
		cin >> arr[i];


	sort(arr, arr + arrsize);


	for (int i = 0; i < arrsize; ++i)
		cout << arr[i] << '\n';


	delete[] arr;
	

	return 0;
}

