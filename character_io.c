#include <stdio.h>

# define IN 1
# define OUT 0

int main() {

    int c;
    int state = IN;

    while ((c = getchar()) != EOF) {
        if (state == IN) {
            printf("%c", c);
        }
        if (c == ' ') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
        }
    }

}