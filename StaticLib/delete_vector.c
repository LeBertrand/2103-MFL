#include "Array.h"

void delete_vector(Vector *vec){
    if(vec->vector != NULL){
        free(vec->vector);
    }
    vec->count = vec->length = 0;
}