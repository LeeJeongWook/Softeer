#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    scanf("%d", &n);
    
    int *s = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d ", &s[i]);
    }
    
    qsort(s, n, sizeof(int), compare);

    int num = n - 1 + s[n - 1];
    printf("%d\n", num);
    
    free(s);
    return 0;
}
