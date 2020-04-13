//https://www.acmicpc.net/problem/1931

//한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의들에 대하여 회의실 사용표를 만들려 한다.
//각 회의의 시작 시간과, 끝 시간이 주어질 때, 최대한 많은 회의를 짤 때의 회의 갯수를 구하시오.
//(한 회의가 끝나는 시간에 바로 다음 회의가 시작하는 시간인 경우는 허용한다.)

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