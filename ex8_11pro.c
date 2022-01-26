#include <stdio.h>
#include <time.h>

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

void save_data(fruit *f, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("과일이름 입력 : ");
        gets((f + i)->name);

        printf("가격 입력 : ");
        scanf("%d", &(f + i)->price);

        printf("년도 입력 : ");
        scanf("%d", &(f + i)->expire.year);

        printf("월 입력 : ");
        scanf("%d", &(f + i)->expire.month);

        printf("일 입력 : ");
        scanf("%d", &(f + i)->expire.day);

        while (getchar() != '\n')
            ;

        (f + i)->throw = 'n';
    }
}

fruit *find(fruit *f, char *name)
{
    for (int i = 0; i < sizeof(f) / sizeof(f[0]); i++)
    {
        if ((f + i)->name == "apple")
        {
            return (f + i);
        }
    }
}

void set_throw(fruit *f, int size)
{
    time_t now = time(NULL);            //time구조체에 현재시간 받음
    struct tm *today = localtime(&now); //tm구조체에 로컬시간 받음

    printf("\n오늘의 날짜 : %d년 %d월 %d일 \n\n",
           (today->tm_year) + 1900, today->tm_mon + 1, today->tm_mday);

    for (int i = 0; i < size; i++)
    {
        if ((today->tm_year) + 1900 > (f + i)->expire.year)
        {
            (f + i)->throw = 'y';
        }

        else if ((today->tm_year) + 1900 == (f + i)->expire.year)
        {
            if (today->tm_mon + 1 > (f + i)->expire.month)
                (f + i)->throw = 'y';
            else if (today->tm_mon + 1 == (f + i)->expire.month)
            {
                if (today->tm_mday > (f + i)->expire.day)
                    (f + i)->throw = 'y';
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d) name=%s, price=%d, year=%d, month=%d, day=%d, throw=%c\n",
               i, (f + i)->name, (f + i)->price, (f + i)->expire.year, (f + i)->expire.month, (f + i)->expire.day, (f + i)->throw);
    }
}

int total_throw_cost(fruit *f, int size)
{
    time_t now = time(NULL);            //time구조체에 현재시간 받음
    struct tm *today = localtime(&now); //tm구조체에 로컬시간 받음

    for (int i = 0; i < size; i++)
    {
        if ((today->tm_year) + 1900 > (f + i)->expire.year)
        {
            (f + i)->throw = 'y';
        }

        else if (today->tm_mon + 1 > (f + i)->expire.month)
        {
            (f + i)->throw = 'y';
        }
        else if (today->tm_mday > (f + i)->expire.day)
        {
            (f + i)->throw = 'y';
        }
    }

    int total = 0;

    for (int i = 0; i < size; i++)
    {
        if ((f + i)->throw == 'y')
        {
            total += (f + i)->price;
        }
    }

    return total;
}

void print_throw(fruit *f, int size)
{
    time_t now = time(NULL);            //time구조체에 현재시간 받음
    struct tm *today = localtime(&now); //tm구조체에 로컬시간 받음

    printf("\n오늘의 날짜 : %d년 %d월 %d일 \n\n",
           (today->tm_year) + 1900, today->tm_mon + 1, today->tm_mday);

    for (int i = 0; i < size; i++)
    {
        if ((today->tm_year) + 1900 > (f + i)->expire.year)
        {
            (f + i)->throw = 'y';
        }

        else if (today->tm_mon + 1 > (f + i)->expire.month)
        {
            (f + i)->throw = 'y';
        }
        else if (today->tm_mday > (f + i)->expire.day)
        {
            (f + i)->throw = 'y';
        }
    }

    for (int i = 0; i < size; i++)
    {
        if ((f + i)->throw == 'y')
        {
            printf("name=%s, price=%d, year=%d, month=%d, day=%d, throw=%c\n",
                   (f + i)->name, (f + i)->price, (f + i)->expire.year, (f + i)->expire.month, (f + i)->expire.day, (f + i)->throw);
        }
    }
}

void print_all(fruit *f, int size)
{
    printf("\n모든항목\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d) name=%s, price=%d, year=%d, month=%d, day=%d, throw=%c\n",
               i, (f + i)->name, (f + i)->price, (f + i)->expire.year, (f + i)->expire.month, (f + i)->expire.day, (f + i)->throw);
    }
}

int main()
{
    int size = 2;
    fruit any[size];

    save_data(any, size);
    fruit *p = find(any, any->name);
    printf("\napple에 해당하는 구조체 정보 : name=%s, price=%d, year=%d, month=%d, day=%d, throw=%c\n", p->name, p->price, p->expire.year, p->expire.month, p->expire.day, p->throw);
    set_throw(any, sizeof(any) / sizeof(any[0]));
    int total_value = total_throw_cost(any, sizeof(any) / sizeof(any[0]));
    printf("\n폐기되는 항목들의 총액 : %d\n", total_value);
    print_throw(any, sizeof(any) / sizeof(any[0]));
    print_all(any, sizeof(any) / sizeof(any[0]));
}