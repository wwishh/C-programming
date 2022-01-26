#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

void ex_01(int argc, char *argv[])
{

    printf("argc= %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, *(argv + i));
    }
}

void ex_02(char *argv)
{

    printf("입력한 문자열에서 숫자는 -> ");
    while (*argv)
    {
        if (*argv >= '0' && *argv <= '9')
        {
            printf("%c", *argv);
        }
        argv++;
    }
}

void ex_03(char *argv[])
{

    int a = atoi(argv[1]);
    int b = atoi(argv[3]);

    char p = *argv[2];

    switch (p)
    {
    case '+':
        printf("-> %d %c %d = %d", a, p, b, a + b);
        break;
    case '-':
        printf("-> %d %c %d = %d", a, p, b, a - b);
        break;
    case '*':
        printf("-> %d %c %d = %d", a, p, b, a * b); //곱하기연산이 안됨
        break;
    case '/':
        printf("-> %d %c %d = %d", a, p, b, a / b);
        break;
    default:
        printf("-> 사칙연산만 가능합니다");
    }
}

void ex_04(char *argv)
{

    char stra[3][4] = {"천", "백", "십"};
    char strb[10][3] = {" ", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};
    int d = 1000;

    int s = atoi(argv);
    if (s >= 10000)
    {
        printf("10000보다 작은 수만 처리 합니다\n");
    }
    printf("입력한 정수는 [");
    for (int i = 0; s != 0; i++)
    {
        if (s / d)
        {
            printf("%s%s ", strb[s / d], stra[i]);
        }
        s = s % d;
        d = d / 10;
    }
    printf("]");
}

int maxx(int *p, int size)
{
    int tmp = *p;
    for (int i = 0; i < size; i++)
    {
        if (tmp < *(p + i))
        {
            tmp = *(p + i);
        }
    }

    return tmp;
}

void ex_05()
{
    int num[3];
    for (int i = 0; i < sizeof(num) / sizeof(int); i++)
    {
        printf("정수입력 : ");
        scanf("%d", &num[i]);
    }
    int max_value = maxx(num, sizeof(num) / sizeof(int));
    printf("max()에서 전달 받은 최댓값 = %d\n", max_value);
}

void ex_06(char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    int num[3] = {a, b, c};

    int max_value = maxx(num, sizeof(num) / sizeof(int));
    printf("max()에서 전달 받은 최댓값 = %d\n", max_value);
}

char *mystrcat(char *sa, char *sb, char *plus)
{
    strcat(sa, sb);
    strcpy(plus, sa);

    return plus;
}

void ex_07()
{
    char stra[50], strb[50], p[50], *mystrcat_value;

    printf("문자열 입력 : ");
    gets(stra);
    printf("문자열 입력 : ");
    gets(strb);

    mystrcat_value = mystrcat(stra, strb, p);
    printf("plus = %s", mystrcat_value);
}

void ex_08(char *stra, char *strb)
{
    char *p;
    char *mystrcat_value = mystrcat(stra, strb, p);
    printf("plus = %s", mystrcat_value);
}

double myabs(double dd)
{
    dd = fabs(dd);

    return dd;
}

void ex_09()
{
    double d;

    printf("실수 입력 : ");
    scanf("%lf", &d);
    double dou = myabs(d);
    printf("입력한 실수의 절대값 : %lf", dou);
}

int isprime(int n)
{
    int i;
    for (i = 2; (n % i) != 0; i++)
        ;

    if (i == n)
        return 1;
    else
        return 0;
}

void ex_10()
{
    int num;

    do
    {
        printf("2보다 큰 양의 정수 입력 : ");
        scanf("%d", &num);

    } while (num < 2);

    int isprime_value = isprime(num);

    if (isprime_value)
        printf("소수입니다.");
    else
        printf("소수가 아닙니다.");
}

int mystrlen(char *len)
{
    int i = strlen(len);

    return i;
}

void ex_11()
{
    char str[50];

    printf("문자열 입력 : ");
    gets(str);

    int len_value = mystrlen(str);
    printf("입력한 문자열의 길이 : %d", len_value);
}

int mystrchcnt(char *str, char ch)
{

    int cnt = 0;

    for (int i = 0; *(str + i); i++)
    {
        if (*(str + i) == ch)
        {
            cnt++;
        }
    }

    return cnt;
}

void ex_12()
{
    char str[50], ch;

    printf("문자열 입력 : ");
    gets(str);
    printf("문자 입력 : ");
    ch = getche();

    int mystrchcnt_value = mystrchcnt(str, ch);
    printf("\n%s에서 %c의 개수 : %d", str, ch, mystrchcnt_value);
}

char *mystrupper(char *sou, char *tar)
{

    tar = strupr(sou);

    return tar;
}

void ex_13()
{
    char source[50], target[50];

    printf("소문자 문자열 입력 : ");
    gets(source);

    char *result = mystrupper(source, target);

    printf("변환된 문자열 : %s", result);
}

int strcmp2dim(char *a, char *b)
{
    int i = strcmp(a, b);

    return i;
}

void ex_14()
{
    char str[2][50];

    printf("문자열 입력 : ");
    gets(str[0]);
    printf("문자열 입력 : ");
    gets(str[1]);

    int in = strcmp2dim(str[0], str[1]);

    if (in == 0)
        printf("문자열 같음");
    else
        printf("문자열 다름");
}

void mysort(int *ary, int *sortary)
{
    for(int i=0;i<5;i++){
        sortary[i]=ary[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sortary[j] > sortary[j+1])
            {
                int temp = sortary[j];
                sortary[j] = sortary[j+1];
                sortary[j+1] = temp;
            }
        }
    }
}

void ex_15(char *argv[])
{
    int ary[5], sortary[5];

    for(int i=0; i<5;i++){
        ary[i] = atoi(argv[i+1]);
    }

    mysort(ary, sortary);

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", ary[i]);
    }
    printf("\n");
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", sortary[i]);
    }
}

int main(int argc, char *argv[])
{

    //ex_01(argc, argv);
    //ex_02(argv[1]);
    //ex_03(argv);
    //ex_04(argv[1]);
    //ex_05();
    //ex_06(argv);
    //ex_07();
    //ex_08(argv[1], argv[2]);
    //ex_09();
    //ex_10();
    //ex_11();
    //ex_12();
    //ex_13();
    //ex_14();
    /*if((argc-1)!=5){
        printf("정수 다섯 개를 입력해 주세요.");
        exit(0);
    }
    ex_15(argv);*/

    return 0;
}