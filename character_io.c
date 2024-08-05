#include <stdio.h>

int main() {

    int c;

    printf("EOF value = %d", EOF);
    while ((c = getchar()) != EOF)
    {
        printf("Character you just...typed? : %c\n", c);
        // putchar(c);
    }
    

}