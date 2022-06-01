//https://www.acmicpc.net/problem/1145

/*적어도 대부분의 배수

체스판은 8*8 크기에 검정 칸과 하얀 칸이 번갈아가면서 색칠되어있다.
체스판의 상태가 주어졌을 때, 하얀 칸 위에 말 개수를 구하시오.
*/

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int input[5];
    
    for (auto& in : input)
        cin >> in;
    
    int result = 1;

    while (true)
    {
        int chance = 3;

        for (const auto& divisor : input)
        {
            if (result % divisor)
                chance--;
            
            if (chance == 0)
                break;
        }

        if (chance != 0)
            break;
        
        result++;
    }

    cout << result;


    return 0;
}
