#include <stdio.h>

int main() {
    // Set default values
    int last_month = 29 ;
    int year = 0 ;

    printf("Input years: ");
    scanf("%d", &year);
    if(year % 4 == 0){
        last_month -= 1;
    }

    printf("Feb = %d days\n", last_month);
}