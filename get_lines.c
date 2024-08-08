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

    printf("longest line is %d characters: ", longest_len - 1);
    printf("%s\n", longest_line);

    return 0;
}

int get_line(char line[], int max_line_len) {

    int c;
    int i;
    
    for (i = 0; i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        ++i;
    }

    line[i] = '\0';
    
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}