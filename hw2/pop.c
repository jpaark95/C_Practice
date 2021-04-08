#include <stdio.h>

#define P_0 52.966
#define T_0 1990
#define GR 2.184

int main() {
    FILE* fp = fopen("pop.txt", "w");
    int future_year;
    float future_pop;

    printf("Enter a year after 1990> ");
    scanf("%d", &future_year);

    future_pop = P_0 + GR * (future_year-T_0);
    fprintf(fp, "Predicted Gotham City population for %d (in thousands): %.3f\n", future_year, future_pop);

    return 0;
}