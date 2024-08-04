#include <stdio.h>

int main() {

    printf("CELSIUS | FARENHEIT\n");
    printf("-------------------\n");
    
    int celsius = 0;
    float farenheit;

    while (celsius <= 320) {
        farenheit = (9.0 / 5.0) * celsius + 32.0;

        printf("%-8d|%10.2f\n", celsius, farenheit);

        celsius += 20;
    }
}