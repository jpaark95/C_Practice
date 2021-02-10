#include <stdio.h>
#include <math.h>

/*
 * This program calculates the acceleration in m/s^2  a jet fighter launched from an aircraft-carrier catapult
 * takes, given the takeoff speed in km/hr and distance in meteres over which the catapult accelerates the jet from
 * rest to takeoff.
 * 
 * (1) v = at (where v is velocity, a is acceleration, t is time)
 * (2) s = 1/2 * at^2 (where s is distance, a is acceleration, t is time)
 * 
 * we can rewrite (2) as
 * s = 1/2 * a * t * t (3)
 * then, substituting v for a * t (1), we get:
 * s = 1/2 v * t (4)
 * solving for t we get:
 * t = 2s / v
 * 
 */

int main() {
    float v, s;
    float t, a;

    printf("Please enter the takeoff speed of the jet in km/hr > ");
    scanf("%f", &v); //km/hr
    printf("Please enter the catapult distance in meters > ");
    scanf("%f", &s); //m
    
    v *= (float)5/(float)18; //convert velocity to m/s
    t = 2*s / v;
    a = v*v / (2*s);
    

    printf("The jet would accelerate at %.2f m/s^2 for %.2f seconds.\n", a, t);
    return 0;
}