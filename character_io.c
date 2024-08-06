#include <stdio.h>

int main() {

    int c, count = 0;

    char newLine  = '\n';
    char tab  = '\t';
    char blank  = ' ';
    
    while ((c = getchar()) != EOF)
    {
        if (c == newLine || c == tab || c == blank) {
            count++;
        }
    }
    printf("\nNum newlines, tab, blank: %d\n", count);

}