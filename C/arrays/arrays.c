#include <stdio.h>

#define MAX_WORD_LEN 40

int main() {
    
    int c;
    int current_word_length = 0;
    int num_words_with_length[MAX_WORD_LEN];

    for (int i = 0; i < MAX_WORD_LEN; i++) {
        num_words_with_length[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n') {
            num_words_with_length[current_word_length]++;
            current_word_length = 0;
        } else {
            current_word_length++;
        }

    }

    for (int i = 1; i < MAX_WORD_LEN; i++) {
        printf("%-3d: ", i);
        for (int j = 0; j < num_words_with_length[i]; j++) {
            printf("#");
        }
        printf("\n");
    }

}