#include <stdio.h>

int main(){
    char ch, str[50];
    int i=0, count=0;

    printf("문자열을 입력하세요 : ");
    gets(str);
    printf("문자를 입력하세요 : ");
    ch = getchar();


    while(str[i]){
        if(str[i] == ch){
            count++;
        }
        i++;
    }
    printf("%s중 %c는 %d개 입니다\n", str, ch, count);
    return 0;

}