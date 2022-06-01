//https://www.acmicpc.net/problem/11728

/*배열 합치기
이미 정렬되어 있는 2개의 배열이 주어질 때,
이 두 배열을 합친 후 정렬한 결과를 출력하세요.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arr1Length, arr2Length;
    cin >> arr1Length >> arr2Length;

    vector<int> arr1(arr1Length), arr2(arr2Length);

    for (int i = 0; i < arr1Length; i++)
        cin >> arr1[i];
    
    for (int i = 0; i < arr2Length; i++)
        cin >> arr2[i];

    auto arr1_iterator = arr1.begin();
    auto arr2_iterator = arr2.begin();

    while (arr1_iterator != arr1.end() && arr2_iterator != arr2.end())
    {
        if (*arr1_iterator < *arr2_iterator)
        {
            cout << *arr1_iterator << " ";
            arr1_iterator++;
        }
        else
        {
            cout << *arr2_iterator << " ";
            arr2_iterator++;
        }
    }

    while (arr1_iterator != arr1.end())
        cout << *arr1_iterator++ << " ";

    while (arr2_iterator != arr2.end())
        cout << *arr2_iterator++ << " ";


	
	return 0;
}