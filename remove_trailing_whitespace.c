#include <stdio.h>

#define MAX_LEN 10
#define IN 1
#define OUT 0

int get_line(char line[], int max_len);

int main() {

    // Step through each character in the line
    // When you hit a white space, record the index (var 'end_index')
    // If you hit a non-whitespace (non-newline) character, jump end_index up to i
    // Place a null character at that index

    int len;
    char line[MAX_LEN];

    while((len = get_line(line, MAX_LEN)) > 0) {
        printf("%s, line length: %d\n", line, len);
    }

    return 0;
}

int get_line(char line[], int max_len) {

    int c, i;
    int end_index;
    int in_whitespace = OUT;

    for (i = 0; i < (max_len - 1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        // If c is reg char, write to line (and set in_whitespace to OUT )
        // If c switches from character to whitespace (OUT to IN), 
        //      set in_whitespace to IN, and set end_index to i
        // If c switches from whitespace to character (IN to OUT),
        //      set in_whitespace to OUT, bump up end_index to i + 1

        if (c == ' ' || c == '\t') {
            if (in_whitespace == OUT) {
                in_whitespace = IN;
                end_index = i;
            }
        } else {
            end_index = i + 1;
            in_whitespace = OUT;
        }

        line[i] = c;
    }

    if (c == '\n') {
        line[end_index] = c;
        end_index++;
    }

    line[end_index] = '\0';

    return end_index;

}