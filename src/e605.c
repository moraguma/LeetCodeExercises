#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int pos = 0;
    int flowerState = flowerbed[0];
    int flowerCount = 0;
    while (n > 0 && pos < flowerbedSize) {
        if (pos < flowerbedSize - 1) flowerState += flowerbed[pos + 1];
        if (flowerState == 0) {
            flowerbed[pos] = 1;
            flowerState++;
            flowerCount++;
        }
        if (pos > 0) flowerState -= flowerbed[pos - 1];
        pos++;
    }
    return flowerCount >= n;
}

int main(int argc, char *argv[]) {
    int flowerbed[5] = {1,0,0,0,0,0,1};
    bool result = canPlaceFlowers(flowerbed, 7, 2);
    printf("%d\n", result);
}