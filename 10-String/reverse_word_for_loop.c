#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int i, count;

    printf("Input : ") ;
    gets(word) ;

    count = strlen(word) ;
    
    printf("Result : ") ;

    for( i = count ; i >= 0 ; i-- ) {
        printf("%c" , word[i]);
    }

    return 0;
}