//https://www.acmicpc.net/problem/1076

/*저항 (Bronze 2)
*/


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long value = 0;
    char color[10];

    for (int i = 0; i < 3; i++)
    {
        cin >> color;

        if (i != 2)
        {
            switch (color[0])
            {
                case 'b':
                    if (color[1] == 'l')
                    {
                        if (color[2] == 'u')
                            value = value * 10 + 6;
                        else
                            value = value * 10;
                    }
                    else
                        value = value * 10 + 1;
                    break;

                case 'r':
                    value = value * 10 + 2;
                    break;

                case 'o':
                    value = value * 10 + 3;
                    break;
                
                case 'y':
                    value = value * 10 + 4;
                    break;

                case 'g':
                    if (color[3] == 'e')
                        value = value * 10 + 5;
                    else
                        value = value * 10 + 8;
                    break;

                case 'v':
                    value = value * 10 + 7;
                    break;

                case 'w':
                    value = value * 10 + 9;
                    break;
            }
        } else {
            switch (color[0])
            {
                case 'b':
                    if (color[1] == 'l')
                    {
                        if (color[2] == 'u')
                            value *= 1000000;
                    }
                    else
                        value *= 10;
                    break;

                case 'r':
                    value *= 100;
                    break;

                case 'o':
                    value *= 1000;
                    break;
                
                case 'y':
                    value *= 10000;
                    break;

                case 'g':
                    if (color[3] == 'e')
                        value *= 100000;
                    else
                        value *= 100000000;
                    break;

                case 'v':
                    value *= 10000000;
                    break;

                case 'w':
                    value *= 1000000000;
                    break;
            }
        }
    }

    cout << value;
    
    return 0;
}