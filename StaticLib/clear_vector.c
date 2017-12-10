#include "Array.h"
void clear_vector(Vector *vec){
    int zeroed;
    for(zeroed = 0; zeroed < vec->count; zeroed++){
        vec->vector[zeroed] = 0.0;
    }
    vec->count = 0;
}