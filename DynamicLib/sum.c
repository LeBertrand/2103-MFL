#include "Array.h"
double sum(Vector vec){
    int index;
    double running = 0;
    for(index = 0; index < vec.count; index++){
        running += vec.vector[index];
    }
    return running;
}