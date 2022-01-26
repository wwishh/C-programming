#include <stdio.h>

int main()
{

    static char str[100], strb[100], strc[100];
    int cnt = 0;
    strb[0] = '\0';
    strc[0] = '\0';
    printf("문자열 입력:");
    gets(str);
    for (int i = 0; i <= sizeof(str) / sizeof(char); i++)
    {

        if (str[i] == '\0')
        {
            break;
        }

        cnt++;
        ;
    }
    printf("%d", cnt);

    for (int i = cnt; i >= 0; i--)
    {
        strb[i] = str[i];
        printf("%c", strb[i]);
        cnt++;
    }

    for (int i = 0; i < sizeof(strb); i++)
    {

        printf("%c", strb[i]);
    }
    return 0;
}