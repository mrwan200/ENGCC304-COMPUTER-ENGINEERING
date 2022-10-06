#include <stdio.h>
#include <string.h>
#include <locale.h>

struct NetworkCompanyEmployee {
    char name[100];
    int salary;
    float tax;
} typedef Employee;

struct ResultMostTAX {
    char name[100];
    float total;
} typedef Result;

void flush_input(){
    /**
     * Clear buffer input data
     * From URL: https://www.youtube.com/watch?v=jnLH_zK1IrM
     */
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int input_data(Employee employee[], int index){
    printf("Employee %d's Name : ", index+1);
    scanf("%s", &employee[index].name);
    printf( "\n" ) ;
    if(!strcmp(employee[index].name, "-1")){
        return 1;
    }
    printf("Salary (Baht/Month): ");
    scanf(" %d", &employee[index].salary);
    printf( "\n" ) ;
    flush_input();
    return 0;
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

Result get_max_tax( Employee em[], int total, float vat, float months) {
    int count = 0;
    int index = 0;
    float total_max = 0;
    Result result;

    while (count < total) {
        float salary_total_current = (em[count].salary * months) *  (vat / 100);
        float salary_total_max = (em[index].salary * months) * (vat / 100);

        if(salary_total_current > salary_total_max) {
            index = count;
            total_max = salary_total_current;
        }
        count++;
    }

    strcpy(result.name, em[index].name);
    result.total = total_max;

    return result;
}

void summary( int index, Employee em[] ) {
    float vat = 7;
    float month = 12;
    float total_month = sum(em, index);
    float total_year = total_month * month;
    float total_vat = total_year * (vat/100); // Aka total_year * 7%

    printf("All slary per month: %'.2f\n", total_month);
    printf("All slary per year: %'.2f\n", total_year);
    printf("Tax(%.0f%% per year) : %'.2f\n", vat, total_vat);

    Result result = get_max_tax(em, index, vat, month);
    printf("Max tax in company : %s (%'.2f Bath per year)\n", result.name, result.total);
}// end function

int main(){
    setlocale(LC_ALL,"");

    int index       = 0;
    int is_loop     = 1;
    Employee em[100];

    while(is_loop){
        int status = input_data(em, index);
        if(status >= 1) break;
        index++;
    }

    summary(index, em);

    return 0;
}