//https://www.acmicpc.net/problem/999 (문제 번호)

/*벚꽃 내리는 시대에 결투를
*/

#include <iostream>
#define MAX 5002
using namespace std;

struct Element {
    int aura;
    char lastAttack;
    Element* before;
};

Element DP[MAX][MAX];
//DP (오오라) [attackNumber][라이프]


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int attackCount, aura, life;
    cin >> attackCount >> aura >> life;

    for (int hpIndex = 0; hpIndex <= aura; hpIndex++)
        DP[0][hpIndex] = {-1, '\0', nullptr};
    
    DP[0][life].aura = aura;

    for (int attackIndex = 1; attackIndex <= attackCount; attackIndex++)
    {
        int auraAttack, lifeAttack;
        cin >> auraAttack >> lifeAttack;

        for (int hpIndex = 1; hpIndex <= life; hpIndex++)
        {
            DP[attackIndex][hpIndex] = {-1, '\0', nullptr};

            if (DP[attackIndex - 1][hpIndex].aura != -1)
            {
                int thisAura = DP[attackIndex - 1][hpIndex].aura;

                if (auraAttack == -1)
                {
                    if (hpIndex > lifeAttack && DP[attackIndex][hpIndex - lifeAttack].aura < thisAura)
                    {
                        DP[attackIndex][hpIndex - lifeAttack] = {thisAura, 'L', &DP[attackIndex - 1][hpIndex]};
                    }
                } else if (lifeAttack == -1) {
                    int afterAura = max(0, DP[attackIndex][hpIndex].aura - auraAttack);
                    if (DP[attackIndex][hpIndex].aura < afterAura)
                    {
                        DP[attackIndex][hpIndex] = {afterAura, 'A', &DP[attackIndex - 1][hpIndex]};
                    }
                } else {
                    if (hpIndex > lifeAttack && DP[attackIndex][hpIndex - lifeAttack].aura < thisAura)
                    {
                        DP[attackIndex][hpIndex - lifeAttack] = {thisAura, 'L', &DP[attackIndex - 1][hpIndex]};
                    }

                    if (thisAura < auraAttack)
                        continue; //오라 데미지 선택 불가
                    
                    int afterAura = max(0, DP[attackIndex][hpIndex].aura - auraAttack);
                    if (DP[attackIndex][hpIndex].aura < afterAura)
                    {
                        DP[attackIndex][hpIndex] = {afterAura, 'A', &DP[attackIndex - 1][hpIndex]};
                    }
                }
            }
        }
    }

    char result[MAX] = {'\0'};
    for (int hpIndex = 1; hpIndex <= life; hpIndex++)
    {
        if (DP[attackCount][hpIndex].aura != -1)
        {
            cout << "YES\n";

            int index = attackCount;
            auto* ptr = &DP[attackCount][hpIndex];
            while (ptr != nullptr)
            {
                result[--index] = ptr->lastAttack;
                ptr = ptr->before;
            }

            cout << result;
            return 0;
        }
    }

    cout << "NO";

    
	
	return 0;
}
