#include <stdio.h>
#include <stdlib.h>

char * mergeAlternately(char * word1, char * word2){
    char* result = malloc(sizeof(char) * 200);
    char* currentWord = word1;
    int resultPos = 0;
    int pos = 0;

    while (currentWord[pos] != '\0') {
        result[resultPos] = currentWord[pos];
        resultPos++;

        if (currentWord == word2) {
            currentWord = word1;
            pos++;
        } else {
            currentWord = word2;
        }
    }

    if (currentWord == word2) pos++;
    
    currentWord = currentWord == word1 ? word2 : word1;
    while(currentWord[pos] != '\0') {
        result[resultPos] = currentWord[pos];
        resultPos++;
        pos++;
    }
    result[resultPos] = '\0';

    return result;
}


int main(int argc, char *argv[]) {
    char* result = mergeAlternately("abcd", "pq");
    printf("%s", result);
    free(result);
}