//https://www.acmicpc.net/problem/999 (문제 번호)

/*할리갈리

*/


#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cardCount;
    cin >> cardCount;

    int arr[4] = {0};
    string fruit;
    int count;
    for (int i = 0; i < cardCount; i++)
    {
        cin >> fruit >> count;

        switch (fruit[0])
        {
            case 'B':
                arr[0] += count;
                break;
            case 'S':
                arr[1] += count;
                break;
            case 'L':
                arr[2] += count;
                break;
            case 'P':
                arr[3] += count;
                break;
        }
    }

    int ring = false;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == 5)
            ring = true;
    }

    if (ring)
        cout << "YES";
    else
        cout << "NO";

	
	return 0;
}
