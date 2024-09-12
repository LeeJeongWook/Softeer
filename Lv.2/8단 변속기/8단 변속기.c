#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Transmission(int *gear){
    int idx, type_rst = 0;

    int ascending = 1, descending = 1;

    for (int i = 0; i < 7; i++) {
        if (gear[i] < gear[i+1]) {
            descending = 0;
        }
        else if (gear[i] > gear[i+1]) {
            ascending = 0;
        }
    }

    if (ascending) {
        printf("ascending");
    }
    else if (descending) {
        printf("descending");
    }
    else {
        printf("mixed");
    }
}

int main(){
    int gear[8];

    for(int i = 0 ; i < 8; i++){
        scanf("%d", &gear[i]);
    }

    Transmission(gear);

    return 0;
}