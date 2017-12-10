#include "Array.h"
Vector create_vector(int length){
    Vector v;
    v.vector = malloc(sizeof(double) * length);
    // check for null 
    if(v.vector == NULL){
        puts("Can't allocate memory for pointer. Exit program.");
        exit(1);
    }
    v.length = length;
    v.count = 0;
    return v;
}