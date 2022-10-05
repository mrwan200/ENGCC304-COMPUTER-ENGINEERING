#include <stdio.h>

int main() {
    int array[100] ;
    int n, i, j, check ;

    printf("Input Array Size : ") ;
    scanf("%d", &n);

    i = 1;
    while(i <= n){
        printf("Array[ %d ] : ", i) ;
        scanf("%d", &array[i]) ;
        i++ ;
    }

    printf("Unique = ") ;
    i = n ; 
    while(i > 0) {
        check = 0;
        j = n;
        while(j > 0) {
            if(i != j && array[i] == array[j]) check = 1;
            j--;
        }
        if(check == 0) printf("%d ", array[i]);
        i--; 
    }

    return 0;
}