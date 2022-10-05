#include <stdio.h>
#include <string.h>

int main() {
    char word[ 100 ];
    int i, count;

    printf("Input : ");
    gets(word);

    count = strlen(word);
    
    printf("Result : ");

    i = count;
    while( i >= 0 ) {
        printf("%c", word[i]);
        i--; 
    }

    return 0;
}