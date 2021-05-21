//https://www.acmicpc.net/problem/10757

/* 큰 수 A+B
C언어의 long long으로는 처리할 수 없는 최대 10000 자리 수의 덧셈을 구현해보자.
*/

#include <stdio.h>
#include <string.h>

void reverseString(char* str, int len);

char A[10002], B[10002];

int main(void)
{
    scanf("%s %s", A, B);

    int Alen = strlen(A), Blen = strlen(B);

    //reverseStrA, B
    reverseString(A, Alen);
    reverseString(B, Blen);

    int maxlen = Alen > Blen ? Alen : Blen;
    int carry = 0;
    for (int i = 0; i <= maxlen; i++)
    {
        if (A[i] == NULL)
        {
            if (B[i] == NULL)
            {
                if (carry) A[i] = '1';
                break;
            } else {
                A[i] = B[i] + carry;
            }
        } else {
            if (B[i] == NULL)
                A[i] += carry;
            else {
                A[i] += (B[i] - '0') + carry;
            }
        }
        
        if (A[i] > '9')
        {
            A[i] -= 10;
            carry = 1;
        } else 
            carry = 0;
    }

    reverseString(A, strlen(A));

    printf("%s", A);

    return 0;
}


void reverseString(char* str, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}