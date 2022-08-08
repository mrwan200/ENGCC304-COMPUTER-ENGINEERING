#include <stdio.h>

int main()
{
    // Set default values
    int line = 0;
    int max_line = 0;

    printf("Input your line: ");
    scanf("%d", &max_line);

    if(max_line % 2 != 0){
         /**
         * Output:
         *     *
         *    * *
         *   * * *
         *  * * * *
         * * * * * *
         */
        for (line = 1; line <= max_line; line++) {
            for (int i = 0; i < max_line - line; i++) {
                printf(" ");
            }
            for (int j = 1; j <= line; j++) {
                printf("* ");
            }
            printf("\n");
        }

        return 0;
    }
    /**
     * Output:
     * * * * * * 
     *  * * * *
     *   * * *
     *    * *
     *     *
     */
    for (line = max_line; line >= 1; line--) {
        for (int i = 0; i < max_line - line; i++) {
            printf(" ");
        }
        for (int j = 1; j <= line; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}