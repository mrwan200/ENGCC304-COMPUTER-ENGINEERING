#include <stdio.h>

int main() {
    // Set default values
    int last_month = 29 ;
    int year = 0 ;

    printf("Input years: ");
    scanf("%d", &year);
    
    int is_odd = year % 4;

    switch(is_odd) {
        case 0:
            last_month -= 1;
            break;
    }

    printf("Feb = %d days\n", last_month);
}