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

    printf("argv의 내용입니다.\n");
    for (int i = 0; i < argc; i++)
    {
        printf("\targv[%d] = %s\n", i, argv[i]);
    }

    printf("std 구조체에 argv의 내용을 포인터(p)를 이용하여 저장합니다.\n");
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

    printf("std 구조체에 argv의 내용을 포인터(p)를 이용하여 화면에 출력합니다.\n");
    for (int i = 0; i < sizeof(std) / sizeof(student); i++)
    {
        printf("name = %s, age= %d\n", (p + i)->name, (p + i)->age);
    }

    printf("어떤 이름의 데이터를 %s파일에 저장할까요? ", filename);
    gets(getname);

    printf("%s에 %s와 관련된 내용을 출력합니다.\n", filename, getname);

    fp = fopen(filename, "wb");
    for (int i = 0; i < sizeof(std) / sizeof(student); i++)
    {
        if ((p + i)->name == getname)
        {
            fwrite(p, sizeof(p), 1, fp);
        }
    }

    fclose(fp);

    printf("%s에 저장된 내용을 읽어 출력합니다.\n", filename);
    fp = fopen(filename, "rb");
    fread(p, sizeof(p), 1, fp);
    fclose(fp);
}

int main(int argc, char *argv[])
{
    ex_01(argc, argv);
    return 0;
}