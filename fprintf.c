#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

struct unit
{
    char fruit[10];
    int price;
};
typedef struct unit unit;

int main(int argc, char *argv[])
{
    FILE *fp;
    unit list[SIZE] = {"apple", 800, "banana", 500, "orange", 600, "peach", 1000};

    fp = fopen(argv[1], "w");
    if (fp == NULL)
    {
        printf("%s Can't open file", argv[1]);
        exit(1);
    }
    for (int i = 0; i < sizeof(list) / sizeof(unit); i++)
    {
        fprintf(stdout, "%s %d\n", (list + i)->fruit, (list + i)->price);
        fprintf(fp, "%s %d\n", (list + i)->fruit, (list + i)->price);
    }
    fprintf(stdout, "\n모니터에 출력된 내용이 파일에 저장되었습니다.\n");
    fprintf(stdout, "%s 파일을 열어보세요.\n\n", argv[1]);

    fclose(fp);
    return 0;
}