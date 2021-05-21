//https://www.acmicpc.net/problem/17502

/*클레어와 팰린드롬
대회 링크 : https://www.acmicpc.net/category/detail/2062
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* str;
	int num;
	int j;

	scanf("%d", &num);
	str = (char*)malloc(sizeof(char) * (num + 1));
	scanf("%s", str);
	/*str[num] = '\0';*/

	for (int i = 0; i < num / 2; i++)
	{
		j = num - 1 - i;
		if (str[i] == '?' && str[j] == '?')
		{
			str[i] = 'x';
			str[j] = 'x';
		}
		else if (str[i] == '?' && str[j] != '?')
		{
			str[i] = str[j];
		}
		else if (str[i] != '?' && str[j] == '?')
		{
			str[j] = str[i];
		}
	}

	if (num % 2 == 1 && str[num / 2] == '?')
	{
		str[num / 2] = 'x';
	}

	printf("%s", str);
	return 0;
}
