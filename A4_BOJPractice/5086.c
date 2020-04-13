//https://www.acmicpc.net/problem/5086

//두 수가 주어질때, 첫 숫자가 두번째 숫자의 약수면 factor, 배수면 multiple, 둘 다 아니면 neither를 출력하시오.
//이 입력은 0 0 을 입력할 때까지 무제한 반복한다.
//+두 수가 같은 경우는 없다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	while (1) {
		int left, right;
		scanf("%d %d", &left, &right);

		if (left == 0 && right == 0) break;

		if (left < right)
		{
			int orgleft = left;
			while (left < right) {
				left += orgleft;
			}

			if (left == right) printf("factor\n");
			else printf("neither\n");
		}
		else if (left > right)
		{
			int orgright = right;
			while (left > right) {
				right += orgright;
			}

			if (left == right) printf("multiple\n");
			else printf("neither\n");
		}
	}


	return 0;
}