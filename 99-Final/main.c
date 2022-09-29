#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[ 100 ] ;
    char date[ 100 ] ;
    int age_years ;
    int age_months ;
} typedef User;

int fast_abs( int x ) {
    int mask = x >> 31;
    return ( mask ^ x ) - mask ;
} // end function

void caculate_age( User user[], int index ) {
    // Example date
    int year    = 2018 ;
    int month   = 6 ;
    int days    = 21 ;

    // Split date
    int count   = 0 ;
    char * date = strtok( user[ index ].date, "-" ) ;
    while( date != NULL ) {
        // Convert string to number
        int num_date = atoi( date ) ;

        switch( count ) {
            case 0 :
                user[ index ].age_years = year - num_date ;
                break;
            case 1 :
                // Formula: abs(Month user - Month now)
                user[ index ].age_months  = fast_abs( month - num_date ) ;
                if(month < num_date) {
                    user[ index ].age_years-- ;
                    user[ index ].age_months = 12 + month - num_date ;
                } // end if
                break;
            case 2 :
                if( days < num_date ) {
                    user[ index ].age_months-- ;
                } // end if
                break ;
        }// end switch

        date = strtok( NULL, "-" ) ;
        count++ ;
    } // end while
} // end function

int get_max_min_index( User user[], int total, int less_than ) {
    int count = 0 ;
    int index = 0 ;

    while ( count < total ) {
        int age_total_current = user[ count ].age_years + user[ count ].age_months ;
        int age_total_max = user[ index ].age_years + user[ index ].age_months ;

        if( !less_than ){
            if( age_total_current > age_total_max ) {
                index = count ;
            }
        } else {
            if( age_total_current < age_total_max ) {
                index = count ;
            }
        } // end if-else
        
        count++ ;
    } // end while
    
    return index ;
} // end function


int openfile(User user[]){
    int index = 0 ;

    FILE *fptr ;
    fptr = fopen( "a.txt", "r" ) ;
    if(fptr == NULL){
        printf( "Error opening file a.txt\n" ) ;
        exit( 0 ) ;
    }
    // Blank data
    char col1[ 100 ], col2[ 100 ], col3[ 100 ], row[ 100 ] ;

    // Scanf first line
    fscanf( fptr, "%s %s %s", col1, col2, col3 ) ;

    while( fscanf( fptr,"%s %s %s\n", row, &user[index].name, &user[index].date ) != EOF ) {
        index++ ;
    } // end while

    fclose(fptr) ;
    return index ;
} // end function

int main() {
    User user[100] ;
    int total = openfile(user) ;

    for( int i = 0; i < total; i++ ){
        caculate_age(user, i) ;
        printf("%s %d Years, %d Months\n", user[i].name, user[i].age_years, user[i].age_months) ;
    }

    int max_idx = get_max_min_index(user, total, 0) ;
    int min_idx = get_max_min_index(user, total, 1) ;
    printf("Max: %s [%d Years, %d Months]\n", user[max_idx].name, user[max_idx].age_years, user[max_idx].age_months) ;
    printf("Min: %s [%d Years, %d Months]\n", user[min_idx].name, user[min_idx].age_years, user[min_idx].age_months) ;

    return 0 ;
} // end function