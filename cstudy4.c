#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void ex_01(void)
{
    int i;
    printf("정수를 입력하세요 : ");
    scanf("%d", &i);
    if (i % 2 == 0)
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
    int i;
    printf("정수를 입력하세요 : ");
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
        printf("숫자를 입력하세요 : ");
        scanf("%lf", &dou);

        if (dou <= -100 || dou >= 100)
        {
            break;
        }

        sum += dou;
    } while (1);
    printf("-100이상 100이하 숫자들의 합 = %.2lf", sum);
}

void ex_04(void)
{
    char ch;
    printf("문자를 입력하세요 : ");
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
    printf("정수를 입력하세요 : ");
    scanf("%d", &i);
    printf("2진수는 = ");

    while (i >= 1)
    {
        bit = (i & 1) * place;
        binary += bit; //이진수
        place *= 10;   //자리수
        i = i >> 1;
    }
    printf("%d", binary);
}

void ex_06(void)
{
    int i, count = 0;
    printf("정수를 입력하세요 : ");
    scanf("%d", &i);
    printf("2진수로 만들 때 1이 나타나는 횟수 = ");
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
        printf("정수를 입력하세요 : ");
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