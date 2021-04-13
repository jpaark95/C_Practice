#include <stdio.h>

enum emission_t {CO, CHx, NOx, NMHC};
void display_table() {
    printf(" (1) Carbon monoxide\n");
    printf(" (2) Hydrocarbons\n");
    printf(" (3) Nitrogen oxides\n");
    printf(" (4) Nonmethane hydrocarbons\n");
}
int main() {
    int odo, flag_passed;
    float emission_rate, permitted_emission_rate;
    enum emission_t emission_type;

    display_table();
    printf("Enter pollutant number>> ");
    scanf("%u", &emission_type);
    emission_type--;
    printf("Enter number of grams emitted per mile>> ");
    scanf("%f", &emission_rate);
    printf("Enter odometer reading>> ");
    scanf("%d", &odo);
    
    switch(emission_type){
        case CO:
            if (odo < 50000) { //first 50,000 miles
                permitted_emission_rate = 3.4;
                if (emission_rate <= permitted_emission_rate)
                    flag_passed = 1;
                else
                    flag_passed = -1;
            } else { //second 50,000 miles
                permitted_emission_rate = 4.2;
                if (emission_rate <= permitted_emission_rate)
                    flag_passed = 1;
                else
                    flag_passed = -1;
            }
            break;
        case CHx:
            if (odo < 50000) { //first 50,000 miles
                permitted_emission_rate = 3.1;
                if (emission_rate <= permitted_emission_rate)
                    flag_passed = 1;
                else
                    flag_passed = -1;
            } else { //second 50,000 miles
                permitted_emission_rate = 0.39;
                if (emission_rate <= permitted_emission_rate)
                    flag_passed = 1;
                else
                    flag_passed = -1;
            }
            break;
        case NOx:
            if (odo < 50000) { //first 50,000 miles
                permitted_emission_rate =  0.4;
                if (emission_rate <= permitted_emission_rate)
                    flag_passed = 1;
                else
                    flag_passed = -1;
            } else { //second 50,000 miles
                permitted_emission_rate = 0.5;
                if (emission_rate <= permitted_emission_rate)
                    flag_passed = 1;
                else
                    flag_passed = -1;
            }
            break;
        case NMHC:
            if (odo < 50000) { //first 50,000 miles
                permitted_emission_rate = 0.25;
                if (emission_rate <= permitted_emission_rate)
                    flag_passed = 1;
                else
                    flag_passed = -1;
            } else { //second 50,000 miles
                permitted_emission_rate = 0.31;
                if (emission_rate <= permitted_emission_rate)
                    flag_passed = 1;
                else
                    flag_passed = -1;
            }
            break;
    }
    if (flag_passed)
        printf("Emissions do not exceed permitted level of %.2f grams/mile.\n", permitted_emission_rate);
    else
        printf("Emissions exceed permitted level of %.2f grams/mile.\n", permitted_emission_rate);
    return 0;
}