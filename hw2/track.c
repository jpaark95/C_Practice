#include <stdio.h>

#define FEET_PER_MILE 5280
#define FEET_PER_KM 3282
#define M_PER_KM 1000

void display_instructions(){

    printf("This program will ask for the minutes and secods for the time it\ntook for a runner to run a mile. The program will then calculate\nthe feet per second and meters per second for that runner.\n");
}

float convert_fps(float total_sec){
    float fps = FEET_PER_MILE / total_sec;
    return fps;
}
float convert_mps(float fps){
    float mps = fps / FEET_PER_KM * M_PER_KM; //convert from km to m
    return mps;
}

int main() {

    float minutes, seconds, total_seconds;
    float fps, mps;

    display_instructions();

    printf("Minutes for the runner: ");
    scanf("%f", &minutes);
    printf("Seconds for the runner: ");
    scanf("%f", &seconds);
    
    total_seconds = 60*minutes + seconds;
    fps = convert_fps(total_seconds);
    mps = convert_mps(fps);

    printf("That is %.1f feet per second, and %.2f meters per second.\n", fps, mps);

    return 0;
}