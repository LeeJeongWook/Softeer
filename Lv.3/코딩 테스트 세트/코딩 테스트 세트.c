#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 200

int N, T, arr_size;
int arr[MAX];

bool Check(int n){
    int tmp = 0;
    for(int i = 0; i < arr_size; i+=2){
        if(i == arr_size - 1)
            if(!(arr[i] + tmp >= n)) return false;
        else
            return true;

        if(arr[i] + tmp >= n){
            tmp = arr[i+1];
        }
        else if(arr[i] + arr[i+1] + tmp >= n){
            tmp = (tmp + arr[i+1]) - (n - arr[i]);
        }
        else if(arr[i] + arr[i+1] + tmp < n){
            return false;
        }
    }
    return true;
}

int BinarySearch(int start, int end){
    int mid = start + (end - start) / 2;

    if(Check(mid)){
        if(start == end)
            return start;
        else
            return BinarySearch(mid+1, end);
    }
    else
        return BinarySearch(start, mid-1);
}

int main(){
    scanf("%d %d", &N, &T);
    arr_size = (N * 2) - 1;
    // arr = (int*)malloc(arr_size * sizeof(int));

    for(int i = 0; i < T; i++){
        for(int j = 0; j < arr_size; j++){
            scanf("%d", &arr[j]);
        }
        printf("%d", BinarySearch(0, MAX));
    }

    // free(arr);

    return 0;
}