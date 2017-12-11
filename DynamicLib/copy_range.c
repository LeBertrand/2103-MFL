#include "Array.h"
Vector copy_range(Vector vec, int from, int to){
    Vector u = empty_vector();
    // catch some errors
    if(to<from || from < 0 || from >= vec.count){
        printf("Bad copy-range call. From: %d, To: %d\n", from, to);
        return u;
    }
    // iterate starting at 'from' index ending at 'to', and insert
    for(;from <= to; from++){
        insert(&u,vec.vector[from]);
    }
    return u;
}