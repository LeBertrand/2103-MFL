#include "Array.h"
Vector empty_vector(){
    Vector v;
    v.vector = (double*) malloc(sizeof(double));
    v.length = 1;
    v.count = 0;
    return v;
}