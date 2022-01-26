#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//파일입출력, 구조체, 함수 모두 응용한 문제

struct unit
{
    int goods_num;
    char goods[3];
    int client;
    int price;
    int sales;
};
typedef struct unit unit;

int read_file(unit *datalist, char *filename)
{
    FILE *fp;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("%s Can't open file", filename);
        exit(1);
    }
    while (1)
    {
        fscanf(fp, "%8d", &(datalist + i)->goods_num);
        fscanf(fp, "%s", (datalist + i)->goods);
        fscanf(fp, "%6d", &(datalist + i)->client);
        fscanf(fp, "%5d", &(datalist + i)->price);
        fscanf(fp, "%3d", &(datalist + i)->sales);

        if (feof(fp))
            break;
        i++;
    }
    fclose(fp);
    return i;
}

void printf_datalist(unit *datalist, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%8d ", (datalist + i)->goods_num);
        printf("%s ", (datalist + i)->goods);
        printf("%6d ", (datalist + i)->client);
        printf("%5d ", (datalist + i)->price);
        printf("%3d\n ", (datalist + i)->sales);
    }
}

int total_amount(unit *datalist, int len){
    int total =0;

    for(int i=0;i<len;i++){
        total += ((datalist+i)->price *(datalist + i)->sales);
    }
    return total;
}

int goods_amount(unit *datalist, int len, char *goods){
    int total = 0;
    for(int i=0; i<len; i++){
        if(strcmp((datalist+i)->goods, goods)){
            total += ((datalist +i)->price *(datalist + i)->sales);
        }
    }
    return total;
}

int main(int argc, char *argv[])
{
    unit data[20];
    int len, total, total_AA;

    len = read_file(data, argv[1]);
    printf_datalist(data, len);

    total = total_amount(data, len);
    printf("\n총 판매금액 = %d\n", total);

    total_AA = goods_amount(data, len, "AA");
    printf("AA제품의 총 판매 금액 = %d\n", total_AA);

    printf("총 판매금액 대비 제품 AA 판매금액 비율 = %.2f\%%\n", (total_AA)/(double)total*100);

    return 0;
}