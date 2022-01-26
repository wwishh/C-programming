#include <stdio.h>
#include <conio.h>

void ex_01(void)
{
    char ch[4];
    int i;
    for (i = 0; i <= 3; i++)
    {

        printf("문자입력 : ");
        ch[i] = getche();
        printf("\n");
    }
    printf("입력된 문자 = ");
    for (i = 0; i <= 3; i++)
        printf("%c", ch[i]);
}

void ex_02(void)
{
    char str[50];

    printf("문자열 입력 : ");
    gets(str);
    printf("입력된 문자열 = %s", str);
}

void ex_03(void)
{
    char str[50];
    int count = 0;
    printf("문자열 입력 : ");
    gets(str);
    while (str[count] != '\0')
    {
        count++;
    }
    printf("    입력된 문자열 길이=%d", count);
}

void ex_04(void)
{
    char str[50];
    int count = 0;
    while (1)
    {
        printf("문자열 입력 : ");
        scanf("%s",str);
        while (str[count] != '\0')
        {
            count++;
        }
        printf("    입력된 문자열의 길이=%d\n", count);
        if (str[0]=="\n")
        {
            printf("<Enter?>");
            break;
        }
        

    }
}

int main()
{
    ex_01();
    // ex_02();
    // ex_03();
    //ex_04();

    return 0;
}