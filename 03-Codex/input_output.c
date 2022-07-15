#include <stdio.h>

int main(){
    int     a ;
    float   b ;
    char    c ;

    printf( "Please enter value : " ) ;
    scanf( "%d %f %c", &a, &b, &c ) ;

    printf("%d %.2f %c", a, b, c ) ;

    return 0;
}//end function