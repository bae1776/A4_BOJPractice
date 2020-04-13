//https://www.acmicpc.net/problem/1931

//�� ���� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǵ鿡 ���Ͽ� ȸ�ǽ� ���ǥ�� ����� �Ѵ�.
//�� ȸ���� ���� �ð���, �� �ð��� �־��� ��, �ִ��� ���� ȸ�Ǹ� © ���� ȸ�� ������ ���Ͻÿ�.
//(�� ȸ�ǰ� ������ �ð��� �ٷ� ���� ȸ�ǰ� �����ϴ� �ð��� ���� ����Ѵ�.)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
} Meeting;

int cmp(const void* a, const void* b) {
	return (*(Meeting*)a).end == (*(Meeting*)b).end ? 
		(*(Meeting*)a).start - (*(Meeting*)b).start : 
		(*(Meeting*)a).end - (*(Meeting*)b).end ;
}

int main(void)
{
	int meeting_count;
	scanf("%d", &meeting_count);

	Meeting* myMeeting = (Meeting*)malloc(sizeof(Meeting) * meeting_count);
	
	for (int i = 0; i < meeting_count; i++)
	{
		scanf("%d %d", &myMeeting[i].start, &myMeeting[i].end);
	}

	qsort(myMeeting, meeting_count, sizeof(Meeting), cmp);
	

	int meetingMax = 0;
	int lastend = 0;
	int nowidx = 0;
	while (1) {
		char flag = 0;
		for (int i = nowidx; i < meeting_count; i++) {
			if (myMeeting[i].start >= lastend) {
				nowidx = i + 1;
				meetingMax++;
				lastend = myMeeting[i].end;
				flag = 1;
				break;
			}
		}
		if (flag == 0) break;
	}

	printf("%d", meetingMax);


	free(myMeeting);
	return 0;
}