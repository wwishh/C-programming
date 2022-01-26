#include <stdio.h>

void ex_01(void)
{

    double source[] = {1.21, 3.43, 5.65, 7.87, 8.98}, target[0], *sou, *tar;

    sou = source;
    tar = target;

    printf("source = ");
    for (int i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        printf("%.2lf,\t", *(sou + i));
    }

    printf("\ntarget = ");
    for (int i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        *(tar + i) = *(sou + i);
        printf("%.2lf,\t", *(tar + i));
    }
}

void ex_02(void)
{
    double source[] = {1.21, 3.43, 5.65, 7.87, 8.98}, *sou, dou;

    sou = source;

    printf("source = ");
    for (int i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        printf("%.2lf,\t", *(sou + i));
    }

    printf("\nsource 각 원소에 더할 값 입력 : ");
    scanf("%lf", &dou);

    printf("target = ");
    for (int i = 0; i < sizeof(source) / sizeof(double); i++)
    {
        printf("%.2lf,\t", *(sou + i) + dou);
    }
}

void ex_03(void)
{
    char str[50], *pstr;
    int i;

    pstr = str;

    printf("문자열 입력 : ");
    gets(pstr);

    for(i=0; *(pstr+i); i++);
    printf("\t입력된 문자열 길이=%d", i);


}

int main()
{

    //ex_01();
    ex_02();
    //ex_03();

    return 0;
}