#include "Array.h"
void zeros(Vector *vec){
    int zeroed;
    for(zeroed = 0; zeroed < vec->count; zeroed++){
        vec->vector[zeroed] = 0.0;
    }
}