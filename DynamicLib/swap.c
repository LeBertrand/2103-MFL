#include "Array.h"
void swap(Vector *vec, int i, int j){
    int x = vec->vector[i];
    vec->vector[i] = vec->vector[j];
    vec->vector[j] = x;
}