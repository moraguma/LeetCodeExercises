#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    char* result = f();
    printf("%s", result);
    free(result);
}