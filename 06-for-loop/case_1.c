#include <stdio.h>

int main() {
    // Set default values
    int line = 0;
    int max_line = 0;

    printf("Input your line: ");
    scanf("%d", &max_line);

    /**
     * Output:
     * *
     * * *
     * * * *
     * * * * *
     * * * * * *
     */
    for (line = 1; line <= max_line; line++) {
        for (int i = 0; i < line; i++) {
            printf("* ");
        }
        printf("\n");
    }
}