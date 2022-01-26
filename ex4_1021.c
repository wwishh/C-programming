#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

void ex_01(void)
{
    int in;

    printf("정수를 입력하세요 : ");
    scanf("%d", &in);

    if (in >= 0)
    {
        printf("양수입니다.");
    }
    else
    {
        printf("음수입니다.");
    }
}

void ex_02(void)
{
    int in;

    printf("정수를 입력하세요 : ");
    scanf("%d", &in);

    switch ((in / 2) > 10)
    {
    case 1:
        printf("OK");
        break;
    case 0:
        printf("NOK");
        break;
    }
}

void ex_03(void)
{
    double dou, sum = 0;

    while (dou > -100 && dou < 100)
    {
        sum += dou;
        printf("숫자를 입력하세요 : ");
        scanf("%lf", &dou);
    }

    printf("-100이상 100이하 숫자들의 합 = %.2lf", sum);
}

void ex_04(void)
{
    char ch;

    printf("문자를 입력하세요 : ");
    while (tolower(ch) != 'q')
    {
        ch = getche();
    }
}

void ex_05(void)
{
    int in, bin1 = 0, bin2 = 0, place = 1;

    printf("정수를 입력하세요 : ");
    scanf("%d", &in);

    while (in >= 1)
    {
        bin1 = (in % 2) * place;
        bin2 += bin1;
        place *= 10;
        in /= 2;
    }
    printf("2진수는 = %d", bin2);
}

void ex_06()
{
    int in, count = 0;

    printf("정수를 입력하세요 : ");
    scanf("%d", &in);

    while (in >= 1)
    {
        if (in & 1)
        {
            count++;
        }
        in = in >> 1;
    }
    printf("2진수로 만들 때 1이 나타나는 횟수 = %d", count);
}

void ex_07(void)
{
    int in, count = 1;

    do
    {
        printf("정수를 입력하세요 : ");
        scanf("%d", &in);
    } while (in < 10);

    for (int i = 10; i <= in; i++)
    {
        if ((i % 2) && (i % 3) && (i % 5) && (i % 7))
        {
            printf("%3d%c", i, (count++ % 10) ? ' ' : '\n');
        }
    }
}

void ex_08(void)
{
    char ch;
    int count = 1;

    do
    {
        printf("알파벳 입력 : ");
        ch = getche();
        printf("\n");
    } while (toupper(ch) <= 'A' || toupper(ch) >= 'Z');

    for (toupper(ch); toupper(ch) <= 'Z'; ch++)
    {
        printf("%3c%c", toupper(ch), (count++ % 5) ? ' ' : '\n');
    }
}

void ex_09(void)
{
    char ch;

    do
    {
        printf("k이하의 알파벳입력(q는 종료, k이상은 다시 입력) : ");
        ch = getche();
        if (ch < 'k')
        {
            printf("\n");
            for (char msg = 'a'; msg <= ch; msg++)
            {
                printf("%c", msg);
            }
        }
        printf("\n");

    } while (ch != 'q');
    printf("q입력으로 종료");
}

void ex_10(void)
{
    char ch;
    int count = 0;

    do
    {
        printf("문자입력(알파벳과 숫자 이외의 문자 입력 시 종료) : ");
        ch = getche();
        if ((ch >= 'a') && (ch <= 'z'))
        {
            printf("\n소문자입니다\n");
        }
        else if ((ch >= 'A') && (ch <= 'Z'))
        {
            printf("\n대문자입니다\n");
        }
        else if ((ch >= '0') && (ch <= '9'))
        {
            count += (ch - '0');
            printf("\n숫자입니다. 지금까지 숫자들의 합=%d\n", count);
        }
        else
        {
            break;
        }
    } while (1);

    printf("\n알파벳과 숫자 이외의 문자를 입력하여 종료합니다.");
}

void ex_11(void)
{

    for (int i = 0; i <= 7; i++) //행
    {
        for (int j = -7; j <= 7; j++) //열
        {
            if (abs(j) > i)
            {
                printf("%c", ' ');
            }
            else
                printf("%d", abs(j));
        }
        printf("\n");
    }
}

void ex_12(void)
{
    int in;
    char ch, dis;

    printf("반복횟수입력: ");
    scanf("%d", &in);

    for (int i = 0; i < in; i++)
    {
        printf("\n문자입력: ");
        ch = getche();

        if(i==0){
            dis=ch;
        }

        if (abs(tolower(ch)-'m')<abs(dis-'m'))
        {
            dis = ch;
        }
    }

    printf("\n\nm과 가장 가까운 문자는 = %c", dis);
}

int main()
{
    //ex_01();
    //ex_02();
    //ex_03();
    //ex_04();
    //ex_05();
    //ex_06();
    //ex_07();
    //ex_08();
    //ex_09();
    //ex_10();
    //ex_11();
    ex_12();

    return 0;
}