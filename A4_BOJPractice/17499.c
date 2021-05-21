//https://www.acmicpc.net/problem/17499

/*������ ����Ʈ ����
��ȸ ��ũ : https://www.acmicpc.net/category/detail/2062
*/

#include <stdio.h>
#include <stdlib.h>

int resetpos(int nowpos, int addpos, int arrlen) {
	nowpos += addpos;
	while (nowpos < 0 || nowpos >= arrlen) {
		if (nowpos < 0) {
			nowpos += arrlen;
		}
		else if (nowpos >= arrlen) {
			nowpos -= arrlen;
		}
	}
	return nowpos;
}

int main(void) {
	int arrlen;
	int testcase;
	int startpos = 0;
	int* arr;

	scanf("%d %d", &arrlen, &testcase);

	arr = (int*)malloc(sizeof(int) * arrlen);

	for (int i = 0; i < arrlen; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < testcase; i++) {
		int order;
		scanf("%d", &order);
		if (order == 1) { //�迭�� ����
			int index, add;
			scanf("%d %d", &index, &add);
			arr[resetpos(startpos, index - 1, arrlen)] += add;
		}
		else if (order == 2) { //ptr �������� �̵�
			int swifts;
			scanf("%d", &swifts);
			startpos = resetpos(startpos, -swifts, arrlen);
		}
		else {
			int swifts;
			scanf("%d", &swifts);
			startpos = resetpos(startpos, swifts, arrlen);
		}
	}


	for (int i = startpos; i < arrlen; i++) {
		printf("%d ", arr[i]);
	}
	for (int i = 0; i < startpos; i++) {
		printf("%d ", arr[i]);
	}

	return 0;

}