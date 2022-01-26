#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

void ex_08(void){
    char ch;
    
}

void ex_11(void)
{
    for (int i = 0; i <= SIZE; i++)
    { //За
        for (int j = -SIZE; j <= SIZE; j++)
        {
            if (abs(j) > i)
                printf("%c", ' '); //putchar(' ');
            else
                printf("%d", abs(j));
        }
        printf("\n");
    }
}

int main()
{
    ex_08();
    //ex_11();
    return 0;
}