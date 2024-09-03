#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int maxCandies = 0;

    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > maxCandies) maxCandies = candies[i];
    }

    bool* result = malloc(sizeof(int) * candiesSize);
    for (int i = 0; i < candiesSize; i++) {
        result[i] = candies[i] + extraCandies >= maxCandies;
    }

    *returnSize = candiesSize;
    return result;
}


int main(int argc, char *argv[]) {
    int candies[5] = {2, 3, 5, 1, 3};
    int returnSize;
    char* result = kidsWithCandies(candies, 5, 3, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d", result[i]);
    printf("\n");
    free(result);
}