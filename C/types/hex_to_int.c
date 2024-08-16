#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 3

int hex_char_to_digit(char hex_char);
int is_valid_hexadecimal(char first_hex_digit, char second_hex_digit);

int main() {

    char c, first_hex_digit, second_hex_digit;
    int out;

    while((c = getchar()) != '\n') {

        if (c == '0') {
            if ((c = getchar()) == 'x' || c == 'X') {
                c = getchar();
            } else {
                c = '0';
            }
        }

        first_hex_digit = c;
        c = getchar();
        second_hex_digit = c;

        if (!is_valid_hexadecimal(first_hex_digit, second_hex_digit)) {
            printf("invalid hexadecimal value given (invalid digits)\n");
            return -1;
        }

        if ((c = getchar()) != '\n') {
           printf("invalid hexadecimal value given (invalid length)\n");
           return -1;
        }

        out = hex_char_to_digit(first_hex_digit) * 16 + hex_char_to_digit(second_hex_digit);
        printf("%d\n", out);
    }

    return 0;

}

int hex_char_to_digit(char hex_char) {
    if (hex_char >= '0' && hex_char <= '9') {
        return hex_char - '0';
    } else if (hex_char >= 'A' && hex_char <= 'F') {
        return hex_char - 'A' + 10;
    } else if (hex_char >= 'a' && hex_char <= 'f') {
        return hex_char - 'a' + 10;
    }

    return -1;
}

int is_valid_hexadecimal(char first_hex_digit, char second_hex_digit) {

    if (!(
        (first_hex_digit >= '0' && first_hex_digit <= '9') ||
        (first_hex_digit >= 'A' && first_hex_digit <= 'F') ||
        (first_hex_digit >= 'a' && first_hex_digit <= 'f'))
    ) {
        return 0;
    }

    if (!(
        (second_hex_digit >= '0' && second_hex_digit <= '9') ||
        (second_hex_digit >= 'A' && second_hex_digit <= 'F') ||
        (second_hex_digit >= 'a' && second_hex_digit <= 'f'))
    ) {
        return 0;
    }

    return 1;

}