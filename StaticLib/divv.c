#include "Array.h"
Vector divv(Vector v1, Vector v2){
    if(v1.count != v2.count){
        puts("Cannot multiply vectors of differing length.");
        return empty_vector();
    }
    Vector quotient = empty_vector();
    int index;
    for(index = 0; index < v1.count; index++){
        insert(&quotient, v1.vector[index] / v2.vector[index]);
    }
    
    return quotient;
}