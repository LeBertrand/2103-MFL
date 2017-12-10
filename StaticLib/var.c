#include "Array.h"
double var(Vector vec){
    double mean = avg(vec);
    double running = 0;
    int index;
    for(index = 0; index < vec.count; index++){
        double dif = mean - vec.vector[index];
        running += (dif * dif)/(vec.count-1);
    }
    
    return running;
}