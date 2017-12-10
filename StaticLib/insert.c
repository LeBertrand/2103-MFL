#include "Array.h"
int insert(Vector *vec, double dbl){
    // Case: vector is full
    
    if(vec->count==vec->length){
        
        double *newVec = malloc(2*vec->length*sizeof(double));
        if(newVec == NULL){
            puts("Cannot allocate more memory to vector.");
            return 1;
        }
        
        vec->length *= 2;
        vec->vector = newVec;
        
    } // @post--vector has space after count
    //printf("Trying to put value no. %d, %lf into vector", vec->count,vec->vector[vec->count]);
    vec->vector[vec->count] = dbl;
    vec->count+=1;
    return 1;
}