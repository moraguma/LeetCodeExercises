#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* conc(char* str1, char* str2) {
    char* conc = malloc(sizeof(char) * 2001);
    int pos = 0;
    while (str1[pos] != '\0') {
        conc[pos] = str1[pos];
        pos++;
    }
    int pos2 = 0;
    while(str2[pos2] != '\0') {
        conc[pos] = str2[pos2];
        pos++;
        pos2++;
    }
    conc[pos] = '\0';
    return conc;
}

bool eqStr(char* str1, char* str2) {
    int pos = 0;
    while (!(str1[pos] == '\0' && str2[pos] == '\0')) {
        if (str1[pos] != str2[pos]) return false;
        pos++;
    }
    return true;
}

int gcd(int a, int b) {
    while (a != 0) {
        int aux = a;
        a = b % a;
        b = aux;
    }
    return b;
}

int strLen(char* str) {
    int pos = 0;
    while (str[pos] != '\0') pos++;
    return pos;
}

char* gcdOfStrings(char* str1, char* str2) {
    char* c = conc(str1, str2);
    char* cAux = conc(str2, str1);
    if (!eqStr(c, cAux)) return "";

    free(cAux);

    c[gcd(strLen(str1), strLen(str2))] = '\0';

    return c;
}

int main(int argc, char *argv[]) {
    char* result = gcdOfStrings("ABCABC", "ABC");
    printf("%s", result);
    free(result);
}