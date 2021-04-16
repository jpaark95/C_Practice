#include <stdio.h>
#include <math.h>

float get_problem(){
    int problem_number;
    printf("Select the form that you would like to convert to slope-intercept form:\n");
    printf("1) Two-point form (you know two points on the line)\n");
    printf("2) Point-slope form (you know the line's slope and one point\n");
    printf("=> ");
    scanf("%d", &problem_number);
    printf("\n");
    return problem_number;
}

void get2_pt(float* x1, float* y1, float* x2, float* y2){
    printf("Enter the x-y coordinates of the first point separated by a space=> ");
    scanf("%f%f", x1, y1);
    printf("Enter the x-y coordiantes of the second point separated by a space=> ");
    scanf("%f%f", x2, y2);
    printf("\n");
    return;
}
void get_pt_slope( float *x, float *y, float *m){
    printf("Enter the slope=> ");
    scanf("%f", m);
    printf("Enter the x-y coordinates of the point separated by a space=> ");
    scanf("%f%f", x, y);
    printf("\n");
    return;
}

void slope_intcpt_from2_pt (float x1, float y1, float x2, float y2, float *m, float *b) {
    *m = (y2 - y1)/(x2 - x1);
    *b = y1 - (*m * x1);
    return;
}

float intcp_from_pt_slope(float x, float y, float m){
    float b = y - m*x;
    return b;
}

void display2_pt(float x1, float y1, float x2, float y2){
    //m = (y2 -y1) / (x2 - x1)
    char sign1, sign2;
    printf("Two-point form:\n");
    if (y1 < 0){
        y1 *= -1.0;
        sign1 = '+';
    } else {
        sign1 = '-';
    }
    if (x1 < 0){
        x1 *= -1.0;
        sign2 = '+';
    } else {
        sign2 = '-';
    }
    
    printf("    (%.2f %c %.2f)\n", y2, sign1, y1);
    printf("m = ------------------\n");
    printf("    (%.2f %c %.2f)\n\n", x2, sign2, x1);
    return;
}

void display_pt_slope(float x, float y, float m) {
    // y - y1 = m(x - x1);
    char sign;
    if (x < 0) {
        x *= -1.0;
        sign = '+';
    } else {
        sign = '-';
    }

    printf("Point-slope form:\n");
    printf("   y - %.2f = %.2f(x %c %.2f)\n\n", y, m, sign, x);    
    return;
}
void display_slope_intcpt(float m, float b){
    // y = mx + b
    char sign;
    if (b < 0) {
        b *= -1.0;
        sign = '-';
    } else {
        sign = '+';
    }
    printf("Slope-intercept form:\n");
    printf("   y = %.2fx %c %.2f\n\n", m, sign, b);
    return;
}
int main() {
    float x1, y1, x2, y2, m, b;
    char again;
    int problem_number;
    do {
        problem_number = get_problem();
        if (problem_number == 1){
            get2_pt(&x1, &y1, &x2, &y2);
            slope_intcpt_from2_pt(x1, y1, x2, y2, &m, &b);
            display2_pt(x1, y1, x2, y2);
            display_slope_intcpt(m, b);
        } else { 
            get_pt_slope(&x1, &y1, &m);
            b = intcp_from_pt_slope(x1, y1, m);
            display_pt_slope(x1, y1, m);
            display_slope_intcpt(m, b);
        }
        
        printf("Do another conversion (Y or N) =>");
        scanf(" %c", &again);
        printf("\n");
    } while (again == 'Y' || again == 'y');
    return 0;
}