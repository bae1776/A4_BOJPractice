//https://www.acmicpc.net/problem/2447

//재귀적으로 별을 찍는 문제

#include <stdio.h>
#include <stdlib.h>


void vacant(char** arr, int row, int col, int val)
{
	for (int i = 0; i < val; i++)
	{
		for (int j = 0; j < val; j++)
		{
			arr[row + i][col + j] = ' ';
		}
	}
}

void shape(char** arr, int row, int col, int val)
{
	int div3 = val / 3;
	switch (val)
	{
	case 3:
		arr[row][col] = '*'; arr[row][col+1] = '*'; arr[row][col+2] = '*';
		arr[row+1][col] = '*'; arr[row+1][col+1] = ' '; arr[row+1][col+2] = '*';
		arr[row+2][col] = '*'; arr[row+2][col+1] = '*'; arr[row+2][col+2] = '*';
		break;
	default:
		shape(arr, row, col, div3);
		shape(arr, row, col + div3, div3);
		shape(arr, row, col + 2*div3, div3);
		shape(arr, row + div3, col, div3);
		vacant(arr, row + div3, col + div3, div3);
		shape(arr, row + div3, col + 2 * div3, div3);
		shape(arr, row + 2 * div3, col, div3);
		shape(arr, row + 2 * div3, col + div3, div3);
		shape(arr, row + 2 * div3, col + 2 * div3, div3);
	}
}



int main(void)
{
	int input;
	scanf("%d", &input);

	char** arr = (char**)malloc(sizeof(char*) * input);
	for (int i = 0; i < input; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * input);
	}

	shape(arr, 0, 0, input);

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
		free(arr[i]);
	}
	free(arr);
}