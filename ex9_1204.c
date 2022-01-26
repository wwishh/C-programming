#include <stdio.h>
#include <conio.h>
#include <string.h>

void ex_01()
{
    FILE *fp;
    char ch;

    fp = fopen("chars.txt", "w");

    printf("문자 입력('q'이면 종료) : ");
    do
    {
        ch = getche();
        if (ch == 'q')
        {
            break;
        }
        fprintf(fp, "%c", ch);

    } while (1);

    printf("\nchars.txt 파일에 저장했습니다.");

    fclose(fp);
}

void ex_02()
{
    FILE *fp;
    char ch;

    fp = fopen("chars.txt", "r");

    printf("\nchars.txt 파일을 읽습니다.\n");
    do
    {
        fscanf(fp, "%c", &ch);
        if (feof(fp))
        { //지금읽은 것이 eof인지 확인, 코드순서 유의(fscanf 먼저실행)
            break;
        }
        printf("%c", ch);
    } while (1);

    fclose(fp);
}

void ex_03()
{
    FILE *fp;
    char str[50];
    fp = fopen("strings.txt", "w");

    do
    {
        printf("문자열 입력 : ");
        gets(str);

        if (str[0] == '\0')
        {
            break;
        }
        fprintf(fp, "%s\n", str);

    } while (1);

    printf("입력하신 문자열을 strings.txt로 저장했습니다.");

    fclose(fp);
}

void ex_04()
{
    FILE *fp;
    char str[50];

    fp = fopen("strings.txt", "r");
    printf("strings.txt를 읽습니다.\n");
    do
    {
        fgets(str, 49, fp);
        if (feof(fp))
        { //지금읽은 것이 끝인지 확인, 코드순서 유의
            break;
        }
        printf("%s", str);
    } while (1);

    fclose(fp);
}

void ex_05()
{
    FILE *fpa, *fpb;
    char stra[50], strb[50];

    fpa = fopen("chars.txt", "r");
    fpb = fopen("strings.txt", "r");
    printf("chars.txt를 열었습니다.\n");
    printf("strings.txt를 열었습니다.\n");

    fscanf(fpa, "%s", stra);
    fscanf(fpb, "%s", strb);

    if (strcmp(stra, strb) == 0)
    {
        printf("같습니다.");
    }
    else
    {
        printf("다릅니다.");
    }

    fclose(fpa);
    fclose(fpb);
}

void ex_06()
{
    FILE *fp1, *fp2;
    char str[50];

    fp1 = fopen("strings.txt", "r");
    printf("strings.txt를 열었습니다.\n");
    fp2 = fopen("samestrings.txt", "w");
    printf("samestrings.txt를 열었습니다.\n");

    do
    {
        fgets(str, 49, fp1);
        if (feof(fp1))
        { //지금읽은 것이 끝인지 확인, 코드순서 유의
            break;
        }
        printf("%s", str);
        fprintf(fp2, "%s", str);
    } while (1);

    printf("strings.txt의 내용을 samestrings.txt에 복사했습니다.\n");
    fclose(fp2);

    fp2 = fopen("samestrings.txt", "r");
    printf("\nsamestrings.txt를 읽습니다.\n");
    do
    {
        fgets(str, 49, fp2);
        if (feof(fp2))
        { //지금읽은 것이 끝인지 확인, 코드순서 유의
            break;
        }
        printf("%s", str);
    } while (1);

    fclose(fp1);
    fclose(fp2);
}

void ex_07()
{
    double doo[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    FILE *fp;

    for (int i = 0; i < sizeof(doo) / sizeof(double); i++)
    {
        printf("%lf ", doo[i]);
    }

    fp = fopen("doubles.data", "wb");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        return;
    }
    printf("\ndoubles.data를 열었습니다.\n");

    fwrite(doo, sizeof(doo), 1, fp);
    if (ferror(fp))
    {
        printf("file write error");
        return;
    }
    printf("\ndouble형 배열의 내용을 출력했습니다.\n");
    fclose(fp);
}

void ex_08()
{
    FILE *fp;
    double doo[5], one;

    fp = fopen("doubles.data", "rb");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        return;
    }
    printf("\ndoubles.data를 얻었습니다.\n");

    fread(doo, sizeof(doo), 1, fp);
    if (ferror(fp))
    {
        printf("file read error\n");
        return;
    }

    for (int i = 0; i < sizeof(doo) / sizeof(double); i++)
    {
        printf("%.1lf ", doo[i]);
    }
    printf("\ndouble형 배열의 내용을 출력했습니다.\n");
    printf("\nftell = %d\n", ftell(fp));

    printf("\ndoubles.data의 마지막 데이터에 접근 합니다.\n");
    fseek(fp, sizeof(double) * (-1), SEEK_END);
    printf("\nftell = %d\n", ftell(fp));

    fread(&one, sizeof(one), 1, fp);
    printf("\n마지막에 저장된 double 값 = %.1lf\n", one);
    fclose(fp);
}

struct fruit
{
    char name[20]; //과일이름 name(문자열),
    double price;  //단가
    int sales;     //판매량
};
typedef struct fruit fruit;

void ex_09(int argc, char *argv[])
{
    fruit wdatas[3], rdatas[3], *p;
    FILE *fp;
    int len = sizeof(wdatas) / sizeof(fruit);
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
    puts(">>After input_datas");
    printf("==========================\n");
    printf("과일\t단가\t판매량\n");
    printf("==========================\n");
    for (int i = 0; i < len; i++)
    {
        printf("%s\t%.2lf\t%d\n", (p + i)->name, (p + i)->price, (p + i)->sales);
    }
    printf("==========================\n");
    puts(">>Before write_file");
    fp = fopen(argv[1], "wb");
    fwrite(wdatas, sizeof(wdatas), 1, fp);
    fclose(fp);
    puts(">>After write_file");
    puts(">>Before read_file");
    fp = fopen(argv[1], "rb");
    fread(rdatas, sizeof(rdatas), 1, fp);
    fclose(fp);
    puts(">>After read_file");
    p = rdatas;
    printf("==========================\n");
    printf("과일\t단가\t판매량\n");
    printf("==========================\n");
    for (int i = 0; i < len; i++)
    {
        printf("%s\t%.2lf\t%d\n", (p + i)->name, (p + i)->price, (p + i)->sales);
    }
    printf("==========================\n");
    puts(">>Before 총 판매금액");
    int total = 0;
    p = rdatas;
    for (int i = 0; i < len; i++)
    {
        total += (p + i)->price * (p + i)->sales;
    }
    printf("총 판매금액 = %d\n", total);
}

int main(int argc, char *argv[])
{
    //ex_01();
    //ex_02();
    //ex_03();
    //ex_04();
    //ex_05();
    ex_06();
    //ex_07();
    //ex_08();
    //ex_09(argc, argv);
    //ex_10();

    return 0;
}