#include "Array.h"
Vector sub(Vector v1, Vector v2){
    Vector in_place = copy(v2);
    // footprint, not efficiency
    int index;
    for(index = 0; index < in_place.count; index++){
        in_place.vector[index] *= (-1);
    }
    return add(in_place, v1);
    
}