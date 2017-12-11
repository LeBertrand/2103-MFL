#include "Array.h"
Vector copy(Vector vec){
    Vector u = empty_vector();
    
    
    // case: empty vector or corrupted data
    if(vec.count && vec.vector != NULL){
        int index;
        for(index = 0; index < vec.length; index++){
            insert(&u, vec.vector[index]);
        }
    }
    return u;
}