#include <stdio.h>

#define THRESHOLD 10
#define MAX_LEN 15

int get_line(char line[], int max_len);

int main() {

    // Read lines from std input
    // If a line is longer than 80 characters, print it
    // If not, ignore and move on
    int c, i, len;
    char line[MAX_LEN];

    // Had issue with old program where it wouldn't quit immediately after 
    // giving EOF signal
    // This is because get_line would return a val > 0, so this while would continue
    // TODO: find a way to fix above
    i = 0;
    while ((c = getchar()) != EOF) {
        if (i < MAX_LEN - 1) {
            line[i] = c;
            if (c == '\n') {
                line[++i] = '\0';
            }
            
            if (i > THRESHOLD) {
                printf("%s", line);
            }
            i = -1;
        } else {
            line[i] = '\0';
            printf("%s", line);
            i = -1;
        }

        ++i;
    }

    if (c == EOF) {
        printf("%s", line);
    }



    return 0;
}

int get_line(char line[], int max_len) {

    int c, i;

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