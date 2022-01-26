#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

void ex_01(void)
{
    int in;

    printf("������ �Է��ϼ��� : ");
    scanf("%d", &in);

    if (in >= 0)
    {
        printf("����Դϴ�.");
    }
    else
    {
        printf("�����Դϴ�.");
    }
}

void ex_02(void)
{
    int in;

    printf("������ �Է��ϼ��� : ");
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
        printf("���ڸ� �Է��ϼ��� : ");
        scanf("%lf", &dou);
    }

    printf("-100�̻� 100���� ���ڵ��� �� = %.2lf", sum);
}

void ex_04(void)
{
    char ch;

    printf("���ڸ� �Է��ϼ��� : ");
    while (tolower(ch) != 'q')
    {
        ch = getche();
    }
}

void ex_05(void)
{
    int in, bin1 = 0, bin2 = 0, place = 1;

    printf("������ �Է��ϼ��� : ");
    scanf("%d", &in);

    while (in >= 1)
    {
        bin1 = (in % 2) * place;
        bin2 += bin1;
        place *= 10;
        in /= 2;
    }
    printf("2������ = %d", bin2);
}

void ex_06()
{
    int in, count = 0;

    printf("������ �Է��ϼ��� : ");
    scanf("%d", &in);

    while (in >= 1)
    {
        if (in & 1)
        {
            count++;
        }
        in = in >> 1;
    }
    printf("2������ ���� �� 1�� ��Ÿ���� Ƚ�� = %d", count);
}

void ex_07(void)
{
    int in, count = 1;

    do
    {
        printf("������ �Է��ϼ��� : ");
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
        printf("���ĺ� �Է� : ");
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
        printf("k������ ���ĺ��Է�(q�� ����, k�̻��� �ٽ� �Է�) : ");
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
    printf("q�Է����� ����");
}

void ex_10(void)
{
    char ch;
    int count = 0;

    do
    {
        printf("�����Է�(���ĺ��� ���� �̿��� ���� �Է� �� ����) : ");
        ch = getche();
        if ((ch >= 'a') && (ch <= 'z'))
        {
            printf("\n�ҹ����Դϴ�\n");
        }
        else if ((ch >= 'A') && (ch <= 'Z'))
        {
            printf("\n�빮���Դϴ�\n");
        }
        else if ((ch >= '0') && (ch <= '9'))
        {
            count += (ch - '0');
            printf("\n�����Դϴ�. ���ݱ��� ���ڵ��� ��=%d\n", count);
        }
        else
        {
            break;
        }
    } while (1);

    printf("\n���ĺ��� ���� �̿��� ���ڸ� �Է��Ͽ� �����մϴ�.");
}

void ex_11(void)
{

    for (int i = 0; i <= 7; i++) //��
    {
        for (int j = -7; j <= 7; j++) //��
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

    printf("�ݺ�Ƚ���Է�: ");
    scanf("%d", &in);

    for (int i = 0; i < in; i++)
    {
        printf("\n�����Է�: ");
        ch = getche();

        if(i==0){
            dis=ch;
        }

        if (abs(tolower(ch)-'m')<abs(dis-'m'))
        {
            dis = ch;
        }
    }

    printf("\n\nm�� ���� ����� ���ڴ� = %c", dis);
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