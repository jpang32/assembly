#include <stdio.h>

#define C 100

void test_func();

int main() {

    int c = 1;
    test_func();
    printf("main c val: %d\n", c);
    test_func();

}

void test_func() {
    int c;

    printf("test_func c val: %d\n", c);
}