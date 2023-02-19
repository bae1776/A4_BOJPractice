//https://www.acmicpc.net/problem/15904

/* UCPC는 무엇의 약자일까? (Silver 5)

Solution : 문자열 선형 탐색
*/


#include <iostream>
using namespace std;
char input[1004];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin.getline(input, 1001);

    int state = 0;
    int index = 0;

    while (input[index] != '\0')
    {
        switch (state)
        {
            case 0:
                if (input[index] == 'U')
                    state = 1;
                break;
            case 1:
                if (input[index] == 'C')
                    state = 2;
                break;
            case 2:
                if (input[index] == 'P')
                    state = 3;
                break;
            case 3:
                if (input[index] == 'C')
                    state = 4;
                break;
        }

        index++;
    }

    if (state == 4)
        cout << "I love UCPC";
    else 
        cout << "I hate UCPC";
    


	return 0;
}


