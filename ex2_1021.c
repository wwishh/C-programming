#include <stdio.h>
#define PI 3.141592

void ex_01(void)
{
    char c1, c2;

    c1 = '1';
    c2 = 1;
    printf("c1 = %c, c2= %c\n", c1, c2);
}//����1�� 1�״�θ� ����ϰ� ����1�� �ƽ�Ű�ڵ忡�� 1�� �ش��ϴ� ���� ����Ѵ�

void ex_02(void)
{
    char c1, c2, c3, c4;
    c1 ='a';
    c2 = 'A';
    c3 = '0';
    c4 = '1';

    printf("('a' - 'A') = %d\n",(c1-c2));
    printf("('0' - '1') = %d\n",(c3-c4));
}//�� ���ڰ� �� ũ�� ���ڸ� �ƽ�Ű�ڵ�� ��ȯ�Ͽ� ����� ����̴�

void ex_03(void)
{
    int in;
    printf("���� �Է� : ");
    scanf("%d", &in);

    printf("8����=%#0o, 10����=%d, 16����=%#x \n", in, in, in);
}

void ex_04(void)
{
    char ch;
    printf("���� �Է� : ");
    scanf("%c", &ch);
    printf("8����=%#0o, 10����=%d, 16����=%#x", ch, ch, ch);
} //���ڸ� 8����, 10����, 16������ ��Ÿ���� �� ���ڿ� �ش��ϴ� �ƽ�Ű�ڵ��� ���� ����Ѵ�

void ex_05(void)
{
    double dou;

    printf("�Ǽ��� �Է��ϼ��� : ");
    scanf("%lf", &dou);
    printf("�Է��Ͻ� �Ǽ��� �Ҽ� ���ڸ��� ����ϸ� : %.1lf", dou);
}

void ex_06(void)
{
    double mid, last;

    printf("�߰���� ���� �Է� : ");
    scanf("%lf", &mid);
    printf("�⸻��� ���� �Է� : ");
    scanf("%lf", &last);
    printf("�� = %-10.3lf\n", (mid + last));
    printf("��� = %-10.3lf", ((mid + last) / 2));
}

void ex_07(void)
{
    double dou;
    printf("���������Է� : ");
    scanf("%lf", &dou);
    printf("�������� : %.2lf\n", dou);
    printf("������ : %.2lf\n", (PI * dou * dou));
    printf("���ѷ� : %.2lf\n", (2 * PI * dou));
}

void ex_08(void)
{
    printf("char�� ũ�� : %d\n", sizeof(char));
    printf("short�� ũ�� : %d\n", sizeof(short));
    printf("int�� ũ�� : %d\n", sizeof(int));
    printf("float�� ũ�� : %d\n", sizeof(float));
    printf("int�� ũ�� : %d\n", sizeof(double));
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