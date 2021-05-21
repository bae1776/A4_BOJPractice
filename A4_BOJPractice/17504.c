//https://www.acmicpc.net/problem/17504

/*力府客 盆 2
措雀 傅农 : https://www.acmicpc.net/category/detail/2062
*/

#include <stdio.h>
#include <stdlib.h>

struct divs {
	long long int up;
	long long int down;
};

typedef struct divs divs;

divs underdivs(int arr[], int depth, int arrsize) {
	if (depth + 2 == arrsize) {
		divs temp;
		temp.up = (long long int) 1 + arr[depth + 1] * arr[depth];
		temp.down = (long long int) arr[depth + 1];
		return temp;
	}

	divs temp;
	divs next = underdivs(arr, depth + 1, arrsize);
	temp.up = (long long int)
		arr[depth] * next.up + next.down;
	temp.down = (long long int) next.up;
	return temp;
}


int main(void) {
	int arrsize;
	scanf("%d", &arrsize);

	int* arr = (int*)malloc(sizeof(int) * arrsize);
	for (int i = 0; i < arrsize; i++) {
		scanf("%d", &arr[i]);
	}


	divs temp = underdivs(arr, 0, arrsize);

	long long int down = (long long int) temp.up;
	long long int up = (long long int) temp.up - temp.down;


	printf("%lld %lld", up, down);
}