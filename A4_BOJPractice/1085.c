//https://www.acmicpc.net/problem/1085

//���簢�� Ż��
//�Ѽ��� (x,y)�� �ְ� ���簢���� ���� �ϴ� �������� (0,0), ������ ��� �������� (w,h)�� �ִ�. 
//�Ѽ��� ���簢�� ��輱���� �ּ� �Ÿ�(����)�� ����Ͻÿ�
//�Է� : x y w h

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int my_x, my_y, rect_x, rect_y;
	scanf("%d %d %d %d", &my_x, &my_y, &rect_x, &rect_y);

	int xmin = (my_x > rect_x - my_x) ? rect_x - my_x : my_x;
	int ymin = (my_y > rect_y - my_y) ? rect_y - my_y : my_y;

	printf("%d", xmin < ymin ? xmin : ymin);
}