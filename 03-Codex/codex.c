#include <stdio.h>

int main() {
    // Set default values
    int i, j    = 0 ;
    int N       = 7 ;
    // Character
    char star   = '*' ;


    printf( "--| Show 'Hello World' to Screen %d line(s)\n", N ) ;
    for( i = 0 ; i < N ; i++ ) {
        printf( "[%3d] Hello World\n", i ) ;
    }//end for
    
    // Set new values and reset i to zero
    N   = 8 ;
    i   = 0 ;
    printf( "\n" );

    while(i < N) {
        j = 0;
        while(j < N) {
            if(i < j) printf( "%c", star );
            j++;
        }//end while

        printf( "%s", "\n" ) ;
        i += 1 ;
    }//end while

    return 0 ;
}// end function