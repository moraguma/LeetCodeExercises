#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(int argc, char *argv[]) {
    char* result = f();
    printf("%s\n", result);
    free(result);
}