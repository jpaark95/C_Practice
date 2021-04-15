#include <stdio.h>

int main(int argc, char *argv[]) {
    enum beers { PIELS = 1, COORS, BUD, IRON_CITY};
    int beers[5];
    int transaction;
    unsigned int beer_brand;


    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){
        printf("Error opening file\n");
        return -1;
    }
    
    fscanf(fp, "%d%d%d%d", &beers[PIELS], &beers[COORS], &beers[BUD], &beers[IRON_CITY]);
    while(fscanf(fp, "%u%d", &beer_brand, &transaction) != EOF) {
        beers[beer_brand] += transaction;
    }

    printf("Piels: %10d\nCoors: %10d\nBud: %12d\nIron City: %6d\n", beers[PIELS], beers[COORS], beers[BUD], beers[IRON_CITY]);

    return 0;
}