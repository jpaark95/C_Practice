#include <stdio.h>

void display_instructions() {
    printf("This program determines the total cost of owning a home for five years.\nThe user will enter initial cost in whole dollars, annual fuel costs in\nwhole dollars, and the annual tax rate as a real number.\n\n");
}
int main() {
    int cost_house, cost_fuel;
    float tax_rate, cost_total;

    display_instructions();
    printf("Please enter the initial cost, fuel cost, and tax rate: ");
    scanf("%d%d%f", &cost_house, &cost_fuel, &tax_rate);

    cost_total = cost_house + cost_fuel*5 + cost_house*tax_rate*5; 
    printf("The total cost is %.2f\n", cost_total);

    return 0;
}