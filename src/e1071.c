#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* gcdOfStrings(char* str1, char* str2) {
    char* result = malloc(sizeof(char) * 1001);
    int pos = 0;
    int maxDivisor = -1;

    while (str1[pos] != '\0' && str2[pos] != '\0' && str1[pos] == str2[pos]) {
        result[pos] = str1[pos];

        int divisorPos = 0;
        int newPos = pos + 1;
        bool finished1 = false;
        bool finished2 = false;
        bool divides = true;
        while (!(finished1 && finished2)) {
            if (((!finished1 && str1[newPos] == '\0') || (!finished2 && str2[newPos] == '\0')) && divisorPos != 0) {
                divides = false;
                break;
            }

            if (!finished1 && str1[newPos] == '\0') finished1 = true;
            if (!finished2 && str2[newPos] == '\0') finished2 = true;

            if ((!finished1 && str1[newPos] != result[divisorPos]) || (!finished2 && str2[newPos] != result[divisorPos])) {
                divides = false;
                break;
            }

            divisorPos = divisorPos == pos ? 0 : divisorPos + 1;
            newPos++;
        }

        if (divides) maxDivisor = pos;

        pos++;
    }

    result[maxDivisor + 1] = '\0';
    return result;
}

int main(int argc, char *argv[]) {
    char* result = gcdOfStrings("ABCABC", "ABC");
    printf("%s", result);
    free(result);
}