#include <stdio.h>
#include <string.h>

int main() {
    char employee_id[10] = "";
    int hour            = 0 ;
    int ammout          = 0 ;
    float result        = 0 ; 

    while(1){
        printf("Input the Employees ID (Max. 10 chars) : ");
        scanf("%s", employee_id);
        if(strlen(employee_id) <= 10) break;
        memset(employee_id, 0, 10);
    }// end while

    printf("Input the working hrs : ");
    scanf("%d", &hour);
    printf("Salary amount/hr (Bath) : ");
    scanf("%d", &ammout);

    /// Caculate the salary
    result = hour * ammout;

    // Output salary
    printf("----\n");
    printf("Excepted Output : \n");
    printf("Employees ID = %s\n", employee_id);
    printf("Amount/day = %.2f Bath(s)\n", result);

    return 0;

}//end function