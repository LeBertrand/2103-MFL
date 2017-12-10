#include "Array.h"
double avg(Vector vec){
    double mean = sum(vec); // this is about footprint, not run-time
    mean /= vec.count;
    return mean;
}