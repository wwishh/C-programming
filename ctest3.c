#include <stdio.h>

int main(){
    char ch, str[50];
    int i=0, count=0;

    printf("���ڿ��� �Է��ϼ��� : ");
    gets(str);
    printf("���ڸ� �Է��ϼ��� : ");
    ch = getchar();


    while(str[i]){
        if(str[i] == ch){
            count++;
        }
        i++;
    }
    printf("%s�� %c�� %d�� �Դϴ�\n", str, ch, count);
    return 0;

}