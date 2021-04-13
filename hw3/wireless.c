#include <stdio.h>

#define FLAT_RATE 3999
#define WKDAY_MINS_AT_FLAT_RATE 600
#define ADDTL_MINS_RATE 40
#define TAX_RATE 0.0525
#define CENTS_PER_DOLLAR 100

int main() {
    int wkday_min, wkend_min, night_min, additional_min, total_min;
    float pretax_bill, total_bill, avg_price_per_min, tax;

    printf("Please enter the number of weekday minutes, night minutes: ");
    scanf("%d%d", &wkday_min, &night_min);
    printf("Please enter the number of weekend minutes: ");
    scanf("%d", &wkend_min);

    total_min = wkday_min + night_min + wkend_min;
    additional_min = wkday_min - WKDAY_MINS_AT_FLAT_RATE;
    pretax_bill = FLAT_RATE + (additional_min*ADDTL_MINS_RATE);
    avg_price_per_min = (int)((pretax_bill / total_min) + 0.5); 
    tax = (int)((pretax_bill*TAX_RATE) + 0.5);
    total_bill = pretax_bill + tax;
    
    printf("\nWeekday minutes: %d, night minutes: %d, weekend minutes: %d\n", wkday_min, night_min, wkend_min);
    printf("Average minute cost: $%.2f\n\n", avg_price_per_min / CENTS_PER_DOLLAR);
    printf("Pretax bill: $%6.2f\n", additional_min, pretax_bill/CENTS_PER_DOLLAR);
    printf("Taxes:       $%6.2f\n", tax/CENTS_PER_DOLLAR);
    printf("Total bill:  $%6.2f\n", total_bill/CENTS_PER_DOLLAR);
    
    return 0;
}