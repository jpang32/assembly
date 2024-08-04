#include <stdio.h>

#define LOWER 0
#define UPPER 320
#define STEP 20

int main() {

    printf("CELSIUS | FARENHEIT\n");
    printf("-------------------\n");
    
    int celsius = LOWER;
    float farenheit;

    while (celsius <= UPPER) {
        farenheit = (9.0 / 5.0) * celsius + 32.0;

        printf("%-8d|%10.2f\n", celsius, farenheit);

        celsius += STEP;
    }
}