#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employees {
    char    name[100];
    int     age;
	float   salary;
} typedef Employees;

Employees * _sort(Employees em[], int total, int less_than){
    Employees em_result;
    for (int i = 1; i < total; i++) {
        for (int j = 0; j < i; j++) {
            if((em[i].age > em[j].age) && !less_than){
                em_result = em[i];
                for(int k = i ; k > j ; k--){
					em[k] = em[k-1] ;
				}
                em[j] = em_result;
                break;
            }

            if((em[i].salary < em[j].salary) && less_than){
                em_result = em[i];
                for(int k = i ; k > j ; k--){
					em[k] = em[k-1] ;
				}
                em[j] = em_result;
                break;
            }
        }
    }

    return em;
}

void result(Employees em[], int total, int keyword){
    Employees * result_age = _sort(em, total, 0);
    Employees * result_salary = _sort(em, total, 1);

    // Age
    printf("\t\t\t");
    for (int c = 0;  c < 5; c++){
		printf("%d\t", result_age[c].age) ;
	}
    printf("\nAge( 99 - 0 ) : \t");
    for (int l = 0 ;  l < 5 ; l++){
		printf("%s\t", result_age[l].name) ;
	}
    printf("\n\n\t\t\t");

    // Salary
    for (int c = 0 ;  c < 5 ; c++){
		printf("%.f\t", result_salary[c].salary) ;
	}
	printf("\n") ;
	printf("Salary( 99999 - 0 ) : \t") ;
	for (int l = 0 ;  l < 5 ; l++){
		printf("%s\t", result_salary[l].name) ;
	}

    printf("\n\n");
    printf("\nAge %d = ", keyword);
	for (int i = 0 ; i < total ; i++){
		if( em[i].age == keyword){
			printf( "%s\t", em[i].name);
		}
	}
}

int openfile(Employees em[]){
    int index = 0 ;

    FILE *fptr ;
    fptr = fopen("salary.txt", "r") ;
    if(fptr == NULL){
        printf("Error opening file salary.txt\n");
        exit(0);
    }

    // Blank data
    char col1[100], col2[100], col3[100], col4[100], row4[100];

    // Scanf first line
    fscanf(fptr, "%s %s %s %s", col1, col2, col3, col4);

    while(fscanf(fptr,"%s %d %f %s\n", em[index].name, &em[index].age, &em[index].salary, row4) != EOF){
        index++;
    }

    fclose(fptr);
    return index;
}

int main(){
    Employees em[100];
    // Open file
    int total = openfile(em);
    int keyword;

    printf("Find Age : ") ;
	scanf("%d", &keyword);
    
    result(em, total, keyword);
    return 0;
}