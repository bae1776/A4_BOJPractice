//https://www.acmicpc.net/problem/16431

//베시와 데이지
//대회 링크 : https://www.acmicpc.net/category/detail/1949

#include <stdio.h>

int main(void) {
	int dRow, dCol;
	int bRow, bCol;
	int jRow, jCol;
	int dTime, bTime;
	int dDisRow, dDisCol;
	int bDisRow, bDisCol;

	scanf("%d %d", &bRow, &bCol);
	scanf("%d %d", &dRow, &dCol);
	scanf("%d %d", &jRow, &jCol);

	dDisRow = jRow - dRow >= 0 ? jRow - dRow : dRow - jRow;
	dDisCol = jCol - dCol >= 0 ? jCol - dCol : dCol - jCol;
	bDisRow = jRow - bRow >= 0 ? jRow - bRow : bRow - jRow;
	bDisCol = jCol - bCol >= 0 ? jCol - bCol : bCol - jCol;

	bTime = bDisRow > bDisCol ? bDisRow : bDisCol;
	dTime = dDisRow + dDisCol;

	if (bTime < dTime)
		printf("bessie");
	else if (bTime == dTime)
		printf("tie");
	else
		printf("daisy");


	return 0;
}