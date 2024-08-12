#include <stdio.h>

#define MAX_LEN 80

int get_line(char line[], int max_len);
void get_reversed_line(char line[], char line_reversed[], int len);

int main() {

    int len;
    char line[MAX_LEN];
    char line_reversed[MAX_LEN];

    while ((len = get_line(line, MAX_LEN)) > 0) {
        get_reversed_line(line, line_reversed, len);
        printf("line: %s\n", line);
        printf("reversed line: %s\n", line_reversed);
    }

    return 0;
}

int get_line(char line[], int max_len) {

    int c, i;
    for (i = 0; i < (max_len - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    line[i] = '\0';

    return i;

}

void get_reversed_line(char line[], char line_reversed[], int len) {

    int j;

    for (j = len - 1; j >= 0; --j) {
        line_reversed[len - 1 - j] = line[j];
    }

    line_reversed[j] = '\0';

}