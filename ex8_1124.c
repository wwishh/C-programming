#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct book
{
    char title[50];
    int price;
};
typedef struct book book;

void ex_01()
{
    book bk;

    printf("책 제목 : ");
    gets(bk.title);
    printf("가격 : ");
    scanf("%d", &bk.price);

    printf("book.title = %s, book.price = %d", bk.title, bk.price);
}

void ex_02()
{
    book bk[3];

    for (int i = 0; i < sizeof(bk) / sizeof(bk[0]); i++)
    {
        printf("%d) 책 제목 : ", i);
        gets(bk[i].title);
        printf("%d) 책 가격 : ", i);
        scanf("%d", &bk[i].price);

        while (getchar() != '\n')
            ; //문장이 엔터를 받을 때까지 입력버퍼에 남아있는 값을 읽어줌
    }

    for (int i = 0; i < sizeof(bk) / sizeof(bk[0]); i++)
    {
        printf("book[%d].title = %s, book[%d].price = %d\n", i, bk[i].title, i, bk[i].price);
    }
}

void ex_03()
{
    book bk[3], *p;

    p = bk;

    for (int i = 0; i < sizeof(bk) / sizeof(bk[0]); i++)
    {
        printf("%d) 책 제목 : ", i);
        gets((p + i)->title);
        printf("%d) 책 가격 : ", i);
        scanf("%d", &(p + i)->price);

        while (getchar() != '\n')
            ; //문장이 엔터를 받을 때까지 입력버퍼에 남아있는 값을 읽어줌
    }

    for (int i = 0; i < sizeof(bk) / sizeof(bk[0]); i++)
    {
        printf("(p+%d)->title = %s, (p+%d)->price = %d\n", i, (p + i)->title, i, (p + i)->price);
    }
}

struct date
{
    int year;
    int month;
    int day;
};
typedef struct date date;

struct fruit
{
    char name[20];
    int price;
    date expire;
    char throw;
};
typedef struct fruit fruit;

void ex_06()
{
    fruit any;
    int yyyymmdd;

    printf("과일이름 : ");
    gets(any.name);
    printf("가격 : ");
    scanf("%d", &any.price);

    while (getchar() != '\n')
        ;

    printf("만기일 : ");
    scanf("%d", &yyyymmdd);

    any.expire.year = yyyymmdd / 10000;
    any.expire.month = yyyymmdd % 10000 / 100;
    any.expire.day = yyyymmdd % 100;
    any.throw = 'n';

    printf("any.name = %s\n", any.name);
    printf("any.price = %d\n", any.price);
    printf("any.expire.year = %d\n", any.expire.year);
    printf("any.expire.month = %d\n", any.expire.month);
    printf("any.expire.day = %d\n", any.expire.day);
    printf("any.throw = %c\n", any.throw);
}

void ex_07()
{
    fruit store[5] = {
        "apple",
        500,
        2020,
        9,
        1,
        'n',
        "banana",
        500,
        2020,
        7,
        3,
        'n',
        "orange",
        500,
        2020,
        8,
        1,
        'n',
        "melon",
        500,
        2020,
        11,
        11,
        'n',
        "mango",
        500,
        2020,
        12,
        25,
        'n',
    };
    fruit *p;

    p = store;

    for (int i = 0; i < sizeof(store) / sizeof(store[0]); i++)
    {
        printf("%d) name=%s, price=%d, year=%d, month=%d, day=%d, throw=%c\n",
               i, (p + i)->name, (p + i)->price, (p + i)->expire.year, (p + i)->expire.month, (p + i)->expire.day, (p + i)->throw);
    }
}

void ex_08()
{

    fruit store[5] = {
        "apple",
        500,
        2020,
        9,
        1,
        'n',
        "banana",
        500,
        2020,
        7,
        3,
        'n',
        "orange",
        500,
        2020,
        8,
        1,
        'n',
        "melon",
        500,
        2020,
        11,
        11,
        'n',
        "mango",
        500,
        2020,
        12,
        25,
        'n',
    };
    fruit *p;

    p = store;

    time_t now = time(NULL);            //time구조체에 현재시간 받음
    struct tm *today = localtime(&now); //tm구조체에 로컬시간 받음

    printf("\n오늘의 날짜 : %d년 %d월 %d일 \n\n",
           (today->tm_year) + 1900, today->tm_mon + 1, today->tm_mday);

    for (int i = 0; i < sizeof(store) / sizeof(store[0]); i++)
    {
        if ((today->tm_year) + 1900 > (p + i)->expire.year)
        {
            (p + i)->throw = 'y';
        }

        else if ((today->tm_year) + 1900 == (p + i)->expire.year)
        {
            if (today->tm_mon + 1 > (p + i)->expire.month)
                (p + i)->throw = 'y';
            else if (today->tm_mon + 1 == (p + i)->expire.month)
            {
                if (today->tm_mday > (p + i)->expire.day)
                    (p + i)->throw = 'y';
            }
        }
    }

    for (int i = 0; i < sizeof(store) / sizeof(store[0]); i++)
    {
        printf("%d) name=%s, price=%d, year=%d, month=%d, day=%d, throw=%c\n",
               i, (p + i)->name, (p + i)->price, (p + i)->expire.year, (p + i)->expire.month, (p + i)->expire.day, (p + i)->throw);
    }
}

void ex_09()
{
    fruit store[5] = {
        "apple",
        500,
        2020,
        9,
        1,
        'n',
        "banana",
        500,
        2020,
        7,
        3,
        'n',
        "orange",
        500,
        2020,
        8,
        1,
        'n',
        "melon",
        500,
        2020,
        11,
        11,
        'n',
        "mango",
        500,
        2020,
        12,
        25,
        'n',
    };
    fruit *p;

    p = store;

    time_t now = time(NULL);            //time구조체에 현재시간 받음
    struct tm *today = localtime(&now); //tm구조체에 로컬시간 받음

    printf("\n오늘의 날짜 : %d년 %d월 %d일 \n\n",
           (today->tm_year) + 1900, today->tm_mon + 1, today->tm_mday);

    for (int i = 0; i < sizeof(store) / sizeof(store[0]); i++)
    {
        if ((today->tm_year) + 1900 > (p + i)->expire.year)
        {
            (p + i)->throw = 'y';
        }

        else if ((today->tm_year) + 1900 == (p + i)->expire.year)
        {
            if (today->tm_mon + 1 > (p + i)->expire.month)
                (p + i)->throw = 'y';
            else if (today->tm_mon + 1 == (p + i)->expire.month)
            {
                if (today->tm_mday > (p + i)->expire.day)
                    (p + i)->throw = 'y';
            }
        }
    }

    for (int i = 0; i < sizeof(store) / sizeof(store[0]); i++)
    {
        if ((p + i)->throw == 'y')
        {
            printf("name=%s, price=%d, year=%d, month=%d, day=%d, throw=%c\n",
                   (p + i)->name, (p + i)->price, (p + i)->expire.year, (p + i)->expire.month, (p + i)->expire.day, (p + i)->throw);
        }
    }
}

void ex_10()
{
    fruit store[5] = {
        "apple",
        500,
        2020,
        9,
        1,
        'n',
        "banana",
        500,
        2020,
        7,
        3,
        'n',
        "orange",
        500,
        2020,
        8,
        1,
        'n',
        "melon",
        500,
        2020,
        11,
        11,
        'n',
        "mango",
        500,
        2020,
        12,
        25,
        'n',
    };
    fruit *p;

    p = store;

    time_t now = time(NULL);            //time구조체에 현재시간 받음
    struct tm *today = localtime(&now); //tm구조체에 로컬시간 받음

    printf("\n오늘의 날짜 : %d년 %d월 %d일 \n\n",
           (today->tm_year) + 1900, today->tm_mon + 1, today->tm_mday);

    for (int i = 0; i < sizeof(store) / sizeof(store[0]); i++)
    {
        if ((today->tm_year) + 1900 > (p + i)->expire.year)
        {
            (p + i)->throw = 'y';
        }

        else if ((today->tm_year) + 1900 == (p + i)->expire.year)
        {
            if (today->tm_mon + 1 > (p + i)->expire.month)
                (p + i)->throw = 'y';
            else if (today->tm_mon + 1 == (p + i)->expire.month)
            {
                if (today->tm_mday > (p + i)->expire.day)
                    (p + i)->throw = 'y';
            }
        }
    }

    int total = 0;

    for (int i = 0; i < sizeof(store) / sizeof(store[0]); i++)
    {
        if ((p + i)->throw == 'y')
        {
            total += (p + i)->price;
        }
    }
    printf("폐기 되는 항목들의 총액은 %d원입니다.", total);
}


struct binary2hexa{
    char hexa[2];
    char bin[5];
};
typedef struct binary2hexa binary2hexa;

void makehexa(char *in, char *rst, binary2hexa *b2h, int size){
    int i=0, j=0;
    char temp[5]="";

    if(*in=='\0'){
        *(rst+0)='x';
        return;
    }

    while(*(in+i)){
        if(*(in+i)<'0'|| *(in+i)>'F'){ 
            *(rst+0)='x';
            return;
        }
        i++;
    }
     if((i>4)!=0){//입력받은 수가 4자리 보다 크면 결과에 x넣고 리턴
        *(rst+0)='x';
        return;
    }

    i=0;
    while(*(in+i)){
        for(j=0;j<1;j++){
            *(temp+j)=*(in+i);//입력받은 수를 temp에 옮김
            i++;
        }
        temp[j]='\0';
        

        for(j=0;j<size;j++){
            if(strcmp((b2h+j)->hexa, temp)==0){
                //배열의 16진수와 입력받은 수가 같으면
                strcat(rst, (b2h+j)->bin);//결과에 2진수 값 연결
 
            }
        }
    }
}

void ex_12()
{
    char input[10]; //16진수입력받는 배열
    char result[50]; //2진수 저장 배열
    binary2hexa b2h[16] = {"0", "0000", "1", "0001", "2", "0010", "3", "0011",
                           "4", "0100", "5", "0101", "6", "0110", "7", "0111",
                           "8", "1000", "9", "1001", "A", "1010", "B", "1011",
                           "C", "1100", "D", "1101", "E", "1110", "F", "1111"}; //2진수-16진수 모아둔 배열
    do
    {
        result[0] = '\0';
        printf("16진수 입력 : ");
        gets(input);

        makehexa(input, result, b2h, sizeof(b2h) / sizeof(b2h[0]));

        if (result[0] == 'x')
            break; //결과배열 첫번째값이 x이면 반복종료

        printf(" %s\n\n", result);
    } while (1);

    printf(" -> 16진수가 아닙니다. 종료합니다.\n\n");
}

int main()
{
    //ex_01();
    //ex_02();
    //ex_03();
    //ex_06();
    //ex_07();
    //ex_08();
    //ex_09();
    //ex_10();
    ex_12();

    return 0;
}