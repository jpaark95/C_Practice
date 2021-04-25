#include <stdio.h>
#include <math.h>

#define ARR_MAX 20

int get_corners(FILE *inp, double *arr_x, double *arr_y, int MAX_SIZE){
    double x, y;
    int sz;
    for (int i = 0; i < MAX_SIZE; i++){
        if (fscanf(inp, "%lf%lf", &x, &y) == EOF) {
            sz = i;
            break;
        }

        arr_x[i] = x;
        arr_y[i] = y;
    }

    return sz;
}

void output_corners(FILE *outfp, double *arr_x, double *arr_y, int arr_size){
    for (int i = 0; i < arr_size; i++){
        fprintf(outfp, "%.1lf %.1lf\n", arr_x[i], arr_y[i]);
    }
    return;
}

double polygon_area(double *arr_x, double* arr_y, int arr_size){
    double area = 0;
    for(int i = 0; i < arr_size-2; i++){
        area += (arr_x[i+1] + arr_x[i])*(arr_y[i+1] - arr_y[i]);
    }
    
    area = fabs(area) / 2.0;
    return area;
}
int main(int argc, char* argv[]) {
    FILE *infp = fopen(argv[1], "r");
    FILE *outfp = fopen(argv[2], "w");

    double arr_x[ARR_MAX], arr_y[ARR_MAX];
    double poly_area;
    int sz = 0;

    if (infp == NULL){
        printf("Error opening input file.\n");
        return -1;
    }

    if (outfp == NULL){
        printf("Error opening output file.\n");
        return -1;
    }

    sz = get_corners(infp, arr_x, arr_y, ARR_MAX);
    output_corners(outfp, arr_x, arr_y, sz);
    poly_area = polygon_area(arr_x, arr_y, sz);

    printf("The area is %.1lf\n", poly_area);

    fclose(infp);
    fclose(outfp);

    return 0;
}