#include <stdio.h>
#include <conio.h>

void ex_04(void)
{
    char str[50];
    int i;

    while (1)
    {
        printf("���ڿ��Է� : ");
        gets(str);

        if (str[0] == '\0')
        {
            printf("<EnterŰ>");
            break;
        }

        for (i = 0; str[i]; i++)
            ;
        printf("    �Էµ� ���ڿ��� ���� =%d\n", i);
    }
}

void ex_05(void)
{
    char str[50], ch;
    int count = 0;

    while (1)
    {
        printf("���ڿ��Է� : ");
        gets(str);
        if (str[0] == '\0')
        {
            printf("<EnterŰ>");
            break;
        }

        printf("�����Է� : ");
        ch = getche();
        printf("\n");
        for (int i = 0; str[i]; i++)
        {
            if (str[i] == ch)
            {
                count++;
            }
        }
        printf("%s���� %c�� %d��.\n", str, ch, count);
        count = 0;
    }
}

void ex_06(void)
{
    char stra[50], strb[50];
    int i;

    printf("���ڿ��Է� : ");
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
    printf("c_07_���ÿ�_20175319\n");

    int from[4], sum, max, min;

    for (int i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        printf("���� �Է� : ");
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
    printf("�� = %d\n", sum);
    printf("���� ū �� = %d\n", max);
    printf("���� ���� �� = %d\n", min);
}

void ex_11(void)
{
    printf("c_07_���ÿ�_20175319\n");

    char x[100];
    int count[5] = {0}, i = 0, max = 0, maxindex = 0;

    printf("0���� 4������ ���� �Է� : ");
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
    printf("\n���� ���� �Է� ���� �� = %d\n", maxindex);
    printf("\n�Է� Ƚ�� = %d\n", count[maxindex]);
}

void ex_12(void)
{
    printf("c_07_���ÿ�_20175319\n");
    char ch[33];
    int i = 0, num;

    while (1)
    {
        printf("���� �Է� : ");
        scanf("%d", &num);
        if (num == 0)
            break;
        printf("�Էµ� %d�� �������� ", num);
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