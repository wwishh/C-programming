#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[20];
    int age;
};
typedef struct student student;

void ex_01(int argc, char *argv[])
{
    student std[3], readfile, *p;
    FILE *fp;
    char filename[] = "student.data";
    char getname[20];

    printf("argv�� �����Դϴ�.\n");
    for (int i = 0; i < argc; i++)
    {
        printf("\targv[%d] = %s\n", i, argv[i]);
    }

    printf("std ����ü�� argv�� ������ ������(p)�� �̿��Ͽ� �����մϴ�.\n");
    p = std;

    for (int i = 1; i < sizeof(std) / sizeof(student); i++)
    {
        if (i % 2 == 0)
        {
            *(p + i)->name = *argv[i];
        }
        else
        {
            *(p + i)->age = atoi(*argv[i]);
        }
    }

    printf("std ����ü�� argv�� ������ ������(p)�� �̿��Ͽ� ȭ�鿡 ����մϴ�.\n");
    for (int i = 0; i < sizeof(std) / sizeof(student); i++)
    {
        printf("name = %s, age= %d\n", (p + i)->name, (p + i)->age);
    }

    printf("� �̸��� �����͸� %s���Ͽ� �����ұ��? ", filename);
    gets(getname);

    printf("%s�� %s�� ���õ� ������ ����մϴ�.\n", filename, getname);

    fp = fopen(filename, "wb");
    for (int i = 0; i < sizeof(std) / sizeof(student); i++)
    {
        if ((p + i)->name == getname)
        {
            fwrite(p, sizeof(p), 1, fp);
        }
    }

    fclose(fp);

    printf("%s�� ����� ������ �о� ����մϴ�.\n", filename);
    fp = fopen(filename, "rb");
    fread(p, sizeof(p), 1, fp);
    fclose(fp);
}

int main(int argc, char *argv[])
{
    ex_01(argc, argv);
    return 0;
}