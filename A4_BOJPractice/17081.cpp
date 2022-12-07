//https://www.acmicpc.net/problem/17081

/*RPG Extreme (Platinum 2)
N*M 2차원 그리드 위에서 RPG 게임이 진행된다. 각 칸에는 아래와 같은 것들이 있을 수 있다.
1. 빈 칸(.) : 자유롭게 입장할 수 있는 칸이다. 주인공(@)은 처음에 빈칸에서 시작한다.
2. 벽(#) : 막힌 칸이다. 이 칸으로는 움직일 수 없다.
3. 아이템 상자(B) : 무기(W), 갑옷(A), 장신구(O) 3가지 중 하나가 들어있다. 아이템 상자를 열 경우, 무기 / 방어구는 해당 장비로
교체되며, 장신구의 경우, 착용할 수 있는 칸이 남았고 동일한 효과의 장신구를 착용하지 않은 경우에만 남은 칸에 착용한다.
그리고 아이템 상자가 열리고 나면, 해당 칸은 빈 칸이 되며, 주인공은 아이템 상자를 연 이후 그 칸으로 이동하게 된다.
4. 가시 함정(^) : 가시 함정은 밟으면 5의 데미지를 입으며, 이로 인해 사망할 수도 있다.
밟더라도 사라지지 않으며, 입력받은 커맨드로 움직일 수 없어 제자리에 멈추는 경우, 다시 데미지를 받는다.
5. 몬스터(&) : 몬스터는 알파벳 대소문자 문자열로 된 이름, 정수로 표시되는 공격력, 방어력, 체력, 쓰러뜨렸을 때 얻을 수 있는 경험치 값을 갖는다.
몬스터가 있는 칸에 입장하면, 전투가 벌어지는 데, 항상 주인공이 선공을 하며, 한 번씩 번갈아가며 각자 max(1, 내 공격력 - 상대 방어력)만큼의 데미지를 서로에게 한 번씩 입힌다.
한 쪽의 체력이 0 이하가 될 경우, 전투는 즉시 종료된다. 이 전투 과정은 모두 한 턴 내에 이루어지며, 주인공이 승리하면 그 칸은 빈 칸이 되고, 그 칸으로 이동하게 된다.
6. 보스 몬스터(M) : 몬스터와 동일하다. 게임의 목표는 보스 몬스터 처치이다.
7. 주인공
주인공은 처음에 어느 빈 칸에서 시작한다. 주인공 캐릭터에 대한 정보는 다음과 같다.
a. 체력, 공격력, 방어력 : 정수로 표현된다. 초기 값은 체력 20, 공격력 2, 방어력 2이다.
b. 경험치 : 레벨 1로 시작하며, 레벨 N에서 N + 1이 되기 위한 경험치 값은 5N이다. 
레벨이 오르면 최대 체력이 5, 공/방 2씩 상승하며, HP가 모두 회복된다. 그리고, 레벨 업 직후 남는 경험치는 모두 버린다.
c. 무기와 방어력 : 각각 1개씩만 착용할 수 있고 각각 공격력과 방어력을 더해준다. 무기의 공격력 상승은 다른 공격력 상승 효과보다 우선 적용된다.
d. 장신구 : 최대 4개까지 착용할 수 있으나, 동일한 효과의 장신구는 최대 하나까지만 착용 가능하다. 각 장신구에는 여러 효과가 있다.
 - HP Regeneration(HR) : 전투에서 승리할 때마다 체력을 3 회복한다. (단, 최대 체력을 넘지 않음)
 - Reincarnation(RE) : 주인공이 사망했을 때 소멸하며, 주인공을 최대 체력으로 부활시켜 준 뒤, 주인공을 첫 시작 위치로 돌려보낸다.
                       이때, 레벨, 장비는 변함이 없고 전투 중인 몬스터도 모두 회복된다. 소멸 뒤에 다시 얻으면 재착용 할 수 있다.
 - Courage(CO) : 모든 전투에서, 첫 번째 공격에서 주인공의 공격력(무기 합산)이 두 배로 적용되어 max(1, 공격력*2-몬스터방어력) 데미지를 입힌다.
 - Dexterity(DX) : 가시 함정에 입는 데미지가 1로 감소하고, Courage와 같이 착용했을 때, 공격력 상승분이 2배 대신 3배 적용된다.
 - Experiance(EX) : 얻는 경험치가 1.2배가 된다 (소수점 버림)
 - Hunter(HU) : 보스 몬스터 전투 시 즉시 체력을 최대치까지 회복하고, 보스 몬스터의 첫 공격에 0 데미지를 받는다.
 - Cursed(CU) : 아무 능력이 없고, 그냥 장신구 자리만 차지한다.

주인공의 한 턴은 먼저 상하좌우로 한 칸 이동하고, 그 칸에 해당되는 이벤트가 일어나는 방식으로 구성된다.
이동 커맨드는 L(왼쪽), R(오른쪽), U(위쪽), D(아래쪽)이며, 커맨드 방향이 막혀있거나, 그리드 밖이면 아무 일도 일어나지 않는다.

게임은 보스 몬스터를 처치하거나, 주인공이 죽거나, 입력된 문자열에 해당하는 모든 커맨드가 마쳤을 경우 끝난다.
보스 몬스터 처치 시 처치 결과도 모두 반영하며, 게임이 끝난 이후 커맨드는 모두 무시한다. 게임이 끝나면, 다음과 같은 순서대로 게임의 결과를 출력한다.
1. 게임 종료 시점 커멘드의 상태 : 
주인공(@, 그 칸에 무엇이 있던 무조건 @로 표시), 빈 칸, 벽, 보스 포함 몬스터(살아있을 경우), 가시 함정, 아이템 상자(열리지 않은 경우)
2. 진행된 턴 수 T : 예를 들어 첫 이동 후 게임이 즉시 끝난다면 1을 출력한다.
3. 종료 시점 주인공의 정보 : 주인공의 레벨, 주인공의 현재/최대 체력, 공격력과 방어력(기본+장비), 현재/최대 경험치량
4. 게임의 결과
보스 몬스터를 처치한 경우 : YOU WIN!
죽었을 경우 : YOU HAVE BEEN KILLED BY <S>..  (S는 몬스터의 이름이 들어가며, 가시 함정에 의해 죽으면 SPIKE TRAP이 된다.)
입력이 끝난 경우 : Press any key to continue.

입력 순서
1. 먼저 그리드의 크기 및 상태가 주어진다. (최대 100*100, 최소 2칸) 주인공과 보스 몬스터는 반드시 1개씩 존재한다.
2. 그 다음엔 LRUD로 이루어진 커맨드 문자열이 주어진다. (최대 5000자)
3. 몬스터의 수만큼 각 행마다, 몬스터의 행 위치, 열 위치, 이름(서로 다름), 공격력, 방어력, 체력, 경험치가 주어진다.
4. 아이템 상자 수만큼 각 행마다, 상자의 행 위치, 열 위치, 장비 종류, 장신구 종류 혹은 무기/방어구 상승 수치가 주어진다.
몬스터, 아이템 상자 정보는 정확히 한 번씩 주어진다.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum BLOCKSTATE {EMPTY, WALL, ITEMBOX, TRAP, MONSTER, BOSSMONSTER};
enum PLAYERSTATE {RESUME, END, WIN, DIE};
enum EQUIPMENT {WEAPON, ARMOR, HR, RE, CO, EX, DX, HU, CU};

class Player {
public:
    int maxHP, curHP;
    int baseAttack, equipAttack, baseDefence, equipDefence;
    int maxEXP, curEXP, level;
    vector<EQUIPMENT> accessoryList;

    Player() : accessoryList()
    {   
        this->maxHP = this->curHP = 20;
        this->baseAttack = this->baseDefence = 2;
        this->equipAttack = this->equipDefence = this->curEXP = 0;
        this->level = 1;
        this->maxEXP = 5;
    };

    void addAccessory(const EQUIPMENT& accessory)
    {
        if (this->accessoryList.size() == 4 || this->has(accessory) == true)
            return;

        this->accessoryList.push_back(accessory);
    }

    bool has(const EQUIPMENT& accessory)
    {
        for (const auto& playerAccessory : this->accessoryList)
            if (playerAccessory == accessory) return true;
        return false;
    }

    void getEXP(const int& expAmount)
    {
        this->curEXP += expAmount;
        if (this->curEXP >= this->maxEXP)
        {
            this->level++;
            this->curEXP = 0;
            this->maxEXP = this->level * 5;
            this->maxHP += 5;
            this->curHP = this->maxHP;
            this->baseAttack += 2;
            this->baseDefence += 2;
        }
    }
};



class Block {
public:
    virtual ~Block() {};
    virtual BLOCKSTATE what() = 0;
    virtual int enterBlock(Player* player) {
        return 0;
    };
};

class EmptyBlock : public Block {
    BLOCKSTATE what() override {
        return EMPTY;
    }
};

class Wall : public Block {
    BLOCKSTATE what() override {
        return WALL;
    }
};

class Itembox : public Block {
public:
    BLOCKSTATE what() override {
        return ITEMBOX;
    }

    EQUIPMENT item;
    int stat;

    int enterBlock(Player* player) override {
        switch (this->item)
        {
            case WEAPON:
                player->equipAttack = this->stat;
                break;
            case ARMOR:
                player->equipDefence = this->stat;
                break;
            default: // = equipment in the box is accessory
                player->addAccessory(item);
                break;
        }
        

        return 0;
    }
};

class Trap : public Block {
public:
    BLOCKSTATE what() override {
        return TRAP;
    }

    int enterBlock(Player* player) override {
        if (player->has(DX))
            player->curHP -= 1;
        else
            player->curHP -= 5;
        
        if (player->curHP <= 0)
        {
            player->curHP = 0;
            return 1;
        } else return 0;
    }
};

class Monster : public Block {
public:
    bool isBoss;
    string name;
    int attack, defence, hp, exp;

    Monster(BLOCKSTATE blockState) : Block() {
        this->isBoss = (blockState == BOSSMONSTER) ? true : false;
    };
    
    BLOCKSTATE what() override {
        return isBoss ? BOSSMONSTER : MONSTER;
    }

    int enterBlock(Player* player) override {
        if (this->what() == BOSSMONSTER && player->has(HU)) //HU 장신구 효과 1
            player->curHP = player->maxHP;
        
        int monsterCurrentHP = this->hp;
        int fightTurn = 0;
        while (++fightTurn)
        {
            //Player Attack Turn
            if (fightTurn == 1 && player->has(CO))
            {
                if (player->has(DX))
                    monsterCurrentHP -= max(1, (player->baseAttack + player->equipAttack) * 3 - this->defence);
                else
                    monsterCurrentHP -= max(1, (player->baseAttack + player->equipAttack) * 2 - this->defence);
            }
            else monsterCurrentHP -= max(1, player->baseAttack + player->equipAttack - this->defence);

            if (monsterCurrentHP <= 0)
                break;
            
            //Monster Attack Turn
            if (fightTurn == 1 && this->what() == BOSSMONSTER && player->has(HU)) //HU 장신구 효과 2
                player->curHP -= 0;
            else
                player->curHP -= max(1, this->attack - (player->baseDefence + player->equipDefence));

            if (player->curHP <= 0)
            {
                player->curHP = 0;
                return 1;
            }
        }

        if (player->has(EX)) //EXP 1.2x
            player->getEXP((int)((double)this->exp * 1.2));
        else
            player->getEXP(this->exp);

        if (player->has(HR)) //HP Regeneration
            player->curHP = min(player->curHP + 3, player->maxHP);

        return 0;
    }
};




class Grid {
public:
    vector<vector<Block*>> grid;
    int xSize, ySize;
    Player* player;
    int playerStartX, playerStartY;
    int playernowX, playernowY;
    string moveList;
    int gridTurn;

    Grid(Player* player) : player(player) {
        cin >> ySize >> xSize;
        int monsterCount = 0, itemboxCount = 0; this->gridTurn = 0;
        grid = vector<vector<Block*>>(this->ySize);

        for (int gridY = 0; gridY < this->ySize; gridY++)
        {
            grid[gridY].reserve(this->xSize);
            string gridLine;
            cin >> gridLine;
            for (int gridX = 0; gridX < this->xSize; gridX++)
            {
                Block* currentBlock = nullptr;
                if (gridLine[gridX] == '.') currentBlock = new EmptyBlock();
                if (gridLine[gridX] == '#') currentBlock = new Wall();
                if (gridLine[gridX] == '^') currentBlock = new Trap();
                if (gridLine[gridX] == 'B') 
                {
                    currentBlock = new Itembox(); itemboxCount++;
                }
                if (gridLine[gridX] == '&') 
                {
                    currentBlock = new Monster(MONSTER); monsterCount++;
                }
                if (gridLine[gridX] == 'M') 
                {
                    currentBlock = new Monster(BOSSMONSTER); monsterCount++;
                }
                if (gridLine[gridX] == '@') //player Block
                {
                    currentBlock = new EmptyBlock();
                    this->playerStartX = this->playernowX = gridX;
                    this->playerStartY = this->playernowY = gridY;
                }
                grid[gridY].emplace_back(currentBlock);
            }
            
        }

        cin >> this->moveList;

        //Monster input
        while (monsterCount--)
        {
            int monsterY, monsterX;
            cin >> monsterY >> monsterX;

            Monster* monsterPtr = dynamic_cast<Monster*>(this->grid[monsterY-1][monsterX-1]);
            cin >> monsterPtr->name >> monsterPtr->attack >> monsterPtr->defence >> monsterPtr->hp >> monsterPtr->exp;
        }

        //item input
        while (itemboxCount--)
        {
            int itemboxY, itemboxX;
            cin >> itemboxY >> itemboxX;

            Itembox* itemboxPtr = dynamic_cast<Itembox*>(this->grid[itemboxY-1][itemboxX-1]);
            
            char itemSort;
            cin >> itemSort;
            
            if (itemSort == 'W')
            {
                itemboxPtr->item = WEAPON;
                cin >> itemboxPtr->stat;
            }
            if (itemSort == 'A')
            {
                itemboxPtr->item = ARMOR;
                cin >> itemboxPtr->stat;
            }
            if (itemSort == 'O')
            {
                string accessorySort;
                cin >> accessorySort;
                if (accessorySort.compare("HR") == 0) itemboxPtr->item = HR;
                if (accessorySort.compare("RE") == 0) itemboxPtr->item = RE;
                if (accessorySort.compare("CO") == 0) itemboxPtr->item = CO;
                if (accessorySort.compare("EX") == 0) itemboxPtr->item = EX;
                if (accessorySort.compare("DX") == 0) itemboxPtr->item = DX;
                if (accessorySort.compare("HU") == 0) itemboxPtr->item = HU;
                if (accessorySort.compare("CU") == 0) itemboxPtr->item = CU;

            }
        }
    }

    PLAYERSTATE move() {
        if (this->gridTurn == moveList.size())
            return END;

        const char& nextMove = moveList[gridTurn++];
        Block* nowStep = nullptr;

        if (nextMove == 'L')
        {
            if (this->playernowX == 0 || this->grid[playernowY][playernowX - 1]->what() == WALL)
                nowStep = this->grid[playernowY][playernowX];
            else
                nowStep = this->grid[playernowY][--playernowX];
        }

        if (nextMove == 'R')
        {
            if (this->playernowX == this->xSize - 1 || this->grid[playernowY][playernowX + 1]->what() == WALL)
                nowStep = this->grid[playernowY][playernowX];
            else
                nowStep = this->grid[playernowY][++playernowX];
        }

        if (nextMove == 'U')
        {
            if (this->playernowY == 0 || this->grid[playernowY - 1][playernowX]->what() == WALL)
                nowStep = this->grid[playernowY][playernowX];
            else
                nowStep = this->grid[--playernowY][playernowX];
        }

        if (nextMove == 'D')
        {
            if (this->playernowY == this->ySize - 1 || this->grid[playernowY + 1][playernowX]->what() == WALL)
                nowStep = this->grid[playernowY][playernowX];
            else
                nowStep = this->grid[++playernowY][playernowX];
        }

        int result = nowStep->enterBlock(this->player);

        if (result == 0) //player Normal
        {
            BLOCKSTATE enteredBlockState = nowStep->what();
            switch (enteredBlockState)
            {
                case ITEMBOX: case MONSTER: case BOSSMONSTER: 
                //아이템 혹은 몬스터를 그리드에서 지우고 일반 벽으로 바꾼다.
                this->grid[playernowY][playernowX] = new EmptyBlock();
                delete nowStep;
            }

            if (enteredBlockState == BOSSMONSTER)
                return WIN;
            else
                return RESUME;
        }
        else //player died
        {
            if (player->has(RE)) //부활 장신구 소지 시
            {
                auto it = player->accessoryList.begin();
                while (*it != RE)
                    ++it;

                player->accessoryList.erase(it); //장신구 삭제

                playernowX = playerStartX;
                playernowY = playerStartY;
                player->curHP = player->maxHP;
                return RESUME;
            }
            else return DIE;
        }

    }

    void print(PLAYERSTATE playerState)
    {
        //1. print grid
        for (int gridY = 0; gridY < this->ySize; gridY++)
        {
            for (int gridX = 0; gridX < this->xSize; gridX++)
            {
                if (gridY == playernowY && gridX == playernowX && playerState != DIE)
                {
                    cout << '@';
                    continue;
                }
                switch (this->grid[gridY][gridX]->what())
                {
                    case EMPTY:
                        cout << '.'; break;
                    case WALL:
                        cout << '#'; break;
                    case ITEMBOX:
                        cout << 'B'; break;
                    case TRAP:
                        cout << '^'; break;
                    case MONSTER:
                        cout << '&'; break;
                    case BOSSMONSTER:
                        cout << 'M'; break;
                }
            }
            cout << '\n';
        }


        //2. print player info
        cout << "Passed Turns : " << this->gridTurn << '\n';
        cout << "LV : " << this->player->level << '\n';
        cout << "HP : " << this->player->curHP << '/' << this->player->maxHP << '\n';
        cout << "ATT : " << this->player->baseAttack << '+' << this->player->equipAttack << '\n';
        cout << "DEF : " << this->player->baseDefence << '+'<< this->player->equipDefence << '\n';
        cout << "EXP : " << this->player->curEXP << '/' << this->player->maxEXP << '\n';
        

        switch (playerState)
        {
            case END:
                cout << "Press any key to continue.";
                break;
            case WIN:
                cout << "YOU WIN!";
                break;
            case DIE:
                cout << "YOU HAVE BEEN KILLED BY ";
                Block* dyingBlock = this->grid[playernowY][playernowX];
                if (dyingBlock->what() == TRAP)
                    cout << "SPIKE TRAP..";
                else { //killed by monster
                    Monster* killer = dynamic_cast<Monster*>(dyingBlock);
                    cout << killer->name << "..";
                }
        }
    }

    ~Grid() {
        for (int gridY = 0; gridY < this->ySize; gridY++)
            for (int gridX = 0; gridX < this->xSize; gridX++)
                delete grid[gridY][gridX];
    }
};






int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    Player* player = new Player();
    Grid* grid = new Grid(player);

    PLAYERSTATE playerState;
    while ((playerState = grid->move()) == RESUME);
    grid->print(playerState);

    delete player;
    delete grid;
	
	return 0;
}
