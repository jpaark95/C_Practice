#include <stdio.h>

enum quadrant{X_AXIS, Y_AXIS, ORIGIN, I, II, III, IV};
int main() {
    
    float x_coord, y_coord;
    enum quadrant qd;

    printf("Please enter the x and y coordinates: ");
    scanf("%f%f", &x_coord, &y_coord);


    if (x_coord == 0){
        if (y_coord == 0)
            qd = ORIGIN;
        else
            qd = Y_AXIS;
    }else if (y_coord == 0){
        qd = X_AXIS;
    }else if (x_coord > 0){
        if (y_coord > 0)
            qd = I;
        else
            qd = IV;
    }else if (x_coord < 0){
        if ( y_coord > 0)
            qd = II;
        else
            qd = III;
    }

    switch(qd) {
        case I:
            printf("(%.1f, %.1f) is in quadrant I\n", x_coord, y_coord);
            break;
        case II:
            printf("(%.1f, %.1f) is in quadrant II\n", x_coord, y_coord);
            break;
        case III:
            printf("(%.1f, %.1f) is in quadrant III\n", x_coord, y_coord);
            break;
        case IV:
            printf("(%.1f, %.1f) is in quadrant IV\n", x_coord, y_coord);
            break;
        case X_AXIS:
            printf("(%.1f, %.1f) is on the x axis\n", x_coord, y_coord);
            break;
        case Y_AXIS:
            printf("(%.1f, %.1f) is on the y axis\n", x_coord, y_coord);
            break;
        case ORIGIN:
            printf("(%.1f, %.1f) is on the origin\n", x_coord, y_coord);
            break;
        
        default:
            printf("error\n");
            return(-1);
    }
    return 0;
}