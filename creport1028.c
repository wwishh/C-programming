#include <stdio.h>

void ex_08(void)
{
    
    char str[2][100];
    int i;

    printf("c_09_실습_위시온_20175319\n");

    while (1)
    {
        printf("문자열 입력 : ");
        gets(str[0]);

        if (str[0][0] == '\0')
        {
            printf("<Enter키>");
            break;
        }
        printf("문자열 입력 : ");
        gets(str[1]);

        for (i = 0; str[0][i]; i++);

        if (str[0][i] == str[1][i])
        {
            i = 0;
            while (str[0][i])
            {
                if (str[0][i] == str[1][i])
                    i++;
                else
                {
                    printf("%s, %s, 다름.\n", str[0], str[1]);
                    break;
                }
            }
            if (str[0][i] == '\0')
                printf("%s, %s, 같음.\n", str[0], str[1]);
        }
        else
            printf("%s, %s, 다름.\n", str[0], str[1]);
    }
}

int main()
{
    ex_08();

    return 0;
}