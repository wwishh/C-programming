#include <stdio.h>

int main(){
    int in[5];

    for(int i=0; i<sizeof(in)/sizeof(int); i++){
        printf("정수를 입력하세요 : ");
        scanf("%d", &in[i]);
    }

    for(int i=0; i<sizeof(in)/sizeof(int); i++){
        printf("in[%d]=%d, *(in+%d)=%d\n", i, in[i], i, *(in+i));
    }

    for(int i=0; i<sizeof(in)/sizeof(int); i++){
        printf("in[%d]=%d, (in+%d)=%d\n", i, &in[i], i, (in+i));
    }

    return 0;
}