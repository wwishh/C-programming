#include <stdio.h>
#include <conio.h>

void ex_01(void)
{
    int x, count, money;

    printf("10000������ �ݾ��� �Է��� �ּ��� : ");
    scanf("%d", &x);

    money = (x > 0 && x <= 10000) ? x : 0;

    printf("Ŀ�� �� �� �帱���? ");
    scanf("%d", &x);
    count = (x > 0 && x <= 8) ? x : 0;

    x = money - (count * 1200);

    printf("�Ž��� �� �Դϴ�.\n");
    printf("5000���� %d��\n", x / 5000);
    printf("1000���� %d��\n", x % 5000 / 1000);
    printf("500�� ���� %d��\n", x % 1000 / 500);
    printf("100�� ���� %d��\n", x % 500 / 100);
}

void ex_02(void)
{
    int a, b, max, min;

    printf("���� �� ���� �Է��ϼ��� : ");
    scanf("%d", &a);
    scanf("%d", &b);

    max = a > b ? a : b;
    min = a < b ? a : b;

    printf("ū �� = %d\n", max);
    printf("���� �� = %d\n", min);
    printf("ū ���� ���� ���� ���� ��� ������ = %d, %d", max / min, max % min);
}

void ex_03(void)
{
    char ch;

    printf("���ڸ� �Է��ϼ��� : ");
    ch = getche();

    ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ? printf(" -> Y") : printf(" -> N");
}

void ex_04(void)
{
    char ch;
    int a, b;

    printf("���ڸ� �Է��ϼ��� : ");
    ch = getche();
    a = (ch >= '0' && ch <= '9') ? (ch - '0') : 1;

    printf("\n���ڸ� �Է��ϼ��� : ");
    ch = getche();
    b = (ch >= '0' && ch <= '9') ? (ch - '0') : 1;

    printf("\n�� ���� ���� = %d", (a*b));
}

void ex_05(void){
    int in;

    printf("������ �Է��ϼ��� : ");
    scanf("%d", &in);

    printf("2�� = %d\n", in<<1);
    printf("4�� = %d\n", in<<2);
    printf("8�� = %d\n", in<<3);
}

void ex_06(void){
    int in;

    printf("������ �Է��ϼ��� : ");
    scanf("%d", &in);
    ((in>>1) >10) ? printf("OK"):printf("NOK"); 
}

void ex_07(void){
    int in;

    printf("������ �Է��ϼ��� : ");
    scanf("%d", &in);
    (in>>31)==0? printf("����Դϴ�."):printf("�����Դϴ�.");

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
}