#include <stdio.h>

long long sum(int *a, int n)
{
	long long temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp += a[i];
	}

	return temp;
}

int main(void)
{
	int arr[] = { 12421,453251,123434,126632,33221,6546534,323232,1341325 };
	int arrsize = sizeof(arr) / sizeof(arr[0]);
	printf("%lld", sum(arr, arrsize));
}