#include <stdio.h>

# define IN 1
# define OUT 0

int main() {

    int c;
    int state = IN;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        if (state == IN) {
            printf("%c", c);
        } else if (c != ' ' && c != '\n' && c != '\t') {
            printf("\n");
            printf("%c", c);
            state = IN;
        }
    }
    printf("\n");
}