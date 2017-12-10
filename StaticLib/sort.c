#include "Array.h"
void sort(Vector *vec){
    int n, going = 1;
    while(going){
        going = 0;
        for(n = 1; n < vec->count; n++){
            if(vec->vector[n] < vec->vector[n - 1]){
                swap(vec, n, n - 1);
                going = 1;
            }
        }
    }
}