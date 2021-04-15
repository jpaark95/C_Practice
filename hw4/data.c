#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int N;
    double temp, sum, smallest, largest, sum_sq, avg, sd;
    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){
        printf("problem opening file\n");
        return -1;
    }

    fscanf(fp, "%d", &N); //read in number of values in file
    fscanf(fp, "%lf", &temp);
    smallest = temp; //first pass
    largest = temp;
    sum = temp;
    sum_sq = pow(temp,2);

    for (int i=0; i<N-1; i++){
        fscanf(fp, "%lf", &temp);
        if (temp < smallest)
            smallest = temp;
        
        if (temp > largest)
            largest = temp;

        sum += temp;
        sum_sq += pow(temp,2);
    }

    avg = sum / (double)N;
    sd = sqrt((sum_sq / (double) N) - pow(avg,2));

    printf("Smallest:%7.2lf\nLargest: %7.2lf\nAverage: %7.2lf\nStandard deviation: %7.3lf\n", smallest, largest, avg, sd);

    fclose(fp);

    return 0;
}