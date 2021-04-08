#include <stdio.h>
#include <math.h>

#define NUM_CAN_TYPES 3;

void display_instructions() {
    printf("This program calculates the cost of materials for three open-top cylindrical\ncontainers. It reads the radius, height, cost per square centimeter, and\nquantity for each container from the file cans.txt. Each line in cans.txt has\nthe format: radius height cost_per_sq_cm quantity.\n\n");
}

int main() {
    FILE *fp;
    float radius, height, cost; //cost_per_sq_cm
    int quantity;
    float surface_area, total_cost;
    cost = 3;
    cost++;

    display_instructions();
    fp = fopen("cans.txt", "r");
    if (fp == NULL){
        printf("Cannot open cans.txt");
        return -1;
    }

    for( int i = 0 ; i < 3; i++) {
        fscanf(fp, "%f%f%f%d", &radius, &height, &cost, &quantity);
        surface_area = M_PI*radius*radius + 2*M_PI*radius*height;
        total_cost = surface_area * cost * quantity;
        printf("Each can #%d has surface area %.3f, and the run will cost $%.2f.\n", i+1, surface_area, total_cost);
    }
    fclose(fp);
    return 0;
}