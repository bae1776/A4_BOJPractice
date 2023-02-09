//https://www.acmicpc.net/problem/3788

/* Delta Encoding and Decoding (Silver 하위권~중위권 예상)
고전적 문자열 치환 암호
암호키 변경 기능, 암호화, 복호화 구현해야함
*/


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isSameStrIgnoreCase(const char* a, const char* b);
char numToChar[26];
char input[10002], result[10002];
int charToNum[255];


int main(void) {

    for (int i = 0; i < 26; i++)
    {
      numToChar[i] = 'A' + i;
      charToNum['A' + i] = i; 
    }
    

    while (cin.getline(input, 10001))
    {            

        if (isSameStrIgnoreCase(input, "ENCRYPT "))
        {
            bool lower;
            char before = 'A', now;
            char* sentencePointer = input + 8;
            int resultIndex = -1;
            
            while (now = *(sentencePointer + ++resultIndex))
            {
                if (!isalpha(now))
                {
                    result[resultIndex] = now;
                    before = 'A';
                    continue;
                }

                if (lower = islower(now))
                    now = toupper(now);

                result[resultIndex] = 
                    numToChar[(charToNum[now] - charToNum[before] + 26) % 26];
                before = toupper(*(sentencePointer + resultIndex));

                if (lower)
                    result[resultIndex] = tolower(result[resultIndex]);
            }
            result[resultIndex] = '\0';

            cout << "RESULT:  " << result << '\n';

        } else if (isSameStrIgnoreCase(input, "DECRYPT ")) {
            
            bool lower;
            char before = 'A', now;
            char* sentencePointer = input + 8;
            int resultIndex = -1;
            
            while (now = *(sentencePointer + ++resultIndex))
            {
                if (!isalpha(now))
                {
                    result[resultIndex] = now;
                    before = 'A';
                    continue;
                }

                if (lower = islower(now))
                    now = toupper(now);

                result[resultIndex] = 
                    numToChar[(charToNum[now] + charToNum[before]) % 26];
                before = result[resultIndex];

                if (lower)
                    result[resultIndex] = tolower(result[resultIndex]);
            }
            result[resultIndex] = '\0';

            cout << "RESULT:  " << result << '\n';
      
        } else if (isSameStrIgnoreCase(input, "CIPHER ")) {

            bool commandValid = true;
            bool alphabetLookTable[26] = {false, };
            char cipherString[27] = { '\0', };
            char now;
            char* sentencePointer = input + 7;
            int resultIndex = -1, cipherLen = 0;
            
            while (now = *(sentencePointer + ++resultIndex))
            {
                if (isalpha(now))
                {
                    int index = toupper(now) - 'A';
                    if (alphabetLookTable[index] == true)
                    {
                        commandValid = false;
                        break;
                    }
                    alphabetLookTable[index] = true;
                    cipherString[cipherLen++] = index + 'A';
                }
            }

            if (commandValid && cipherLen == 26)
            {
                cout << "Good cipher.  Using " << cipherString << ".\n";
                for (int i = 0; i < cipherLen; i++)
                {
                    numToChar[i] = cipherString[i];
                    charToNum[cipherString[i]] = i;
                }
            } else {
                cout << "Bad cipher.  Using default.\n";
                for (int i = 0; i < 26; i++)
                {
                    numToChar[i] = 'A' + i;
                    charToNum['A' + i] = i;
                }
            }

      
        } else {
            cout << "Command not understood.\n";
        }
    }

    return 0;
}


bool isSameStrIgnoreCase(const char* a, const char* b)
{
    int index = 0;

    while (a[index] != '\0' && b[index] != '\0')
    {
        if (toupper(a[index]) == toupper(b[index]))
            index++;
        else
            return false;
    }

    return true;
}