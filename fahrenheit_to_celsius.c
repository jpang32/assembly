#include <stdio.h>

#define LOWER 0
#define UPPER 320
#define STEP 20

int main() {

    printf("FARENHEIT | CELSIUS\n");
    printf("-------------------\n");
    // Loop through i from 0 to 300, incrementing by 20
    for (int i = LOWER; i < UPPER; i = i + 20) {
        // Calculate celsius using farenheit
        // 5.0 necessary in order to avoid integer arithmetic
        double celsius = (5.0 / 9) * (i - 32);

        // Print out results in two columns
        // Farenheit left-justified with 3 character column width
        printf("%-10d|%8.2f", i, celsius);
        printf("\n");
    }
}