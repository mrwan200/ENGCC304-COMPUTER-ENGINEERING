#include <stdio.h>

int main() {
    // Init intiget
    int i = 0;

    printf("Input : "); 
    scanf("%d", &i); 

    while(i >=0) {
        if(i == 7 || i == 5 || i == 3 || i == 2) printf("%d ", i);
        else if ( i % 7 != 0  && i % 5 != 0 && i % 3 != 0 && i % 2 != 0 && i != 1 ) printf("%d ", i);
        i--;
    }

    return 0;
}