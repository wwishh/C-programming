#include <stdio.h>
#include <conio.h>

void ex_01(void)
{
    char ch[4];
    int i;
    for (i = 0; i <= 3; i++)
    {

        printf("�����Է� : ");
        ch[i] = getche();
        printf("\n");
    }
    printf("�Էµ� ���� = ");
    for (i = 0; i <= 3; i++)
        printf("%c", ch[i]);
}

void ex_02(void)
{
    char str[50];

    printf("���ڿ� �Է� : ");
    gets(str);
    printf("�Էµ� ���ڿ� = %s", str);
}

void ex_03(void)
{
    char str[50];
    int count = 0;
    printf("���ڿ� �Է� : ");
    gets(str);
    while (str[count] != '\0')
    {
        count++;
    }
    printf("    �Էµ� ���ڿ� ����=%d", count);
}

void ex_04(void)
{
    char str[50];
    int count = 0;
    while (1)
    {
        printf("���ڿ� �Է� : ");
        scanf("%s",str);
        while (str[count] != '\0')
        {
            count++;
        }
        printf("    �Էµ� ���ڿ��� ����=%d\n", count);
        if (str[0]=='\0')
        {
            printf("<Enter?>");
            break;
        }
        

    }
}



int main()
{
    //ex_01();
    ex_02();
    // ex_03();
    //ex_04();

    return 0;
}