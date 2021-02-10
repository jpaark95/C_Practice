#include <stdio.h>
#define GRASS_CUT_RATE 2 // sqr_ft/second
int main() {
    int h_length, h_width, y_length, y_width, area_to_cut;
    int minutes, seconds, total_seconds;

    printf("Please enter the length and width of the yard > ");
    scanf("%d%d", &y_length, &y_width);
    printf("Please enter the length and width of the house > ");
    scanf("%d%d", &h_length, &h_width);

    area_to_cut = y_length*y_width - h_length*h_width;

    total_seconds = area_to_cut / GRASS_CUT_RATE;

    minutes = total_seconds / 60; //convert to minutes
    seconds = total_seconds % 60; 

    printf("%d square feet will take %d minutes and %d seconds to cut.\n", area_to_cut, minutes, seconds);

    return 0;    
}