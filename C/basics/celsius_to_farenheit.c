#include <stdio.h>

#define LOWER 0
#define UPPER 320
#define STEP 20

double celsius_to_farenheit(double celsius);

int main() {

    printf("CELSIUS | FARENHEIT\n");
    printf("-------------------\n");
    
    int celsius = LOWER;
    float farenheit;

    while (celsius <= UPPER) {
        farenheit = celsius_to_farenheit(celsius);

        printf("%-8d|%10.2f\n", celsius, farenheit);

        celsius += STEP;
    }
}

double celsius_to_farenheit(double celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}