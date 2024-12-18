//https://www.acmicpc.net/problem/16434

//드래곤 앤 던전
//대회 링크 : https://www.acmicpc.net/category/detail/1949



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int type;
	int atk;		//type 1이면 몬스터 공격력, 2면 공격력 상승
	int hp;			//type 2이면 몬스터 체력, 2면 회복량
} Room;


int main(void) {
	int roomcount;
	long long attack;

	scanf("%d %d", &roomcount, &attack);

	Room* adventure = (Room*)malloc(sizeof(Room) * roomcount);
	long long* layeredHP = (long long*)calloc(roomcount, sizeof(long long));

	for (int i = 0; i < roomcount; i++) {
		scanf("%d %d %d", &adventure[i].type, &adventure[i].atk, &adventure[i].hp);
	}

	for (int i = 0; i < roomcount; i++) {
		switch (adventure[i].type) {
		case 1: //몬스터 필드
			layeredHP[i] = (long long)-adventure[i].atk * ((adventure[i].hp - 1) / attack);
			break;
		case 2: //회복 지점
			layeredHP[i] = (long long)adventure[i].hp;
			attack += adventure[i].atk;
		}
	}

	long long Nowhp = 0;
	long long Maxhp = 0;

	for (int i = 0; i < roomcount; i++) {
		Nowhp += layeredHP[i];
		if (Nowhp < -Maxhp) Maxhp = -Nowhp;
		if (Nowhp > 0) Nowhp = 0;
	}

	printf("%lld", Maxhp + 1);
}