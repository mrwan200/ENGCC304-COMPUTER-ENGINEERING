#include <stdio.h>

int main() {
    int array[100];
    int n, i, j, check;

    printf("Input Array Size : ");
    scanf("%d", &n);

    for(i = 1 ; i <= n ; i++){
        printf("Array[ %d ] : ", i);
        scanf("%d" , &array[i]);
    }

    printf("Unique = ");
    for(i = n ; i > 0 ; i--) {
        check = 0;
        for(j = n ; j > 0 ; j--) {
            if(i != j && array[i] == array[j]) check = 1;
        }
        if(check == 0) printf("%d ", array[i]);
    }

    return 0;
}