#include <stdio.h>

void ex_01(void)
{
    int num[5];
    int size = sizeof(num) / sizeof(int);

    printf("�迭�� ���� �� : %d", size);
}

void ex_06(void)
{
    char stra[50], strb[50];
    int i = 0, count = -1;

    printf("���ڿ� �Է� : ");
    gets(stra);

    while (stra[i])
    {
        i++;
        count++;
    }

    for (i = 0; stra[i]; i++)
    {
        strb[count] = stra[i];
        count--;
    }
    strb[i] = '\0';
    printf("stra = %s\n", stra);
    printf("strb = %s", strb);
}

void ex_07(void)
{
    char stra[50], strb[50];
    int i, j;

    printf("���ڿ��Է� : ");
    gets(stra);
    printf("���ڿ��Է� : ");
    gets(strb);

    for (i = 0; stra[i]; i++)
        ;
    for (j = 0; strb[j]; j++)
        ;

    if (i == j)
    {
        i = 0;
        j = 0;
        while (stra[i])
        {
            if (stra[i] == strb[j])
            {
                i++;
                j++;
            }
            else
            {
                printf("%s, %s, �ٸ�.", stra, strb);
                break;
            }
        }
        if (stra[i] == strb[j])
        {
            printf("%s, %s, ����.", stra, strb);
        }
    }
    else
    {
        printf("%s, %s, �ٸ�.", stra, strb);
    }
}

void ex_09(void)
{
    int from[4], i, max, min, sum = 0;
    for (i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        printf("�����Է� : ");
        scanf("%d", &from[i]);
    }
    max = from[0];
    min = from[0];
    sum += from[0];
    for (i = 1; i < sizeof(from) / sizeof(int); i++)
    {
        sum += from[i];
        if (from[i] > max)
        {
            max = from[i];
        }

        if (from[i] < min)
        {
            min = from[i];
        }
    }

    printf("��=%d\n", sum);
    printf("���� ū ��=%d\n", max);
    printf("���� ���� ��=%d", min);
}

void ex_10(void)
{
    int from[4], to[4], i;
    for (i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        printf("�����Է� : ");
        scanf("%d", &from[i]);
        to[i] = from[i];
    }
    for (i = 0; i < sizeof(from) / sizeof(int); i++)
    {
        printf("from�迭: %d, to�迭:%d\n", from[i], to[i]);
    }
}

void ex_11(void)
{
    char str[50];
    int i = 0, count[5]={0}, max=0, maxnum=0;
    printf("0���� 4������ ���� �Է� : ");
    gets(str);
    while (str[i]){
        if(str[i]>='0'&&str[i]<='4'){
            ++count[str[i]-'0'];
        }
        i++;
    }
    for(i=0;i<5;i++){
        if(count[i]>max){
            max=count[i];
            maxnum=i;
        }
    }
    printf("���� ���� �Է� ���� �� = %d\n", maxnum);
    printf("�Է� Ƚ�� = %d", max);
}

void ex_12(void)
{

    char str[33];
    int i = 0, leng = 0, num, num2;

    printf("c_07_���ÿ�_20175319\n");

    while (1)
    {
        printf("�����Է� : ");
        scanf("%d", &num);
        num2 = num;

        if (num == 0)
        {
            break;
        }
        while (1)
        {

            if (num2 == 1)
            {
                str[i] = (num2 + '0');
                str[(i + 1)] = '\0';

                break;
            }
            str[i] = ((num2 % 2) + '0');
            i++;
            num2 = num2 / 2;
        }
        while (str[leng])
        {
            leng++;
        }
        printf("\t�Էµ� %d�� �������� ", num);
        for (leng - 1; leng >= 0; leng--)
        {
            printf("%c", str[leng]);
        }
        printf("\n");

        i = 0;
    }
}
int main()
{

    //ex_01();
    //ex_06();
    //ex_07();
    //ex_09();
    //ex_10();
    ex_11();
    //ex_12();
    return 0;
}
