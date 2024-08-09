#include <stdio.h>

#define MAX_LEN 10

int get_line(char line[], int max_line_len);
void copy(char to[], char from[]);

int main() {

    char cur_line[MAX_LEN];
    char longest_line[MAX_LEN];
    int cur_len;
    int longest_len = 0;

    while ((cur_len = get_line(cur_line, MAX_LEN)) > 0) {
        if (cur_len > longest_len) {
            longest_len = cur_len;
            copy(longest_line, cur_line);
        }
    }

    printf("longest line is %d characters: ", longest_len);
    printf("%s\n", longest_line);

    return 0;
}

int get_line(char line[], int max_line_len) {

    int c;
    int i = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < max_line_len - 1) {
            line[i] = c;
        }

        ++i;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    if (i < max_line_len - 1) {
        line[i] = '\0';
    } else {
        line[max_line_len - 1] = '\0';
    }

    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}