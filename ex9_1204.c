#include <stdio.h>
#include <conio.h>
#include <string.h>

void ex_01()
{
    FILE *fp;
    char ch;

    fp = fopen("chars.txt", "w");

    printf("���� �Է�('q'�̸� ����) : ");
    do
    {
        ch = getche();
        if (ch == 'q')
        {
            break;
        }
        fprintf(fp, "%c", ch);

    } while (1);

    printf("\nchars.txt ���Ͽ� �����߽��ϴ�.");

    fclose(fp);
}

void ex_02()
{
    FILE *fp;
    char ch;

    fp = fopen("chars.txt", "r");

    printf("\nchars.txt ������ �н��ϴ�.\n");
    do
    {
        fscanf(fp, "%c", &ch);
        if (feof(fp))
        { //�������� ���� eof���� Ȯ��, �ڵ���� ����(fscanf ��������)
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
        printf("���ڿ� �Է� : ");
        gets(str);

        if (str[0] == '\0')
        {
            break;
        }
        fprintf(fp, "%s\n", str);

    } while (1);

    printf("�Է��Ͻ� ���ڿ��� strings.txt�� �����߽��ϴ�.");

    fclose(fp);
}

void ex_04()
{
    FILE *fp;
    char str[50];

    fp = fopen("strings.txt", "r");
    printf("strings.txt�� �н��ϴ�.\n");
    do
    {
        fgets(str, 49, fp);
        if (feof(fp))
        { //�������� ���� ������ Ȯ��, �ڵ���� ����
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
    printf("chars.txt�� �������ϴ�.\n");
    printf("strings.txt�� �������ϴ�.\n");

    fscanf(fpa, "%s", stra);
    fscanf(fpb, "%s", strb);

    if (strcmp(stra, strb) == 0)
    {
        printf("�����ϴ�.");
    }
    else
    {
        printf("�ٸ��ϴ�.");
    }

    fclose(fpa);
    fclose(fpb);
}

void ex_06()
{
    FILE *fp1, *fp2;
    char str[50];

    fp1 = fopen("strings.txt", "r");
    printf("strings.txt�� �������ϴ�.\n");
    fp2 = fopen("samestrings.txt", "w");
    printf("samestrings.txt�� �������ϴ�.\n");

    do
    {
        fgets(str, 49, fp1);
        if (feof(fp1))
        { //�������� ���� ������ Ȯ��, �ڵ���� ����
            break;
        }
        printf("%s", str);
        fprintf(fp2, "%s", str);
    } while (1);

    printf("strings.txt�� ������ samestrings.txt�� �����߽��ϴ�.\n");
    fclose(fp2);

    fp2 = fopen("samestrings.txt", "r");
    printf("\nsamestrings.txt�� �н��ϴ�.\n");
    do
    {
        fgets(str, 49, fp2);
        if (feof(fp2))
        { //�������� ���� ������ Ȯ��, �ڵ���� ����
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
    printf("\ndoubles.data�� �������ϴ�.\n");

    fwrite(doo, sizeof(doo), 1, fp);
    if (ferror(fp))
    {
        printf("file write error");
        return;
    }
    printf("\ndouble�� �迭�� ������ ����߽��ϴ�.\n");
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
    printf("\ndoubles.data�� ������ϴ�.\n");

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
    printf("\ndouble�� �迭�� ������ ����߽��ϴ�.\n");
    printf("\nftell = %d\n", ftell(fp));

    printf("\ndoubles.data�� ������ �����Ϳ� ���� �մϴ�.\n");
    fseek(fp, sizeof(double) * (-1), SEEK_END);
    printf("\nftell = %d\n", ftell(fp));

    fread(&one, sizeof(one), 1, fp);
    printf("\n�������� ����� double �� = %.1lf\n", one);
    fclose(fp);
}

struct fruit
{
    char name[20]; //�����̸� name(���ڿ�),
    double price;  //�ܰ�
    int sales;     //�Ǹŷ�
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
        printf("�������� : ");
        gets((p + i)->name);
        printf("�ܰ� : ");
        scanf("%lf", &(p + i)->price);
        printf("�Ǹŷ� : ");
        scanf("%d", &(p + i)->sales);
        while (getchar() != '\n')
            ; //���ۿ� ����Ǿ� �ִ� �� ����
        puts("");
    }
    puts(">>After input_datas");
    printf("==========================\n");
    printf("����\t�ܰ�\t�Ǹŷ�\n");
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
    printf("����\t�ܰ�\t�Ǹŷ�\n");
    printf("==========================\n");
    for (int i = 0; i < len; i++)
    {
        printf("%s\t%.2lf\t%d\n", (p + i)->name, (p + i)->price, (p + i)->sales);
    }
    printf("==========================\n");
    puts(">>Before �� �Ǹűݾ�");
    int total = 0;
    p = rdatas;
    for (int i = 0; i < len; i++)
    {
        total += (p + i)->price * (p + i)->sales;
    }
    printf("�� �Ǹűݾ� = %d\n", total);
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