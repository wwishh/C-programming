#include <stdio.h>
#include <conio.h>
#include <string.h>

struct fruit
{
    char name[20]; //과일이름 name(문자열),
    double price;  //단가
    int sales;     //판매량
};
typedef struct fruit fruit;

void input_datas(fruit *wdatas, int len)
{

    fruit *p;
    p = wdatas;
    puts(">>Before input_datas");
    for (int i = 0; i < len; i++)
    {
        printf("과일종류 : ");
        gets((p + i)->name);
        printf("단가 : ");
        scanf("%lf", &(p + i)->price);
        printf("판매량 : ");
        scanf("%d", &(p + i)->sales);
        while (getchar() != '\n')
            ; //버퍼에 저장되어 있는 값 삭제
        puts("");
    }
}

void print_datas(fruit *datas, int len)
{
    fruit *p;
    p = datas;

    printf("==========================\n");
    printf("과일\t단가\t판매량\n");
    printf("==========================\n");
    for (int i = 0; i < len; i++)
    {
        printf("%s\t%.2lf\t%d\n", (p + i)->name, (p + i)->price, (p + i)->sales);
    }
    printf("==========================\n");
}

void write_file(fruit *wdatas, int len, char *argv)
{
    FILE *fp;

    puts(">>Before write_file");
    fp = fopen(argv, "wb");
    fwrite(wdatas, sizeof(wdatas), 1, fp);
    fclose(fp);
}

void read_file(fruit *rdatas, int len, char *argv)
{
    FILE *fp;

    puts(">>After write_file");
    puts(">>Before read_file");
    fp = fopen(argv, "rb");
    fread(rdatas, sizeof(rdatas), 1, fp);
    fclose(fp);
}

int total_amount(fruit *rdatas, int len)
{
    fruit *p;

    puts(">>Before 총 판매금액");
    int total = 0;
    p = rdatas;
    for (int i = 0; i < len; i++)
    {
        total += (p + i)->price * (p + i)->sales;
    }

    return total;
}

void ex_09(int argc, char *argv[])
{
    fruit datas[3];

    int len = sizeof(datas) / sizeof(fruit);

    input_datas(datas, len);
    puts(">>After input_datas");
    print_datas(datas, len);

    write_file(datas, len, argv[1]);

    read_file(datas, len, argv[1]);
    puts(">>After read_file");
    print_datas(datas, len);

    int total = total_amount(datas, len);

    printf("총 판매금액 = %d\n", total);
}

int main(int argc, char *argv[])
{
    ex_09(argc, argv);

    return 0;
}