#include <stdio.h>
#include <conio.h>

void ex_04(void)
{
    char str[50];
    int i;

    while (1)
    {
        printf("문자열입력 : ");
        gets(str);

        if (str[0] == '\0')
        {
            printf("<Enter키>");
            break;
        }

        for (i = 0; str[i]; i++)
            ;
        printf("    입력된 문자열의 길이 =%d\n", i);
    }
}

void ex_05(void)
{
    char str[50], ch;
    int count = 0;

    while (1)
    {
        printf("문자열입력 : ");
        gets(str);
        if (str[0] == '\0')
        {
            printf("<Enter키>");
            break;
        }

        printf("문자입력 : ");
        ch = getche();
        printf("\n");
        for (int i = 0; str[i]; i++)
        {
            if (str[i] == ch)
            {
                count++;
            }
        }
        printf("%s에서 %c는 %d개.\n", str, ch, count);
        count = 0;
    }
}

void ex_06(void)
{
    char stra[50], strb[50];
    int i;

    printf("문자열입력 : ");
    gets(stra);

    for (i = 5; i>0; i--)
    {
        strb[i] = stra[i];
    }

    strb[i] = '\0';

    printf("stra = %s\n", stra);
    printf("strb = %s", strb);
}

void ex_09(void)
{
    printf("c_07_위시온_20175319\n");

    int from[4], sum, max, min;

    for (int i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        printf("정수 입력 : ");
        scanf("%d", &from[i]);
    }
    min = from[0];
    max = from[0];
    sum = from[0];
    for (int i = 1; i < sizeof(from) / sizeof(int); i++)
    {
        if (from[i] > max)
        {
            max = from[i];
        }
        if (from[i] < min)
        {
            min = from[i];
        }
        sum += from[i];
    }
    printf("합 = %d\n", sum);
    printf("가장 큰 수 = %d\n", max);
    printf("가장 작은 수 = %d\n", min);
}

void ex_11(void)
{
    printf("c_07_위시온_20175319\n");

    char x[100];
    int count[5] = {0}, i = 0, max = 0, maxindex = 0;

    printf("0에서 4까지의 정수 입력 : ");
    gets(x);

    while (x[i])
    {
        if (x[i] >= '0' && x[i] <= '4')
        {
            ++count[x[i] - '0'];
        }
        i++;
    }
    for (i = 0; i < 5; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            maxindex = i;
        }
    }
    printf("\n가장 많이 입력 받은 수 = %d\n", maxindex);
    printf("\n입력 횟수 = %d\n", count[maxindex]);
}

void ex_12(void)
{
    printf("c_07_위시온_20175319\n");
    char ch[33];
    int i = 0, num;

    while (1)
    {
        printf("정수 입력 : ");
        scanf("%d", &num);
        if (num == 0)
            break;
        printf("입력된 %d의 이진수는 ", num);
    }

    while (num > 0)
    {

        if (num == 1)
        {
            ch[i] = '\0';
        }
        ch[i] = ((num % 2) + '0');
        num = num / 2;
        i++;

        for (int j = (i - '\0'); j >= 0; j--)
        {
            printf("%s\n", ch[j]);
        }
    }
}

int main()
{
    //ex_04();
    //ex_05();
    //ex_06();
    //ex_09();
    //ex_11();
    ex_12();

    return 0;
}