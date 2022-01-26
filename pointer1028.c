#include <stdio.h>

void ex_01(void)
{
    char str[50];
    char *ch;

    printf("c_09_위시온_20175319\n");

    printf("문자열 입력 : ");
    gets(str);

    ch = str;

    printf("%s", ch);
}

void ex_02(void)
{
    int num[5];
    int *in;

    printf("c_09_위시온_20175319\n");

    for (int i = 0; i < (sizeof(num) / sizeof(int)); i++)
    {

        printf("정수 입력 : ");
        scanf("%d", &num[i]);
    }
    in = num;

    for (int i = 0; i < (sizeof(num) / sizeof(int)); i++)
        printf("%3d", *(in+i));
}

int main()
{
    //ex_01();
    ex_02();

    return 0;
}