#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void ex_01()
{
    double source[] = {1.21, 3.43, 5.65, 7.87, 8.98}, target[] = {0}, *p;
    p = source;
    int i = 0;

    for (i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        target[i] = *(p + i);
    }
    printf("source = ");
    for (i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        printf("%.2lf, ", source[i]);
    }
    printf("\ntarget = ");
    for (i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        printf("%.2lf, ", target[i]);
    }
}

void ex_02()
{
    double source[] = {1.21, 3.43, 5.65, 7.87, 8.98}, target[] = {0};
    double *sou, *tar, dou;

    sou = source;
    tar = target;

    printf("source = ");
    for (int i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        printf("%.2lf, ", *(sou + i));
    }
    printf("\nsource �� ���ҿ� ���� �� �Է� : ");
    scanf("%lf", &dou);

    printf("target = ");
    for (int i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        *(tar + i) = *(sou + i);
        printf("%.2lf, ", *(tar + i) + dou);
    }
}

void ex_03(void)
{
    char str[50], *ch;
    int i;

    ch = str;

    printf("���ڿ� �Է� : ");
    gets(ch);

    for (i = 0; *(ch + i); i++)
        ;

    printf("\t�Էµ� ���ڿ� ����=%d", i);
}

void ex_04(void)
{
    char str[50], *ch;
    int i;

    ch = str;

    while (1)
    {
        printf("���ڿ� �Է� : ");
        gets(ch);

        if (*ch == '\0')
        {
            printf("<EnterŰ>");
            break;
        }

        for (i = 0; *(ch + i); i++)
            ;

        printf("\t�Էµ� ���ڿ� ����=%d\n", i);
    }
}

void ex_05(void)
{
    char str[50], c, *ch;
    int count = 0;

    ch = str;

    while (1)
    {
        printf("���ڿ� �Է� : ");
        gets(ch);

        if (*ch == '\0')
        {
            printf("<EnterŰ>");
            break;
        }

        printf("���� �Է� : ");
        c = getche();

        for (int i = 0; *(ch + i); i++)
        {
            if (*(ch + i) == c)
            {
                count++;
            }
        }
        printf("\n\t%s���� %c�� %d��.\n", ch, c, count);
        count = 0;
    }
}

void ex_06(void)
{
    char stra[50], strb[50], *sa, *sb;

    sa = stra;
    sb = strb;

    printf("���ڿ� �Է� : ");
    gets(sa); //apple

    printf("���ڿ� �Է� : ");
    gets(sb); //banana

    printf("sa=%s, ", sa);
    printf("sa=%s", sb);

    while (*sa)
    {
        sa++;
    }

    while (*sb)
    {
        *sa = *sb;
        sa++;
        sb++;
    }
    *sa = '\0';

    printf("\nsa=sa+sb=%s, ", stra);
    printf("sb=%s", strb);
}

void ex_07(void)
{
    char stra[50], strb[50], *sa, *sb;

    sa = stra;
    sb = strb;

    printf("���ڿ� �Է� : ");
    gets(sa);

    while (*sa)
    {
        *sb = toupper(*sa);
        sa++;
        sb++;
    }
    *sb = '\0';

    printf("stra=%s, strb=%s", stra, strb);
}

void ex_08(void)
{
    char str[2][50], (*pstr)[50];
    int i;

    pstr = str;

    printf("���ڿ� �Է� : ");
    gets(pstr[0]);

    for (i = 0; *(*(pstr + 0) + i); i++)
    {
        (*(*(pstr + 1) + i)) = toupper(*(*(pstr + 0) + i));
    }
    (*(*(pstr + 1) + i)) = '\0';

    printf("str[0]=%s, ", str[0]);
    printf("str[1]=%s", str[1]);
}

void ex_09(void)
{
    char str[2][50], *p, *q;

    p = str[0];
    q = str[1];

    printf("���ڿ� �Է� : ");
    gets(p);
    printf("���ڿ� �Է� : ");
    gets(q);

    while (*p)
    {
        if (*p != *q)
        {
            break;
        }
        p++;
        q++;
    }
    if (*p == *q)
    {
        printf("%s, %s, ����.", str[0], str[1]);
    }
    else
    {
        printf("%s, %s, �ٸ�.", str[0], str[1]);
    }
}

void ex_10(void)
{
    char str[2][50];
    char *p, *q;
    int i = 0;

    p = str[0];
    q = str[1];

    while (1)
    {
        printf("���ڿ� �Է� : ");
        gets(p);

        if (*p == '\0')
            break;
        printf("���ڿ� �Է� : ");
        gets(q);

        while (*(p + i))
        {
            if (*(p + i) != *(q + i))
            {
                break;
            }
            i++;
        }

        if (*(p + i) == *(q + i))
        {
            printf("%s, %s, ����.\n", str[0], str[1]);
        }
        else
        {
            printf("%s, %s, �ٸ�.\n", str[0], str[1]);
        }
        i = 0;
    }
}

void ex_11(void)
{
    int from[4], i, *p;
    int sum = 0, max, min;

    for (i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        printf("�����Է� : ");
        scanf("%d", from + i);
    }
    p = from;
    max = min = *p;

    for (i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        sum += *p;
        if (max < *p)
        {
            max = *p;
        }
        if (min > *p)
        {
            min = *p;
        }
        p++;
    }

    printf("��=%d\n", sum);
    printf("���� ū ��=%d\n", max);
    printf("���� ���� ��=%d\n", min);
}

void ex_12()
{
    int from[4], to[4];
    int *p, *q;

    for (int i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        printf("�����Է� : ");
        scanf("%d", from + i);
    }
    p = from;
    q = to;

    for (int i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        *(q + i) = *(p + i);
        printf("from�迭: %d, to�迭:%d\n", *(p + i), *(q + i));
    }
}

void ex_13()
{
    char str[2][10];
    char *p, *q;
    int i, count=-1;

    p = str[0];
    q = str[1];

    printf("�� �ܾ �Է��ϼ��� : ");
    gets(p);

    for(i=0; *(p+i); i++) count++;

    for(i=0; *(p+i); i++)
    {
        *(q+i) = *(p+count);
        count--;
    }
    *(q+i) = '\0';

    printf("�Է��� �ܾ �ݴ�� ����մϴ� : %s", str[1]);
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
    //ex_12();
    //ex_13();

    return 0;
}