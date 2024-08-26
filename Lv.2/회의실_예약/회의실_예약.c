#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M, s, t;
    
    scanf("%d", &M);
    char car[] = malloc(sizeof(char));
    char cararr[] = malloc(car);

    for(int i = 0; i < 3; i++){
        scanf("%s", cararr[i]);    
    }

    for(int j = 0; j < 3; j++){
        printf("%s", cararr[j]);
    }
    
    /*
    char car[3][10] = {{"grandeur"},
                        {"avante"},
                        {"sonata"}};
    printf("%s\n", car[0]);
    printf("%s\n", car[1]);
    printf("%s\n", car[2]);
    */


    return 0;
}