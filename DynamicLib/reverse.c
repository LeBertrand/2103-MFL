#include "Array.h"
void reverse(Vector *vec){
    int i;
    for(i = 0; i < (vec->count) / 2; i++){
        swap(vec, i, vec->count - i - 1);
    }
}