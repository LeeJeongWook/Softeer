#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Work_time(char *t1, char *t2){
    int total_time;
    int min1 = 0;
    int min2 = 0;

    min1 = ((((t1[0] - 48) * 10) + (t1[1] - 48)) * 60) + ((t1[3] - 48) * 10) + (t1[4] - 48);
    min2 = ((((t2[0] - 48) * 10) + (t2[1] - 48)) * 60) + ((t2[3] - 48) * 10) + (t2[4] - 48);

    total_time = min2 - min1;

    return total_time;
}

int main(){
    char *time1 = malloc(sizeof(char));
    char *time2 = malloc(sizeof(char));
    int result = 0;

    for(int i = 0; i < 5; i++){
        scanf("%s %s", time1, time2);
        result += Work_time(time1, time2);
    }
    printf("%d", result);

    return 0;
}