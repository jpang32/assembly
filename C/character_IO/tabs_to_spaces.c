#include <stdio.h>

#define MAX_LEN 80
#define TAB_LEN 5

int get_line(char line[], int max_len);

int main() {

    int len;
    char line[MAX_LEN];

    while ((len = get_line(line, MAX_LEN)) > 0) {
        printf("line: %s\n", line);
        printf("line length: %d\n", len);
    }

    return 0;
}

int get_line(char line[], int max_len) {

    int c, i;
    for (i = 0; i < (max_len - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {

        if (c == '\t') {
            int j;
            for (j = 0; j < TAB_LEN && ((j + i) < (max_len - 1)); ++j) {
                line[i + j] = ' ';
            }
            i = i + j - 1;
        } else {
            line[i] = c;
        }
    }

    line[i] = '\0';

    return i;

}
