#include <stdio.h>
#define PI 3.141592

void ex_01(void)
{
    char c1, c2;

    c1 = '1';
    c2 = 1;
    printf("c1 = %c, c2= %c\n", c1, c2);
}//문자1은 1그대로를 출력하고 정수1은 아스키코드에서 1에 해당하는 값을 출력한다

void ex_02(void)
{
    char c1, c2, c3, c4;
    c1 ='a';
    c2 = 'A';
    c3 = '0';
    c4 = '1';

    printf("('a' - 'A') = %d\n",(c1-c2));
    printf("('0' - '1') = %d\n",(c3-c4));
}//위 문자가 더 크다 문자를 아스키코드로 변환하여 출력한 결과이다

void ex_03(void)
{
    int in;
    printf("정수 입력 : ");
    scanf("%d", &in);

    printf("8진수=%#0o, 10진수=%d, 16진수=%#x \n", in, in, in);
}

void ex_04(void)
{
    char ch;
    printf("문자 입력 : ");
    scanf("%c", &ch);
    printf("8진수=%#0o, 10진수=%d, 16진수=%#x", ch, ch, ch);
} //문자를 8진수, 10진수, 16진수로 나타내면 그 문자에 해당하는 아스키코드의 값을 출력한다

void ex_05(void)
{
    double dou;

    printf("실수를 입력하세요 : ");
    scanf("%lf", &dou);
    printf("입력하신 실수를 소수 한자리만 출력하면 : %.1lf", dou);
}

void ex_06(void)
{
    double mid, last;

    printf("중간고사 성적 입력 : ");
    scanf("%lf", &mid);
    printf("기말고사 성적 입력 : ");
    scanf("%lf", &last);
    printf("합 = %-10.3lf\n", (mid + last));
    printf("평균 = %-10.3lf", ((mid + last) / 2));
}

void ex_07(void)
{
    double dou;
    printf("원반지름입력 : ");
    scanf("%lf", &dou);
    printf("원반지름 : %.2lf\n", dou);
    printf("원면적 : %.2lf\n", (PI * dou * dou));
    printf("원둘레 : %.2lf\n", (2 * PI * dou));
}

void ex_08(void)
{
    printf("char의 크기 : %d\n", sizeof(char));
    printf("short의 크기 : %d\n", sizeof(short));
    printf("int의 크기 : %d\n", sizeof(int));
    printf("float의 크기 : %d\n", sizeof(float));
    printf("int의 크기 : %d\n", sizeof(double));
}
int main()
{
    //ex_01();
    ex_02();
    //ex_03();
    //ex_04();
    //ex_05();
    //ex_06();
    //ex_07();
    //ex_08();
    return 0;
}