//https://www.acmicpc.net/problem/16434

//�巡�� �� ����
//��ȸ ��ũ : https://www.acmicpc.net/category/detail/1949



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int type;
	int atk;		//type 1�̸� ���� ���ݷ�, 2�� ���ݷ� ���
	int hp;			//type 2�̸� ���� ü��, 2�� ȸ����
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
		case 1: //���� �ʵ�
			layeredHP[i] = (long long)-adventure[i].atk * ((adventure[i].hp - 1) / attack);
			break;
		case 2: //ȸ�� ����
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