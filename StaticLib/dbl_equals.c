#include "Array.h"
int dbl_equals(double d1, double d2){
    double dif = fabs(d1-d2);
    return dif < EPSILON;
}