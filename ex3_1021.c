#include <stdio.h>
#include <conio.h>

void ex_01(void)
{
    int x, count, money;

    printf("10000이하의 금액을 입력해 주세요 : ");
    scanf("%d", &x);

    money = (x > 0 && x <= 10000) ? x : 0;

    printf("커피 몇 잔 드릴까요? ");
    scanf("%d", &x);
    count = (x > 0 && x <= 8) ? x : 0;

    x = money - (count * 1200);

    printf("거스름 돈 입니다.\n");
    printf("5000원권 %d개\n", x / 5000);
    printf("1000원권 %d개\n", x % 5000 / 1000);
    printf("500원 동전 %d개\n", x % 1000 / 500);
    printf("100원 동전 %d개\n", x % 500 / 100);
}

void ex_02(void)
{
    int a, b, max, min;

    printf("정수 두 개를 입력하세요 : ");
    scanf("%d", &a);
    scanf("%d", &b);

    max = a > b ? a : b;
    min = a < b ? a : b;

    printf("큰 수 = %d\n", max);
    printf("작은 수 = %d\n", min);
    printf("큰 수를 작은 수로 나눈 몫과 나머지 = %d, %d", max / min, max % min);
}

void ex_03(void)
{
    char ch;

    printf("문자를 입력하세요 : ");
    ch = getche();

    ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ? printf(" -> Y") : printf(" -> N");
}

void ex_04(void)
{
    char ch;
    int a, b;

    printf("숫자를 입력하세요 : ");
    ch = getche();
    a = (ch >= '0' && ch <= '9') ? (ch - '0') : 1;

    printf("\n숫자를 입력하세요 : ");
    ch = getche();
    b = (ch >= '0' && ch <= '9') ? (ch - '0') : 1;

    printf("\n두 수의 곱은 = %d", (a*b));
}

void ex_05(void){
    int in;

    printf("정수를 입력하세요 : ");
    scanf("%d", &in);

    printf("2배 = %d\n", in<<1);
    printf("4배 = %d\n", in<<2);
    printf("8배 = %d\n", in<<3);
}

void ex_06(void){
    int in;

    printf("정수를 입력하세요 : ");
    scanf("%d", &in);
    ((in>>1) >10) ? printf("OK"):printf("NOK"); 
}

void ex_07(void){
    int in;

    printf("정수를 입력하세요 : ");
    scanf("%d", &in);
    (in>>31)==0? printf("양수입니다."):printf("음수입니다.");

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