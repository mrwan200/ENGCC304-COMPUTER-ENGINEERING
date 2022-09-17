#include <stdio.h>

struct Employee {
    char    name[ 100 ] ;
    float   salary ;
    int     duration ;
} typedef Employee ;

void most_salary( Employee em[], int index ) {
    int count               = 0 ;
    int total               = 0 ;
    int most_salary_index   = -1 ;
    
    while( count < index ) {
        int is_most = total < em[ count ].salary ;
        switch(is_most) {
            case 1:
                most_salary_index = count ;
                total = em[ count ].salary ;
                break ;
        }// end swtich
        count += 1 ;
    }// end while

    printf( "** Most salary in this buiniess **\n" ) ;
    printf( "Name: %s (%d Years)\n", em[ most_salary_index ].name, em[ most_salary_index ].duration ) ;
    printf( "Salary: %.2f\n", em[ most_salary_index ].salary ) ;
}

float sum( Employee em[], int index ) {
    float total = 0 ;
    int count   = 0 ;
    while( count < index ) {
        total += em[ count ].salary ;
        count += 1 ;
    }// end while

    return total ;
}// end function

void summary( int index, Employee em[] ) {
    float total = sum( em, index ) ;
    float avg = total / index ;

    printf( "Average of Salary: %.2f\n", avg ) ;
    printf( "Payment of every month: %.2f\n", total ) ;
    most_salary( em, index ) ;
}// end function

void input_employee_data( int index, Employee em[] ) {
    char name[100] ;
    getchar() ; 
    printf( "Employee name: " ) ;
    gets( em[index].name ) ;
    printf( "\n" ) ;
    printf( "Salary (Baht/Month): " ) ;
    scanf( " %f", &em[index].salary ) ;
    printf( "\n" ) ;
    printf( "Duration (Year): " ) ;
    scanf( " %d", &em[index].duration ) ;
    printf( "\n" ) ;
}// end function

int confrim_employee( char confrim, int index, Employee em[] ) {
    switch( confrim ){
        case 'y':
            input_employee_data( index, em ) ;
            return 1 ;
        case 'n':
        default:
            return 0 ;
    }// end swtich
}// end function

int main() {
    int index   = 0 ;
    int is_loop = 1 ;
    Employee em[ 100 ] ;

    while( is_loop ) {
        char confrim ;
        printf( "Do you want to Enter Employee Information? (y/N): " ) ;
        scanf( " %c", &confrim ) ;
        printf( "\n" ) ;
        is_loop = confrim_employee( confrim, index, em ) ;
        index += is_loop ;
    }// end while

    summary( index, em ) ;
    return 0 ;
}// end function