#include <stdio.h>
#define REIMBURSEMENT_RATE 0.35

int main(){

    float odo_final, odo_initial, miles_traveled;
    float reimbursement;

    printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
    printf("Enter beginning odometer reading=> ");
    scanf("%f", &odo_initial);
    printf("Enter ending odometer reading=> ");
    scanf("%f", &odo_final);

    miles_traveled = odo_final - odo_initial;
    if (miles_traveled < 0){
        printf("Invalid input\n");
        return 0;
    }
    reimbursement = miles_traveled * REIMBURSEMENT_RATE;

    printf("You traveled %.1f miles. At $0.35 per mile,\nyour reimbursement is $%.2f\n",
                                                        miles_traveled, reimbursement);


    return 0;
}