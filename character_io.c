#include <stdio.h>

int main() {

    int c;
    int is_blank = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!is_blank) {
                is_blank = 1;
                printf("%c", c);
            }
        } else {
            is_blank = 0;
            printf("%c", c);
        }
    }

}