//https://www.acmicpc.net/problem/16440

/*제이크와 케이크

사각 케이크에는 가로로 N개의 과일 조각이 올려져 있습니다. (N은 4의 배수)
이때 N/2개는 딸기, N/2개는 키위입니다.

제이크는 케이크를 잘라서 두 사람에게 과일 조각을 딱 반반씩 주려고 합니다.
즉, 한 사람에게 딸기 N/4, 키위 N/4개를 줄 수 있게 자르고 싶습니다.

제이크는 귀찮아서 케이크를 최소한으로 자르고 싶어합니다.
이때 케이크를 잘라야 하는 최소 횟수와 자르는 위치를 오름차순으로 출력하세요.

*/

#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int cakeLength; 
    string cake;
    cin >> cakeLength;
    cin >> cake;

    int halfCutEnd = cakeLength / 2;
    const int half = halfCutEnd;
    pair<int, int> halfCutFruits = {0, 0};

    for (int i = 0; i < halfCutEnd; i++)
    {
        if (cake[i] == 's')
            ++(halfCutFruits.first);
        else
            ++(halfCutFruits.second);
    }

    while (halfCutFruits.first != halfCutFruits.second)
    { //partSum : sliding window
        if (cake[halfCutEnd - half] == 's')
            --(halfCutFruits.first);
        else
            --(halfCutFruits.second);

        if (halfCutEnd == cakeLength - 1)
            return 0;

        if (cake[halfCutEnd++] == 's')
            ++(halfCutFruits.first);
        else
            ++(halfCutFruits.second);
    }


    if (halfCutEnd - half == 0)
        cout << 1 << '\n' << halfCutEnd;
    else
        cout << 2 << '\n' << halfCutEnd - half << ' ' << halfCutEnd;
    
    return 0;

}