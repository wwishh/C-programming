#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void ex_01(void)
{
    int i;
    printf("������ �Է��ϼ��� : ");
    scanf("%d", &i);
    if (i % 2 == 0)
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
    int i;
    printf("������ �Է��ϼ��� : ");
    scanf("%d", &i);

    switch (i / 2 > 10)
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

    do
    {
        printf("���ڸ� �Է��ϼ��� : ");
        scanf("%lf", &dou);

        if (dou <= -100 || dou >= 100)
        {
            break;
        }

        sum += dou;
    } while (1);
    printf("-100�̻� 100���� ���ڵ��� �� = %.2lf", sum);
}

void ex_04(void)
{
    char ch;
    printf("���ڸ� �Է��ϼ��� : ");
    while (1)
    {

        ch = getche();
        if (tolower(ch) == 'q')
        {
            break;
        }
    }
}

void ex_05(void)
{
    int i, bit = 0, binary = 0, place = 1;
    printf("������ �Է��ϼ��� : ");
    scanf("%d", &i);
    printf("2������ = ");

    while (i >= 1)
    {
        bit = (i & 1) * place;
        binary += bit; //������
        place *= 10;   //�ڸ���
        i = i >> 1;
    }
    printf("%d", binary);
}

void ex_06(void)
{
    int i, count = 0;
    printf("������ �Է��ϼ��� : ");
    scanf("%d", &i);
    printf("2������ ���� �� 1�� ��Ÿ���� Ƚ�� = ");
    while (i >= 1)
    {
        if ((i & 1) == 1)
            count++;

        i = i >> 1;
    }

    printf("%d", count);
}

void ex_07(void)
{
    int i, count=0;

    do
    {
        printf("������ �Է��ϼ��� : ");
        scanf("%d", &i);
    }while(i<=9);

for(int num = 10; num <= i; num++){

    for(int j=2; (num%j)!=0 ; j++)


    if(j==num){
        printf("%d%c", num, (++count%10? ' ':'\n'));
    }
}
}

int main()
{
    //ex_01();
    //ex_02();
    //ex_03();
    //ex_04();
    //ex_05();
    //ex_06();
    ex_07();

    return 0;
}