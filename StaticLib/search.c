#include "Array.h"
int search(Vector vec, double dbl){
    int lower = 0;
    int upper = vec.count - 1;
    int mid = (upper + lower)/2;
    while(lower < upper){
        // searching too early.
        if(vec.vector[mid] < dbl){
            // retain second half of list
            lower = mid + 1;
        }
        // searching too late...retain first half of list
        else upper = mid;
        
        // find new middle of list
        mid = (upper + lower)/2;
    }
    if(vec.vector[mid] == dbl)
        return mid;
    else return -1;
}