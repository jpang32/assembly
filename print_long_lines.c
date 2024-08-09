#include <stdio.h>

#define THRESHOLD 80
#define MAX_LEN 200

int get_line(char line[], int max_len);

int main() {

    // Read lines from std input
    // If a line is longer than 80 characters, print it
    // If not, ignore and move on
    int len;
    char line[MAX_LEN];

    // Had issue with old program where it wouldn't quit immediately after 
    // giving EOF signal
    // This is because get_line would return a val > 0, so this while would continue
    // TODO: find a way to fix above
    while ((len = get_line(line, MAX_LEN)) > 0) {
        if (len > THRESHOLD) {
            printf("%s", line);
        }
    }

    return 0;
}

int get_line(char line[], int max_len) {

    int c;
    int i;

    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;

}