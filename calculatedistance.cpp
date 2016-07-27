#include "calculatedistance.h"
#include <QtMath>


double   calculateDistance::getCalculateDistance(Dorf StartDorf, Dorf TargetDorf , double c )
{
    //not yet full tested
    //TODO write a unittest
    int dorf1_x, dorf1_y, dorf2_x, dorf2_y;
    int dorf1_x_new, dorf1_y_new, dorf2_x_new, dorf2_y_new;
//     dorf1_x = 488;
//     dorf1_y = 429;

//     dorf2_x = 487;
//     dorf2_y = 430;

    dorf1_x = StartDorf.getX();
    dorf1_y = StartDorf.getY();

    dorf2_x = TargetDorf.getX();
    dorf2_y = TargetDorf.getY();


     dorf1_y_new = dorf1_y ;
    if(dorf1_y % 2 == 0 )  dorf1_x_new = dorf1_x * 2;
     else dorf1_x_new = dorf1_x * 2 + 1;
    dorf2_y_new = dorf2_y ;
    if( dorf2_y %2 == 0 )dorf2_x_new = dorf2_x * 2;
     else dorf2_x_new = dorf2_x * 2 + 1;
    double x_abstand = abs(dorf1_x_new - dorf2_x_new);
    double y_abstand = abs(dorf1_y_new - dorf2_y_new );
    double y_coeff = sqrt(3./4);
    y_abstand *=  y_coeff;
    double x_coeff = 0.5;
    x_abstand *= x_coeff;
    //double c = 14;  //in minutes
    double abstand_in_min = c * sqrt( y_abstand*y_abstand + x_abstand * x_abstand );

    return abstand_in_min;
}
