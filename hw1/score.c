#include <stdio.h>

/*
 * This program calculates a grade student needs on the final to get their desired grade
 */

int main() {

    char desired_grade;
    float pct_current, pct_req, pct_needed, exam_weight;

    printf("Enter desired grade> ");
    scanf("%c", &desired_grade);
    printf("Enter minimum average required> ");
    scanf("%f", &pct_req);
    printf("Enter current average in course> ");
    scanf("%f", &pct_current);
    printf("Enter how much the final counts\n as a percent of the course grade> ");
    scanf("%f", &exam_weight);
    exam_weight *= .01; //convert percent to decimal

    pct_needed = (pct_req - pct_current*(1.0-exam_weight)) / exam_weight;

    printf("You need a score of %.2f on the final to get a %c\n", pct_needed, desired_grade);

    return 0;
}