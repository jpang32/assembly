#include <stdio.h>

int main() {
    // Loop through i from 0 to 300, incrementing by 20
    for (int i = 0; i < 320; i = i + 20) {
        // Calculate celsius using farenheit
        // 5.0 necessary in order to avoid integer arithmetic
        double celsius = (5.0 / 9) * (i - 32);

        // Print out results in two columns
        // Farenheit left-justified with 3 character column width
        printf("%-3d %d", i, (int) celsius);
        printf("\n");
    }
}