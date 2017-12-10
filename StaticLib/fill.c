#include "Array.h"
void fill(Vector *vec, double dbl){
    int filled;
    for(filled = 0; filled < vec->count; filled++){
        vec->vector[filled] = dbl;
    }
}