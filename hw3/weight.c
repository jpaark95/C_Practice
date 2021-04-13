#include <stdio.h>
#include <string.h>

int main() {

    int weight_lb, height_in;
    float bmi;
    char status[20];

    printf("Please enter your weight in whole pounds: ");
    scanf("%d", &weight_lb);
    printf("Please enter your height in whole inches: ");
    scanf("%d", &height_in);

    bmi = (float)703*weight_lb/height_in/height_in;

    if (bmi < 0){
        printf("error, negative bmi \n");
        return(-1);
    }

    if (bmi < 18.5){
        strcpy(status, "underweight");
    } else if (18.5 <= bmi && bmi < 24.9){
        strcpy(status, "normal");
    } else if (25.0 <= bmi && bmi < 29.9){
        strcpy(status, "overweight");
    } else {
        strcpy(status, "obese");
    }

    printf("You have a BMI of %.1f, and your weight status is %s.\n", bmi, status);
    return 0;
}